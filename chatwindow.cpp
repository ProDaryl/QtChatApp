#include "chatwindow.h"
#include "messagewidget.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    loadChatMessages();
}


void ChatWindow::loadChatMessages() {
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

void ChatWindow::displayMessage(Message message) {       
    QString senderName = DatabaseManager::database().getUsernamefromId(message.getSenderId());
    QString messageText = message.getText();
    QByteArray imageData = message.getImage();

    QListWidgetItem *listItem = new QListWidgetItem(ui->listWidget_chats);
    MessageWidget *itemWidget = new MessageWidget(senderName, messageText, imageData);

    listItem->setSizeHint(itemWidget->sizeHint());
    ui->listWidget_chats->addItem(listItem);
    ui->listWidget_chats->setItemWidget(listItem, itemWidget);

}

void ChatWindow::on_pushButton_send_clicked() {
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


void ChatWindow::on_pushButton_addImage_clicked() {
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

ChatWindow::~ChatWindow()
{
    delete ui;
}




