#include "databasemanager.h"

DatabaseManager::DatabaseManager() {}

bool DatabaseManager::sendMessage(QString senderId, QString receiverId, QString messageText, QByteArray messageImage) {
    // Validate sender ID and message text
    if (senderId.isEmpty() && messageText.trimmed().isEmpty()) {
        qDebug() << "Invalid sender ID or empty message text.";
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO Messages (sender_id, receiver_id, message_text, message_image) VALUES (?, ?, ?, ?)");
    query.addBindValue(senderId);
    query.addBindValue(receiverId);
    query.addBindValue(messageText);
    query.addBindValue(messageImage); // Ensure messageImage is a QByteArray

    if (!query.exec()) {
        qDebug() << "Failed to send message:" << query.lastError().text();
        return false;
    }

    return true;
}


bool DatabaseManager::addUserToGroupChat(QString userId) {
    QSqlQuery query;
    query.prepare("INSERT INTO Conversation_members (user_id) VALUES (?)");
    query.addBindValue(userId);

    if (!query.exec()) {
        qDebug() << "Failed to add user to group chat:" << query.lastError().text();
        return false;
    }

    return true;
}


QList<Message> DatabaseManager::getGroupChatMessages() {
    QList<Message> messages;
    QSqlQuery query;
    query.prepare("SELECT sender_id, message_text, message_image FROM Conversations"); // Retrieve messages for the main group chat (chat_id 1)

    if (!query.exec()) {
        qDebug() << "Failed to retrieve group chat messages:" << query.lastError().text();
        return messages;
    }

    while (query.next()) {
        Message message;
        message.setSenderId(query.value("sender_id").toString());
        message.setText(query.value("message_text").toString());
        message.setImage(query.value("message_image").toByteArray());
        messages.append(message);
    }

    return messages;
}


QList<int> DatabaseManager::getConversationIdsForUserWithFriend(QString userId, QString friendId) {
    QList<int> messageIds;

    QSqlQuery query;
    query.prepare("SELECT message_id FROM Messages WHERE (sender_id = :userId AND receiver_id = :friendId) OR "
                  "(sender_id = :friendId AND receiver_id = :userId)");
    query.bindValue(":userId", userId);
    query.bindValue(":friendId", friendId);

    if (!query.exec()) {
        qDebug() << "Failed to retrieve message IDs for user with friend:" << query.lastError().text();
        return messageIds;
    }

    while (query.next()) {
        messageIds.append(query.value(0).toInt());
    }

    return messageIds;
}

QString DatabaseManager::getFriendIdFromDatabase(QString userId) {
    QSqlQuery query;
    query.prepare("SELECT friend_id FROM Friends WHERE user_id = ?");
    query.addBindValue(userId);

    if (!query.exec()) {
        qDebug() << "Failed to retrieve friend ID for user:" << query.lastError().text();
        return QString();
    }

    if (query.next()) {
        return query.value(0).toString();
    } else {
        qDebug() << "No friend ID found for user:" << userId;
        return QString();
    }
}

QString DatabaseManager::getUsernamefromId(QString userId) {
    QSqlQuery query;
    query.prepare("SELECT username FROM Users WHERE id = ?");
    query.addBindValue(userId);

    if (!query.exec()) {
        qDebug() << "Failed to retrieve username for ID:" << query.lastError().text();
        return QString();
    }

    if (query.next()) {
        return query.value(0).toString();
    } else {
        qDebug() << "No username found for ID:" << userId;
        return QString();
    }
}

QList<Message> DatabaseManager::getMessagesForConversation(int conversationId, QString userId, QString friendId) {
    QList<Message> messages;
    // Assuming you have a database connection and query setup
    QSqlQuery query;
    query.prepare("SELECT * FROM Messages WHERE message_id = :conversationId AND (sender_id = :userId OR sender_id = :friendId)");
    query.bindValue(":conversationId", conversationId);
    query.bindValue(":userId", userId);
    query.bindValue(":friendId", friendId);

    if (query.exec()) {
        while (query.next()) {
            Message message;
            message.setSenderId(query.value("sender_id").toString());
            message.setText(query.value("message_text").toString());
            messages.append(message);
        }
    }
    return messages;
}

QString DatabaseManager::hashPassword(QString password) {
    QByteArray hash = QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}

bool DatabaseManager::initializeDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("ChatApp.db");

    if (!db.open()) {
        qDebug() << "Error: Unable to connect to the database!";
        return false;
    }

    QSqlQuery query;

    // Create Users table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Users ("
                    "id TEXT PRIMARY KEY, "
                    "username TEXT UNIQUE NOT NULL, "
                    "password TEXT, "
                    "email TEXT)")) {
        qDebug() << "Failed to create Users table:" << query.lastError().text();
        return false;
    }

    // Create Profile table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Profile ("
                    "user_id TEXT, "
                    "image BLOB, "
                    "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                    "FOREIGN KEY (user_id) REFERENCES Users(id))")) {
        qDebug() << "Failed to create Profile table:" << query.lastError().text();
        return false;
    }

    // Create Friends table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Friends ("
                    "user_id TEXT, "
                    "friend_id TEXT, "
                    "FOREIGN KEY (user_id) REFERENCES Users(id), "
                    "FOREIGN KEY (friend_id) REFERENCES Users(id))")) {
        qDebug() << "Failed to create Friends table:" << query.lastError().text();
        return false;
    }

    // Create Conversation_members table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Conversation_members ("
                    "conversation_id INTEGER, "
                    "user_id TEXT, "
                    "FOREIGN KEY (conversation_id) REFERENCES Conversations(conversation_id), "
                    "FOREIGN KEY (user_id) REFERENCES Users(id))")) {
        qDebug() << "Failed to create Conversation_members table:" << query.lastError().text();
        return false;
    }

    // Create Messages table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Messages ("
                    "message_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "sender_id TEXT, "
                    "receiver_id TEXT, "
                    "message_text TEXT, "
                    "message_image BLOB, "
                    "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                    "FOREIGN KEY (receiver_id) REFERENCES Users(id), "
                    "FOREIGN KEY (sender_id) REFERENCES Users(id))")) {
        qDebug() << "Failed to create Messages table:" << query.lastError().text();
        return false;
    }

    // Create Conversations table
    if (!query.exec("CREATE TABLE IF NOT EXISTS Conversations ("
                    "conversation_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "sender_id TEXT, "
                    "message_text TEXT, "
                    "message_image BLOB, "
                    "timestamp DATETIME DEFAULT CURRENT_TIMESTAMP, "
                    "FOREIGN KEY (sender_id) REFERENCES Users(id))")) {
        qDebug() << "Failed to create Conversations table:" << query.lastError().text();
        return false;
    }

    return true;
}

