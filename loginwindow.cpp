#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "signupwindows.h"
#include "mainwindow.h"


LoginWindow::LoginWindow(QString &userId, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow), currentUserId(userId)
{
    ui->setupUi(this);
    QHBoxLayout *layout = qobject_cast<QHBoxLayout*>(ui->horizontalLayout_4);
    if(layout) {
        layout->setStretch(0, 1);
        layout->setStretch(1, 2);
        layout->setStretch(2, 1);
    }
    QPixmap original_logo(":/resources/Images/ICTULogo.png");


    QSize newSize(100, 100);
    QPixmap logo = original_logo.scaled(newSize, Qt::KeepAspectRatio);
    ui->label_logo->setPixmap(logo);
    statusBar()->addPermanentWidget(ui->label_developer);
    SessionManager::instance().setUserId(userId);
}

QString LoginWindow::hashPassword(QString &password)
{
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

bool LoginWindow::checkLogin(QString &username, QString &password)
{
    QSqlDatabase db = QSqlDatabase::database();

    if(!db.isValid()) {
        qDebug() << "Error. No valid database connection.";
        return false;
    }
    QString hashedPassword = hashPassword(password);

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Query failed:" << query.lastError().text();
        return false;
    }

    if (query.next()) {
        QString storedPassword = query.value(0).toString();
        // Compare the stored password with the provided password
        if (storedPassword == hashedPassword) {
            qDebug() << "Login successful!";
            return true;
        } else {
            qDebug() << "Incorrect password!";
            return false;
        }
    } else {
        qDebug() << "Username not found!";
        return false;
    }
}


LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_sigUp_clicked()
{
    ui->pushButton_sigUp->setStyleSheet("Qlabel{color: green; text-decoration: underline}");
    this->close();
    SignUpWindows *signupwindow = new SignUpWindows(this);
    signupwindow->show();
}


void LoginWindow::on_pushButton_quit_clicked()
{
    this->close();
}


void LoginWindow::on_pushButton_login_clicked()
{
    QString username = ui->lineEdit_username->text().trimmed();
    QString password = ui->lineEdit_password->text().trimmed();
    if(checkLogin(username, password)) {
        this->close();
        QString newUserId = DatabaseManager::database().getUserIdFromName(username);
        SessionManager::instance().setUserId(newUserId);
        MainWindow *mainwindow = new MainWindow(this);
        mainwindow->show();
        return;
    }
    QMessageBox::warning(this, "Error", "Username and password incorrect");
}

