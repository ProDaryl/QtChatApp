#include "signupwindows.h"
#include "ui_signupwindows.h"
#include "loginwindow.h"
#include "mainwindow.h"
#include "sessionmanager.h"


SignUpWindows::SignUpWindows(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SignUpWindows)
{
    ui->setupUi(this);
    QHBoxLayout *layout = qobject_cast<QHBoxLayout*>(ui->horizontalLayout_4);
    if(layout) {
        layout->setStretch(0, 1);
        layout->setStretch(1, 2);
        layout->setStretch(2, 1);
    }
    statusBar()->addPermanentWidget(ui->label_developer);
    QPixmap original_logo(":/resources/Images/ICTULogo.png");
    QSize newSize(100, 100);
    QPixmap logo = original_logo.scaled(newSize, Qt::KeepAspectRatio);
    ui->label_logo->setPixmap(logo);
}

bool SignUpWindows::addUser(QString &id, QString &username, QString &password, QString &email)
{
    QSqlDatabase db = QSqlDatabase::database();

    if(!db.isValid()) {
        qDebug() << "Error. No valid database connection.";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO Users(id, username, password, email) VALUES(:id, :username, :password, :email)");
    query.bindValue(":id", id);
    query.bindValue(":username", username);
    query.bindValue(":password", hashPassword(password));
    query.bindValue(":email", email);

    if(!query.exec()) {
        qDebug() <<"Error. Failed to insert user:" << query.lastError().text();
        return false;
    }
    return true;
}

QString SignUpWindows::hashPassword(QString &password)
{
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}


QString SignUpWindows::createUsername(QString fullname)
{
    QStringList nameParts = fullname.split(" ", Qt::SkipEmptyParts);
    if(nameParts.size() < 2) {
        QMessageBox::warning(this, "Warning", "Full name must contain a first name and a last name.");
        return "";
    }
    QString firstName = nameParts.first();
    QString lastName = nameParts.last();

    QString username = firstName.toLower() + lastName.toLower();
    return username;
}


bool SignUpWindows::sendEmailNotification(QString &recipientName, QString &recipientEmail, QString &userId)
{

    QString smtpServer = "smtp.gmail.com";
    int port = 587;
    QString username = "ejohdaryl@gmail.com";
    QString password = "pkqa iroc rfof sxdp";

    QSslSocket socket;
    socket.connectToHost(smtpServer, port);
    if (!socket.waitForConnected(30000)) {
        qDebug() << "Failed to connect to server";
        return false;
    }

    socket.waitForReadyRead();
    qDebug() << socket.readAll();

    auto sendCommand = [&](const QString &command) -> bool {
        socket.write(command.toUtf8() + "\r\n");
        socket.flush();
        if (!socket.waitForReadyRead()) {
            qDebug() << "Failed to get response from server for command:" << command;
            return false;
        }
        qDebug() << socket.readAll();
        return true;
    };

    if (!sendCommand("EHLO gmail.com") ||
        !sendCommand("STARTTLS")) {
        return false;
    }

    socket.startClientEncryption();
    if (!socket.waitForEncrypted(30000)) {
        qDebug() << "Failed to establish TLS";
        return false;
    }

    if (!sendCommand("EHLO example.com") ||
        !sendCommand("AUTH LOGIN") ||
        !sendCommand(QString(QByteArray(username.toUtf8()).toBase64())) ||
        !sendCommand(QString(QByteArray(password.toUtf8()).toBase64()))) {
        return false;
    }

    if (!sendCommand("MAIL FROM:<" + username + ">") ||
        !sendCommand("RCPT TO:<" + recipientEmail + ">") ||
        !sendCommand("DATA")) {
        return false;
    }

    // Email content
    QString emailContent = "Subject: Account created\r\n\r\nHello " + recipientName + ",\nYour unique id is:  " + userId + "\nPlease keep it safe.\r\n.\r\n";
    if (!sendCommand(emailContent)) {
        return false;
    }

    if (!sendCommand("QUIT")) {
        return false;
    }

    socket.close();
    return true;
}


SignUpWindows::~SignUpWindows()
{
    delete ui;
}




void SignUpWindows::on_pushButton_login_clicked()
{
    ui->pushButton_SignUp->setStyleSheet("Qlabel{color: green; text-decoration: underline}");
    this->close();
    LoginWindow *loginwindow = new LoginWindow(currentUserId, this);
    loginwindow->show();
}


void SignUpWindows::on_pushButton_Quit_clicked()
{
    this->close();
}


void SignUpWindows::on_pushButton_SignUp_clicked()
{
    QString username = createUsername(ui->lineEdit_FullName->text().trimmed());
    QString password = ui->lineEdit_Password->text().trimmed();
    QString email = ui->lineEdit_email->text().trimmed();
    QString confirmPassword = ui->lineEdit_ConfirmPass->text().trimmed();

    if(username.isEmpty() || password.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Invalid input", "One or more of the fields is empty");
        return;
    }

    if(password != confirmPassword) {
        QMessageBox::warning(this, "Error", "Passwords do not match");
        return;
    }

    QString uniqueId = QUuid::createUuid().toString();
    currentUserId = uniqueId;
    if(addUser(uniqueId, username, password, email)) {
        if(sendEmailNotification(username, email, uniqueId)) {
            SessionManager::instance().setUserId(uniqueId);
            DatabaseManager::database().addUserToGroupChat(uniqueId);
            QMessageBox::information(this, "Qt ChatApp Account created", "Account created successfully! Check your email.");
            this->hide();
            MainWindow *mainwindow = new MainWindow(this);
            mainwindow->show();
        } else {
            QMessageBox::warning(this, "Email Notification Failed", "Failed to send email notification.");
         }
    } else {
        QMessageBox::critical(this, "Database Error", "Failed to add user to the database.");
    }
}


