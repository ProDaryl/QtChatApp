/********************************************************************************
** Form generated from reading UI file 'chatwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIDGET_H
#define UI_CHATWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWidget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listWidget_chats;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_message;
    QPushButton *pushButton_addImage;
    QPushButton *pushButton_send;
    QPushButton *pushButton_back;

    void setupUi(QWidget *ChatWidget)
    {
        if (ChatWidget->objectName().isEmpty())
            ChatWidget->setObjectName("ChatWidget");
        ChatWidget->resize(576, 437);
        verticalLayoutWidget = new QWidget(ChatWidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 70, 561, 321));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget_chats = new QListWidget(verticalLayoutWidget);
        listWidget_chats->setObjectName("listWidget_chats");
        listWidget_chats->setProperty("isWrapping", QVariant(false));
        listWidget_chats->setWordWrap(true);

        verticalLayout_2->addWidget(listWidget_chats);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_message = new QLineEdit(verticalLayoutWidget);
        lineEdit_message->setObjectName("lineEdit_message");

        horizontalLayout_2->addWidget(lineEdit_message);

        pushButton_addImage = new QPushButton(verticalLayoutWidget);
        pushButton_addImage->setObjectName("pushButton_addImage");

        horizontalLayout_2->addWidget(pushButton_addImage);

        pushButton_send = new QPushButton(verticalLayoutWidget);
        pushButton_send->setObjectName("pushButton_send");

        horizontalLayout_2->addWidget(pushButton_send);


        verticalLayout_2->addLayout(horizontalLayout_2);

        pushButton_back = new QPushButton(ChatWidget);
        pushButton_back->setObjectName("pushButton_back");
        pushButton_back->setGeometry(QRect(40, 10, 75, 24));

        retranslateUi(ChatWidget);

        QMetaObject::connectSlotsByName(ChatWidget);
    } // setupUi

    void retranslateUi(QWidget *ChatWidget)
    {
        ChatWidget->setWindowTitle(QCoreApplication::translate("ChatWidget", "Form", nullptr));
        pushButton_addImage->setText(QCoreApplication::translate("ChatWidget", "Add image", nullptr));
        pushButton_send->setText(QCoreApplication::translate("ChatWidget", "Send", nullptr));
        pushButton_back->setText(QCoreApplication::translate("ChatWidget", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWidget: public Ui_ChatWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIDGET_H
