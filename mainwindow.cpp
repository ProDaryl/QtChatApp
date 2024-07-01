#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), friendlistWidget(new QListWidget()), chatslistWidget(new QListWidget())
{
    ui->setupUi(this);
    ui->lineEdit_searchfriends->setVisible(false);
    ui->pushButton_addfriend->setVisible(false);

    // Set default profile picture
    QPixmap image(":/resources/Images/default_profile_picture.jpg");
    image = image.scaled(ui->label_profilepic->size() * 5, Qt::KeepAspectRatio);
    ui->label_profilepic->setPixmap(image);
    QString username = DatabaseManager::database().getUsernamefromId(SessionManager::instance().getUserId());
    ui->label_username->setText(username);
    loadProfilePicture();

    // Call friendList to populate the list
    friendList(ui->listWidget_chats);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete friendlistWidget;
    delete chatslistWidget;
}

void MainWindow::loadProfilePicture() {
    QString currentUserId = SessionManager::instance().getUserId();
    QByteArray imageData = DatabaseManager::database().getProfilePicture(currentUserId);

    if (!imageData.isEmpty()) {
        QPixmap pic;
        pic.loadFromData(imageData);
        pic = pic.scaled(ui->label_profilepic->size() * 5, Qt::KeepAspectRatio);
        ui->label_profilepic->setPixmap(pic);
    } else {
        qDebug() << "No profile picture to display.";
    }
}

void MainWindow::friendList(QListWidget *listWidget) {
    QString userId = SessionManager::instance().getUserId();
    qDebug() << "Loading friends for user ID:" << userId;

    if (userId.isEmpty()) {
        qDebug() << "Error: User ID is empty.";
        return;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isValid()) {
        qDebug() << "Error: No valid database connection.";
        return;
    }

    // Clear the list widget before populating it
    listWidget->clear();

    QSqlQuery query;

    query.prepare("SELECT U.id, U.username "
                  "FROM Users U "
                  "INNER JOIN Friends F ON U.id = F.friend_id "
                  "WHERE F.user_id = :userId AND F.friend_id IN "
                  "(SELECT user_id FROM Friends WHERE friend_id = :userId)");
    query.bindValue(":userId", userId);

    qDebug() << "Executing query:" << query.executedQuery();

    if (!query.exec()) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    bool hasFriends = false;
    while (query.next()) {
        hasFriends = true;
        QString friendId = query.value(0).toString();
        QString username = query.value(1).toString();
        QByteArray imageData = query.value(2).toByteArray();

        qDebug() << "Friend ID:" << friendId << "Username:" << username;

        if (imageData.isEmpty()) {
            qDebug() << "Image data is empty, loading default image.";
            imageData = loadImageDataFromResource(":/resources/Images/default_profile_picture.jpg");
        }

        QPixmap userImage;
        if (!userImage.loadFromData(imageData)) {
            qDebug() << "Failed to load image data, loading default image.";
            userImage.load(":/resources/Images/default_profile_picture.jpg");
        }

        QListWidgetItem *item = new QListWidgetItem(QIcon(userImage.scaled(64, 64)), username);
        listWidget->addItem(item);
    }

    if (!hasFriends) {
        qDebug() << "No friends found for user ID:" << userId;
    }

    listWidget->setIconSize(QSize(64, 64));
}

void MainWindow::insertProfilePicture(QString userId, QByteArray imageData)
{
    if (userId.isEmpty() || imageData.isEmpty()) {
        qDebug() << "User ID or Image Data is empty. Cannot insert profile picture.";
        return;
    }


    QSqlQuery query;
    query.prepare("INSERT INTO Profile (user_id, image, timestamp) VALUES (:user_id, :image, CURRENT_TIMESTAMP)");
    query.bindValue(":user_id", userId);
    query.bindValue(":image", imageData);

    if (!query.exec()) {
        qDebug() << "Failed to insert profile picture:" << query.lastError().text();
        return;
    }

    return;
}


QByteArray MainWindow::loadImageDataFromResource(QString resourcePath) {
    QFile file(resourcePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open resource file:" << resourcePath;
        return QByteArray();
    }

    return file.readAll();
}


