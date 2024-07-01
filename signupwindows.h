#ifndef SIGNUPWINDOWS_H
#define SIGNUPWINDOWS_H

#include <QMainWindow>
#include <QMessageBox>
#include <QUuid>
#include <QtNetwork>

QT_BEGIN_NAMESPACE
namespace Ui {
class SignUpWindows;
}
QT_END_NAMESPACE

class SignUpWindows : public QMainWindow
{
    Q_OBJECT

public:
    SignUpWindows(QWidget *parent = nullptr);
    bool addUser(QString &, QString &, QString &, QString &);
    ~SignUpWindows();

private slots:
    void on_pushButton_login_clicked();

    void on_pushButton_Quit_clicked();

    void on_pushButton_SignUp_clicked();

private:
    Ui::SignUpWindows *ui;
    bool sendEmailNotification(QString &, QString &, QString &);
    QString hashPassword(QString &);
    QString createUsername(QString );
    QString currentUserId;
};
#endif // SIGNUPWINDOWS_H
