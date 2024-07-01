#include "chatwidget.h"
#include "ui_chatwidget.h"

ChatWidget::ChatWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::ChatWidget)
{
    ui->setupUi(this);
    loadChatMessages();
}


void ChatWidget::loadChatMessages() {
    QString userId = SessionManager::instance().getUserId();
    QString friendId = SessionManager::instance().getFriendId();

    if (userId.isEmpty() || friendId.isEmpty()) {
        qDebug() << "User ID or Friend ID is empty. Cannot load messages.";
        return;
    }

    QList<int> conversationIds = DatabaseManager::database().getConversationIdsForUserWithFriend(userId, friendId);

    ui->listWidget_chats->clear();

    for (int conversationId : conversationIds) {
        QList<Message> messages = DatabaseManager::database().getMessagesForConversation(conversationId, userId, friendId);
        for (const auto& message : messages) {
            displayMessage(message);
        }
    }
}

void ChatWidget::displayMessage(Message message) {
    QString senderName = DatabaseManager::database().getUsernamefromId(message.getSenderId());
    QString messageText = message.getText();
    QString displayText = senderName + ": " + messageText;

    QListWidgetItem* listItem = new QListWidgetItem();

    // Create a custom widget for the list item
    QWidget* itemWidget = new QWidget();

    // Create a layout for the custom widget
    QHBoxLayout* layout = new QHBoxLayout(itemWidget);

    QLabel* textLabel = new QLabel(displayText);
    layout->addWidget(textLabel);

    if (!message.getImage().isEmpty()) {
        QPixmap pixmap;
        pixmap.loadFromData(message.getImage());
        pixmap = pixmap.scaled(64, 64, Qt::KeepAspectRatio);
        QLabel* imageLabel = new QLabel();
        imageLabel->setPixmap(pixmap);
        layout->addWidget(imageLabel);
    }

    // Set the custom widget as the list item widget
    listItem->setSizeHint(itemWidget->sizeHint());
    ui->listWidget_chats->addItem(listItem);
    ui->listWidget_chats->setItemWidget(listItem, itemWidget);

}

void ChatWidget::on_pushButton_send_clicked() {
    QString messageText = ui->lineEdit_message->text();
    QString senderId = SessionManager::instance().getUserId();
    QString friendId = SessionManager::instance().getFriendId();

    if (!friendId.isEmpty()) {
        QByteArray messageImage;

        if (!messageText.trimmed().isEmpty() && DatabaseManager::database().sendMessage(senderId, friendId, messageText, messageImage)) {
            Message message;
            message.setSenderId(senderId);
            message.setText(messageText);
            message.setImage(messageImage);

            displayMessage(message);
            ui->lineEdit_message->clear();
        } else {
            qDebug() << "Failed to send message.";
        }
    } else {
        qDebug() << "Failed to send message: Unable to determine the friend ID.";
    }
}


void ChatWidget::on_pushButton_addImage_clicked() {
    QString userId = SessionManager::instance().getUserId();
    QString friendId = SessionManager::instance().getFriendId();
    QString filter = "Images (*.png *.jpg *.jpeg *.bmp *.gif)";
    QString fileName = QFileDialog::getOpenFileName(this, "Add an image", QDir::homePath(), filter);

    if (!fileName.isEmpty()) {
        QByteArray imageData;
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            imageData = file.readAll();
            file.close();
        }

        if (!imageData.isEmpty() && DatabaseManager::database().sendMessage(userId, friendId, QString(), imageData)) {
            Message message;
            message.setSenderId(userId);
            message.setText("");
            message.setImage(imageData);

            displayMessage(message);
        } else {
            qDebug() << "Failed to send image.";
        }
    }
}

ChatWidget::~ChatWidget()
{
    delete ui;
}
