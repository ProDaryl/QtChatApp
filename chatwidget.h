#ifndef CHATWIDGET_H
#define CHATWIDGET_H

#include <QWidget>
#include <QByteArray>
#include <QDebug>
#include <QFileDialog>
#include <QListWidget>
#include <QLabel>
#include <QMessageBox>

#include "databasemanager.h"
#include "sessionmanager.h"
#include "message.h"


namespace Ui {
class ChatWidget;
}

class ChatWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWidget(QWidget *parent = nullptr);
    void displayMessage(Message message);
    void loadChatMessages();
    ~ChatWidget();

private slots:
    void on_pushButton_send_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_addImage_clicked();

private:
    Ui::ChatWidget *ui;
};

#endif // CHATWIDGET_H