bool MainWindow::addFriend(QString userId, QString friendId) {
    QSqlDatabase db = QSqlDatabase::database();

    if (!db.isValid()) {
        qDebug() << "Error: No valid database connection.";
        return false;
    }

    // Check if the friend ID exists
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM Users WHERE id = :friendId");
    checkQuery.bindValue(":friendId", friendId);

    if (!checkQuery.exec() || !checkQuery.next() || checkQuery.value(0).toInt() == 0) {
        qDebug() << "Error: Friend does not exist.";
        return false;
    }

    // Check if the friendship already exists in either direction
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM Friends WHERE (user_id = :userId AND friend_id = :friendId) OR (user_id = :friendId AND friend_id = :userId)");
    query.bindValue(":userId", userId);
    query.bindValue(":friendId", friendId);
    if (!query.exec() || !query.next()) {
        qDebug() << "Error: Failed to check existing friendship";
        return false;
    }
    int existingFriendshipCount = query.value(0).toInt();
    if (existingFriendshipCount > 0) {
        qDebug() << "Error: Friendship already exists";
        QMessageBox::warning(this, "Error", "Friendship already exists.");
        return false;
    }

    // Insert the friendship in both directions
    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO Friends (user_id, friend_id) VALUES (:userId, :friendId)");
    insertQuery.bindValue(":userId", userId);
    insertQuery.bindValue(":friendId", friendId);
    if (!insertQuery.exec()) {
        qDebug() << "Error: Failed to add friend:" << insertQuery.lastError().text();
        return false;
    }
    insertQuery.bindValue(":userId", friendId);
    insertQuery.bindValue(":friendId", userId);
    if (!insertQuery.exec()) {
        qDebug() << "Error: Failed to add friend:" << insertQuery.lastError().text();
        return false;
    }

    qDebug() << "Friend added successfully";
    return true;
}

bool MainWindow::hasExistingMessages() {
    QSqlQuery query("SELECT COUNT(*) FROM Messages");
    if (query.exec() && query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}

void MainWindow::on_pushButton_newchat_clicked() {
    ui->lineEdit_searchfriends->setVisible(true);
    ui->pushButton_addfriend->setVisible(true);
    ui->lineEdit_searchfriends->setFocus();
}

void MainWindow::on_pushButton_addfriend_clicked() {
    QString userId = SessionManager::instance().getUserId().trimmed();
    QString friendId = ui->lineEdit_searchfriends->text().trimmed();

    if (friendId == userId) {
        qDebug() << "Error: Cannot add yourself as a friend.";
        QMessageBox::warning(this, "Error", "Cannot add yourself as a friend");
        return;
    }

    if (addFriend(userId, friendId)) {
        SessionManager::instance().setFriendId(friendId);
        QString message = DatabaseManager::database().getUsernamefromId(friendId) + " is now your friend";
        QMessageBox::information(this, "Friend added", message);
        friendList(ui->listWidget_chats);
        ui->lineEdit_searchfriends->clear();
    } else {
        qDebug() << "Failed to add friend";
    }
}

void MainWindow::on_pushButton_addPic_clicked() {
    QString currentUserId = SessionManager::instance().getUserId();
    QString filter = "Image Files (*.jpg *.png *.jpeg)";
    QString imagePath = QFileDialog::getOpenFileName(this, "Select a picture", QDir::homePath(), filter);

    if (!imagePath.isEmpty()) {
        QPixmap pic(imagePath);
        pic = pic.scaled(ui->label_profilepic->size(), Qt::KeepAspectRatio);

        QByteArray imageData;
        QBuffer buffer(&imageData);
        buffer.open(QIODevice::WriteOnly);
        pic.save(&buffer, "JPG");

        insertProfilePicture(currentUserId, imageData);
        ui->label_profilepic->setPixmap(pic);
    }
}


void MainWindow::on_listWidget_chats_itemClicked(QListWidgetItem *item) {
    QString friendName = item->text();
    QString friendId = DatabaseManager::database().getUserIdFromName(friendName);
    SessionManager::instance().setFriendId(friendId);
    ChatWindow *chatWindow = new ChatWindow(this);
    chatWindow->show();
}

void MainWindow::on_pushButton_groupchat_clicked()
{
    GroupChatWindow *window = new GroupChatWindow;
    window->show();
}

