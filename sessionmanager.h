#ifndef SESSIONMANAGER_H
#define SESSIONMANAGER_H

#include <QString>
#include <QDebug>
#include <QTextStream>
#include <QFile>

class SessionManager {
public:
    static SessionManager& instance() {
        static SessionManager instance;
        return instance;
    }
    void saveUserIdToFile(QString userId);

    // Function to load userId from a file
    void loadUserIdFromFile();

    QString getUserId() const;
    QString getFriendId() const;
    void setUserId(QString id);
    void setFriendId(QString id);
private:
    SessionManager() {}
    QString userId;
    QString friendId;
};

#endif // SESSIONMANAGER_H
