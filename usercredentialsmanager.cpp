#include "usercredentialsmanager.h"

UserCredentialsManager::UserCredentialsManager(QString &userid, QString &username, QString &password, QString &email): m_userid(userid), m_username(username), m_password(password), m_email(email) {}

QString UserCredentialsManager::getUsername() const
{
    return m_username;
}

QString UserCredentialsManager::getEmail() const {
    return m_email;
}

QString UserCredentialsManager::getUserId() const {
    return m_userid;
}

