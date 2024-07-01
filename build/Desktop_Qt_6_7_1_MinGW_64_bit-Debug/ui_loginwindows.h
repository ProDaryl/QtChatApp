/********************************************************************************
** Form generated from reading UI file 'loginwindows.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOWS_H
#define UI_LOGINWINDOWS_H

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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *label_userName;
    QLabel *label_Password;
    QLineEdit *lineEdit_UserName;
    QLineEdit *lineEdit_Password;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_signIn;
    QPushButton *pushButton_Quit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_signup;
    QMenuBar *menubar;
    QMenu *menuLogin;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(514, 317);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        label_userName = new QLabel(centralwidget);
        label_userName->setObjectName("label_userName");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_userName);

        label_Password = new QLabel(centralwidget);
        label_Password->setObjectName("label_Password");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_Password);

        lineEdit_UserName = new QLineEdit(centralwidget);
        lineEdit_UserName->setObjectName("lineEdit_UserName");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_UserName);

        lineEdit_Password = new QLineEdit(centralwidget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_Password);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        pushButton_signIn = new QPushButton(centralwidget);
        pushButton_signIn->setObjectName("pushButton_signIn");

        horizontalLayout->addWidget(pushButton_signIn);

        pushButton_Quit = new QPushButton(centralwidget);
        pushButton_Quit->setObjectName("pushButton_Quit");

        horizontalLayout->addWidget(pushButton_Quit);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        label_signup = new QLabel(centralwidget);
        label_signup->setObjectName("label_signup");
        label_signup->setStyleSheet(QString::fromUtf8("color: green;\n"
"text-decoration: underline;"));

        horizontalLayout_2->addWidget(label_signup);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 514, 22));
        menuLogin = new QMenu(menubar);
        menuLogin->setObjectName("menuLogin");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuLogin->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_userName->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_Password->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        lineEdit_Password->setText(QString());
        pushButton_signIn->setText(QCoreApplication::translate("MainWindow", "SignIn", nullptr));
        pushButton_Quit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Already have an account?", nullptr));
        label_signup->setText(QCoreApplication::translate("MainWindow", "Create an account", nullptr));
        menuLogin->setTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
class MainWindow: private slots:
                                             void on_pushButton_signIn_clicked();
private slots:
                                             void on_pushButton_signIn_clicked();
private slots:
                                             void on_pushButton_Quit_clicked();
private slots:
                                         void on_pushButton_Quit_clicked();
Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOWS_H
