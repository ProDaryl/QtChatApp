#ifndef GROUPCHATWINDOW_H
#define GROUPCHATWINDOW_H

#include <QMainWindow>
#include <QSql>
#include <QLabel>
#include <QFileDialog>

#include "message.h"
#include "databasemanager.h"
#include "qlistwidget.h"
#include "sessionmanager.h"

namespace Ui {
class GroupChatWindow;
}

class GroupChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit GroupChatWindow(QWidget *parent = nullptr);
    bool sendMessageToGroupChat(QString userId, QString messageText, QByteArray messageImage);
    void displayMessageToGroup(Message message);
    void loadGroupChatMessages();
    ~GroupChatWindow();

private slots:
    void on_pushButton_addImage_clicked();

    void on_pushButton_send_clicked();

private:
    Ui::GroupChatWindow *ui;

    QListWidget *messageslist;
};

#endif // GROUPCHATWINDOW_H
