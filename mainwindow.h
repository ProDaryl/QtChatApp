#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qstackedwidget.h"
#include "sessionmanager.h"
#include "databasemanager.h"
#include "chatwindow.h"
#include "groupchatwindow.h"

#include <QMainWindow>
#include <QtSql>
#include <QListWidget>
#include <QMessageBox>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void loadProfilePicture();

    bool hasExistingMessages();

    void friendList(QListWidget *listWidget);

    ~MainWindow();

    bool addFriend(QString , QString );
    QStringList searchFriendById(QString );
    QByteArray loadImageDataFromResource(QString );
private slots:
    void on_pushButton_newchat_clicked();

    void on_pushButton_addfriend_clicked();

    void on_pushButton_addPic_clicked();

    void on_listWidget_chats_itemClicked(QListWidgetItem *item);


    void on_pushButton_groupchat_clicked();

private:
    Ui::MainWindow *ui;

    void insertProfilePicture(QString userId, QByteArray imageData);

    QListWidget *friendlistWidget;

    QListWidget *chatslistWidget;

    QStackedWidget *stackedWidget;



    QString friendId;
};

#endif // MAINWINDOW_H
