/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget_chats;
    QLineEdit *lineEdit_searchfriends;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_newchat;
    QPushButton *pushButton_groupchat;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_username;
    QLabel *label_profilepic;
    QPushButton *pushButton_addPic;
    QPushButton *pushButton_addfriend;
    QMenuBar *menubar;
    QMenu *menuChats;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"background-color: #f0f0f0;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(50, 90, 421, 371));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_chats = new QListWidget(verticalLayoutWidget);
        listWidget_chats->setObjectName("listWidget_chats");
        listWidget_chats->setStyleSheet(QString::fromUtf8("border: 1px solid #ccc;\n"
"border-radius: 5px;\n"
"background-color: white;"));

        verticalLayout->addWidget(listWidget_chats);

        lineEdit_searchfriends = new QLineEdit(centralwidget);
        lineEdit_searchfriends->setObjectName("lineEdit_searchfriends");
        lineEdit_searchfriends->setGeometry(QRect(110, 10, 211, 41));
        lineEdit_searchfriends->setStyleSheet(QString::fromUtf8("font-size: 1.5em;\n"
"padding: 5px;\n"
"border: 1px solid #ccc;\n"
"border-radius: 5px;"));
        verticalLayoutWidget_2 = new QWidget(centralwidget);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(520, 20, 231, 391));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_newchat = new QPushButton(verticalLayoutWidget_2);
        pushButton_newchat->setObjectName("pushButton_newchat");
        pushButton_newchat->setStyleSheet(QString::fromUtf8("padding: 5px 10px;\n"
"border: 1px solid #0078d7;\n"
"border-radius: 5px;\n"
"background-color: #0078d7;\n"
"color: white;"));

        verticalLayout_2->addWidget(pushButton_newchat);

        pushButton_groupchat = new QPushButton(verticalLayoutWidget_2);
        pushButton_groupchat->setObjectName("pushButton_groupchat");
        pushButton_groupchat->setStyleSheet(QString::fromUtf8("padding: 5px 10px;\n"
"border: 1px solid #0078d7;\n"
"border-radius: 5px;\n"
"background-color: #0078d7;\n"
"color: white;"));

        verticalLayout_2->addWidget(pushButton_groupchat);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        label_username = new QLabel(verticalLayoutWidget_2);
        label_username->setObjectName("label_username");
        label_username->setStyleSheet(QString::fromUtf8("font-size: 14px;\n"
"font-family: Arial, sans-serif; \n"
"font-weight: bold; \n"
"color: #333; \n"
"text-align: center;"));

        verticalLayout_3->addWidget(label_username);

        label_profilepic = new QLabel(verticalLayoutWidget_2);
        label_profilepic->setObjectName("label_profilepic");

        verticalLayout_3->addWidget(label_profilepic);

        pushButton_addPic = new QPushButton(verticalLayoutWidget_2);
        pushButton_addPic->setObjectName("pushButton_addPic");
        pushButton_addPic->setStyleSheet(QString::fromUtf8("padding: 5px 10px;\n"
"border: 1px solid #0078d7;\n"
"border-radius: 5px;\n"
"background-color: #0078d7;\n"
"color: white;"));

        verticalLayout_3->addWidget(pushButton_addPic);


        verticalLayout_2->addLayout(verticalLayout_3);

        pushButton_addfriend = new QPushButton(centralwidget);
        pushButton_addfriend->setObjectName("pushButton_addfriend");
        pushButton_addfriend->setGeometry(QRect(320, 10, 91, 41));
        pushButton_addfriend->setStyleSheet(QString::fromUtf8("padding: 5px 10px;\n"
"border: 1px solid #0078d7;\n"
"border-radius: 5px;\n"
"background-color: #0078d7;\n"
" color: white;"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuChats = new QMenu(menubar);
        menuChats->setObjectName("menuChats");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuChats->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lineEdit_searchfriends->setText(QString());
        lineEdit_searchfriends->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter a friend ID", nullptr));
        pushButton_newchat->setText(QCoreApplication::translate("MainWindow", "New Chat", nullptr));
        pushButton_groupchat->setText(QCoreApplication::translate("MainWindow", "Group Chat", nullptr));
        label_username->setText(QString());
        label_profilepic->setText(QString());
        pushButton_addPic->setText(QCoreApplication::translate("MainWindow", "Add a profile picture", nullptr));
        pushButton_addfriend->setText(QCoreApplication::translate("MainWindow", "Add friend", nullptr));
        menuChats->setTitle(QCoreApplication::translate("MainWindow", "Chats", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
