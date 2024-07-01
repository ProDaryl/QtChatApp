#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>

#include "sessionmanager.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QString &, QWidget *parent = nullptr);
    bool checkLogin(QString &, QString &);

    ~LoginWindow();

private slots:
    void on_pushButton_sigUp_clicked();

    void on_pushButton_quit_clicked();

    void on_pushButton_login_clicked();

private:
    Ui::LoginWindow *ui;

    QString hashPassword(QString &);

    QString currentUserId;
};

#endif // LOGINWINDOW_H