QByteArray DatabaseManager::getProfilePicture(QString userId) {
    QByteArray imageData;
    QSqlQuery query;
    query.prepare("SELECT image FROM Profile WHERE user_id = :user_id ORDER BY timestamp DESC LIMIT 1");
    query.bindValue(":user_id", userId);

    if (!query.exec()) {
        qDebug() << "Failed to retrieve profile picture:" << query.lastError().text();
        return imageData;
    }

    if (query.next()) {
        imageData = query.value(0).toByteArray();
    } else {
        qDebug() << "No profile picture found for user:" << userId;
    }

    return imageData;
}


QString DatabaseManager::getUserIdFromName(QString username) {
    QSqlQuery query;
    query.prepare("SELECT id FROM Users WHERE username = ?");
    query.addBindValue(username);

    if (!query.exec()) {
        qDebug() << "Failed to retrieve user ID for username:" << query.lastError().text();
        return QString();
    }

    if (query.next()) {
        return query.value(0).toString();
    } else {
        qDebug() << "No user ID found for username:" << username;
        return QString();
    }
}

void DatabaseManager::displayUsers() {
    QSqlQuery query("SELECT id, username, password, email FROM Users");
    while (query.next()) {
        QString id = query.value(0).toString();
        QString username = query.value(1).toString();
        QString password = query.value(2).toString();
        QString email = query.value(3).toString();

        qDebug() << "ID:" << id << "Username:" << username << "Password[hashed]:" << hashPassword(password) << "Email:" << email;
    }
}

DatabaseManager::~DatabaseManager() {}
