/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit_username;
    QLabel *label_logo;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_login;
    QPushButton *pushButton_quit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_developer;
    QLabel *label_4;
    QLineEdit *lineEdit_email;
    QMenuBar *menubar;
    QMenu *menuLogin;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(623, 291);
        LoginWindow->setStyleSheet(QString::fromUtf8("background-color:  #f2f2f0;\n"
"border-radius: 10px;"));
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setStyleSheet(QString::fromUtf8("padding: 5px;\n"
"border: 1px solid #ccc;\n"
"border-radius: 5px;"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_username);

        label_logo = new QLabel(centralwidget);
        label_logo->setObjectName("label_logo");
        label_logo->setStyleSheet(QString::fromUtf8("background-repeat: no-repeat;\n"
"background-position: center;\n"
"min-height: 100px;"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_logo);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_login = new QPushButton(centralwidget);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setStyleSheet(QString::fromUtf8("padding: 5px 10px;\n"
"border: 1px solid #0078d7;\n"
"border-radius: 5px;\n"
"background-color: #0078d7;\n"
"color: white;"));

        horizontalLayout_3->addWidget(pushButton_login);

        pushButton_quit = new QPushButton(centralwidget);
        pushButton_quit->setObjectName("pushButton_quit");
        pushButton_quit->setStyleSheet(QString::fromUtf8("padding: 5px 10px;\n"
"border: 1px solid #0078d7;\n"
"border-radius: 5px;\n"
"background-color: #0078d7;\n"
"color: white;"));

        horizontalLayout_3->addWidget(pushButton_quit);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");

        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_4);

        label_developer = new QLabel(centralwidget);
        label_developer->setObjectName("label_developer");
        label_developer->setStyleSheet(QString::fromUtf8("font-weight: bold;\n"
"color: #333;"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_developer);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);

        lineEdit_email = new QLineEdit(centralwidget);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setStyleSheet(QString::fromUtf8("padding: 5px;\n"
"border: 1px solid #ccc;\n"
"border-radius: 5px;"));
        lineEdit_email->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_email);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 623, 22));
        menuLogin = new QMenu(menubar);
        menuLogin->setObjectName("menuLogin");
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        menubar->addAction(menuLogin->menuAction());

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "Username:", nullptr));
        label_logo->setText(QString());
        pushButton_login->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        pushButton_quit->setText(QCoreApplication::translate("LoginWindow", "Quit", nullptr));
        label_developer->setText(QCoreApplication::translate("LoginWindow", "Developed by: ", nullptr));
        label_4->setText(QCoreApplication::translate("LoginWindow", "Email:", nullptr));
        menuLogin->setTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
