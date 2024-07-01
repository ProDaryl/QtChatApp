/********************************************************************************
** Form generated from reading UI file 'groupchatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPCHATWINDOW_H
#define UI_GROUPCHATWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
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

class Ui_GroupChatWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget_chats;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_message;
    QPushButton *pushButton_addImage;
    QPushButton *pushButton_send;
    QMenuBar *menubar;
    QMenu *menuGroup_Chatting;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GroupChatWindow)
    {
        if (GroupChatWindow->objectName().isEmpty())
            GroupChatWindow->setObjectName("GroupChatWindow");
        GroupChatWindow->resize(476, 468);
        GroupChatWindow->setStyleSheet(QString::fromUtf8("color: #f0f0f0;\n"
"border-radius: 10px;"));
        centralwidget = new QWidget(GroupChatWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(10, 40, 431, 361));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget_chats = new QListWidget(verticalLayoutWidget);
        listWidget_chats->setObjectName("listWidget_chats");
        listWidget_chats->setStyleSheet(QString::fromUtf8("border: 1px solid #ccc;\n"
"border-radius: 5px;\n"
"background-color: white;"));
        listWidget_chats->setProperty("isWrapping", QVariant(false));
        listWidget_chats->setWordWrap(true);

        verticalLayout_2->addWidget(listWidget_chats);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_message = new QLineEdit(verticalLayoutWidget);
        lineEdit_message->setObjectName("lineEdit_message");
        lineEdit_message->setStyleSheet(QString::fromUtf8("padding: 5px;\n"
"border: 1px solid #ccc;\n"
"border-radius: 5px;"));

        horizontalLayout_2->addWidget(lineEdit_message);

        pushButton_addImage = new QPushButton(verticalLayoutWidget);
        pushButton_addImage->setObjectName("pushButton_addImage");
        pushButton_addImage->setStyleSheet(QString::fromUtf8("padding: 5px 10px;\n"
"border: 1px solid #0078d7;\n"
"border-radius: 5px;\n"
"background-color: #0078d7;\n"
"color: white;"));

        horizontalLayout_2->addWidget(pushButton_addImage);

        pushButton_send = new QPushButton(verticalLayoutWidget);
        pushButton_send->setObjectName("pushButton_send");
        pushButton_send->setStyleSheet(QString::fromUtf8("padding: 5px 10px;\n"
"border: 1px solid #0078d7;\n"
"border-radius: 5px;\n"
"background-color: #0078d7;\n"
"color: white;"));

        horizontalLayout_2->addWidget(pushButton_send);


        verticalLayout_2->addLayout(horizontalLayout_2);

        GroupChatWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GroupChatWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 476, 22));
        menuGroup_Chatting = new QMenu(menubar);
        menuGroup_Chatting->setObjectName("menuGroup_Chatting");
        GroupChatWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(GroupChatWindow);
        statusbar->setObjectName("statusbar");
        GroupChatWindow->setStatusBar(statusbar);

        menubar->addAction(menuGroup_Chatting->menuAction());

        retranslateUi(GroupChatWindow);

        QMetaObject::connectSlotsByName(GroupChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *GroupChatWindow)
    {
        GroupChatWindow->setWindowTitle(QCoreApplication::translate("GroupChatWindow", "MainWindow", nullptr));
        pushButton_addImage->setText(QCoreApplication::translate("GroupChatWindow", "Add image", nullptr));
        pushButton_send->setText(QCoreApplication::translate("GroupChatWindow", "Send", nullptr));
        menuGroup_Chatting->setTitle(QCoreApplication::translate("GroupChatWindow", "Group Chating", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GroupChatWindow: public Ui_GroupChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPCHATWINDOW_H
