#include "sessionmanager.h"

void SessionManager::saveUserIdToFile(QString userId) {
    QFile file("CurrentUser.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << file.errorString();
        return;
    }
    QTextStream out(&file);
    out << userId;
    file.close();
}

void SessionManager::loadUserIdFromFile() {
    QFile file("CurrentUser.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString id = in.readAll();
        file.close();
        userId = id.trimmed();
        qDebug() << "Loaded user ID:" << userId;
    } else {
        qDebug() << "Failed to open file for reading:" << file.errorString();
    }
}

QString SessionManager::getUserId() const {
    return userId;
}

void SessionManager::setUserId(QString id) {
    userId = id;
    saveUserIdToFile(id);
}

QString SessionManager::getFriendId() const {
    return friendId;
}

void SessionManager::setFriendId(QString id) {
    friendId = id;
}
