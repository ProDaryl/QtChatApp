// chatwindow.h
#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QFileDialog>

#include "databasemanager.h"
#include "message.h"
#include "sessionmanager.h"

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);
    ~ChatWindow();

private slots:
    void on_pushButton_send_clicked();
    void on_pushButton_addImage_clicked();

private:
    Ui::ChatWindow *ui;
    void displayMessage(Message message);

    void loadChatMessages();
};

#endif // CHATWINDOW_H
