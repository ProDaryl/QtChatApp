#ifndef USERCREDENTIALSMANAGER_H
#define USERCREDENTIALSMANAGER_H

#include "QObject"
#include <QString>
#include <QUuid>
#include <QCryptographicHash>
#include <QMessageBox>


class UserCredentialsManager {
public:
    UserCredentialsManager(QString &, QString& , QString &, QString& );

    QString getUsername() const;
    QString getEmail() const;
    QString getPassword() const;
    QString getUserId() const;
private:
    QString m_userid;
    QString m_username;
    QString m_password;
    QString m_email;
    QByteArray profile_pic;
};


#endif // USERCREDENTIALSMANAGER_H
