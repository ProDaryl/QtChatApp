#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <QtSql>
#include <QDebug>

#include "message.h"

class DatabaseManager
{
private:
    DatabaseManager();
    QSqlDatabase db = QSqlDatabase::database();
public:

    static DatabaseManager& database() {
        static DatabaseManager database;
        return database;
    }

    QList<Message> getGroupChatMessages();

    QByteArray getProfilePicture(QString userId);

    bool addUserToGroupChat(QString userId);
    QString hashPassword(QString );
    bool sendMessage(QString , QString ,  QString ,  QByteArray );
    QString getFriendIdFromDatabase(QString );

    bool initializeDatabase();
    QString getUsernamefromId(QString );

    void displayUsers();
    QList<Message> getMessagesForConversation(int , QString , QString );
    QList<int> getConversationIdsForUserWithFriend(QString , QString);
    QString getUserIdFromName(QString username);

    ~DatabaseManager();
};

#endif // DATABASEMANAGER_H
