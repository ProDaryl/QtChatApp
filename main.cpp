#include "databasemanager.h"
#include "signupwindows.h"
#include <QApplication>
#include <QtSql>
#include <QDebug>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SignUpWindows w;
    w.show();
    if (!DatabaseManager::database().initializeDatabase()) {
        qDebug() << "Failed to create database.";
    }
    DatabaseManager::database().displayUsers();

    return app.exec();
}
