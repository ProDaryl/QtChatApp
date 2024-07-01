#include "groupchatwindow.h"
#include "ui_groupchatwindow.h"
#include "messagewidget.h"

GroupChatWindow::GroupChatWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GroupChatWindow)
{
    ui->setupUi(this);
    loadGroupChatMessages();
}

void GroupChatWindow::loadGroupChatMessages() {
    QSqlQuery query;
    query.prepare("SELECT sender_id, message_text, message_image FROM Conversations ORDER BY timestamp DESC");

    if (!query.exec()) {
        qDebug() << "Failed to fetch group chat messages:" << query.lastError().text();
        return;
    }

    ui->listWidget_chats->clear(); // Clear existing messages

    while (query.next()) {
        QString senderId = query.value(0).toString();
        QString messageText = query.value(1).toString();
        QByteArray messageImage = query.value(2).toByteArray();

        Message message(senderId, messageText, messageImage);
        displayMessageToGroup(message);
    }
}

bool GroupChatWindow::sendMessageToGroupChat(QString userId, QString messageText, QByteArray messageImage) {
    if (userId.isEmpty() || (messageText.trimmed().isEmpty() && messageImage.isEmpty())) {
        qDebug() << "Invalid parameters for sending message.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Conversations (sender_id, message_text, message_image) VALUES (?, ?, ?)");
    query.addBindValue(userId);
    query.addBindValue(messageText);
    query.addBindValue(messageImage);

    if (!query.exec()) {
        qDebug() << "Failed to send message to group chat:" << query.lastError().text();
        return false;
    }

    displayMessageToGroup(Message(userId, messageText, messageImage));
    return true;
}

void GroupChatWindow::displayMessageToGroup(Message message) {
    QString senderName = DatabaseManager::database().getUsernamefromId(message.getSenderId());
    QString messageText = message.getText();
    QByteArray imageData = message.getImage();

    QListWidgetItem *listItem = new QListWidgetItem(ui->listWidget_chats);
    MessageWidget *itemWidget = new MessageWidget(senderName, messageText, imageData);

    listItem->setSizeHint(itemWidget->sizeHint());
    ui->listWidget_chats->addItem(listItem);
    ui->listWidget_chats->setItemWidget(listItem, itemWidget);
}



void GroupChatWindow::on_pushButton_addImage_clicked()
{
    QString userId = SessionManager::instance().getUserId();
    QString filter = "Images (*.png *.jpg *.jpeg *.bmp *.gif)";
    QString fileName = QFileDialog::getOpenFileName(this, "Add an image", QDir::homePath(), filter);

    if (!fileName.isEmpty()) {
        QByteArray imageData;
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly)) {
            imageData = file.readAll();
            file.close();
        }

        if (!imageData.isEmpty() && sendMessageToGroupChat(userId, QString(), imageData)) {
            Message message;
            message.setSenderId(userId);
            message.setText("");
            message.setImage(imageData);

            displayMessageToGroup(message);
        } else {
            qDebug() << "Failed to send image.";
        }
    }
}


void GroupChatWindow::on_pushButton_send_clicked()
{
    QString userId = SessionManager::instance().getUserId();
    Message message;
    message.setSenderId(userId);
    message.setText(ui->lineEdit_message->text().trimmed());
    sendMessageToGroupChat(userId, message.getText(), QByteArray());
    ui->lineEdit_message->clear();
}

GroupChatWindow::~GroupChatWindow() {}

