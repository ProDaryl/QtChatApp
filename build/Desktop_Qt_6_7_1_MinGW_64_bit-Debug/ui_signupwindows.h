/********************************************************************************
** Form generated from reading UI file 'signupwindows.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPWINDOWS_H
#define UI_SIGNUPWINDOWS_H

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

class Ui_SignUpWindows
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *label_fullName;
    QLineEdit *lineEdit_FullName;
    QLabel *label_email;
    QLineEdit *lineEdit_email;
    QLabel *label_password;
    QLineEdit *lineEdit_Password;
    QLabel *label_confirmPass;
    QLineEdit *lineEdit_ConfirmPass;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_SignUp;
    QPushButton *pushButton_Quit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QPushButton *pushButton_login;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuSign_In_Page;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SignUpWindows)
    {
        if (SignUpWindows->objectName().isEmpty())
            SignUpWindows->setObjectName("SignUpWindows");
        SignUpWindows->resize(559, 248);
        centralwidget = new QWidget(SignUpWindows);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        label_fullName = new QLabel(centralwidget);
        label_fullName->setObjectName("label_fullName");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_fullName);

        lineEdit_FullName = new QLineEdit(centralwidget);
        lineEdit_FullName->setObjectName("lineEdit_FullName");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_FullName);

        label_email = new QLabel(centralwidget);
        label_email->setObjectName("label_email");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_email);

        lineEdit_email = new QLineEdit(centralwidget);
        lineEdit_email->setObjectName("lineEdit_email");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_email);

        label_password = new QLabel(centralwidget);
        label_password->setObjectName("label_password");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_password);

        lineEdit_Password = new QLineEdit(centralwidget);
        lineEdit_Password->setObjectName("lineEdit_Password");
        lineEdit_Password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_Password);

        label_confirmPass = new QLabel(centralwidget);
        label_confirmPass->setObjectName("label_confirmPass");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_confirmPass);

        lineEdit_ConfirmPass = new QLineEdit(centralwidget);
        lineEdit_ConfirmPass->setObjectName("lineEdit_ConfirmPass");
        lineEdit_ConfirmPass->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit_ConfirmPass);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pushButton_SignUp = new QPushButton(centralwidget);
        pushButton_SignUp->setObjectName("pushButton_SignUp");

        horizontalLayout_3->addWidget(pushButton_SignUp);

        pushButton_Quit = new QPushButton(centralwidget);
        pushButton_Quit->setObjectName("pushButton_Quit");

        horizontalLayout_3->addWidget(pushButton_Quit);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        pushButton_login = new QPushButton(centralwidget);
        pushButton_login->setObjectName("pushButton_login");
        pushButton_login->setStyleSheet(QString::fromUtf8("color: blue;\n"
"text-decoration: underline;"));

        horizontalLayout_4->addWidget(pushButton_login);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        formLayout->setLayout(5, QFormLayout::FieldRole, horizontalLayout_4);

        SignUpWindows->setCentralWidget(centralwidget);
        menubar = new QMenuBar(SignUpWindows);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 559, 22));
        menuSign_In_Page = new QMenu(menubar);
        menuSign_In_Page->setObjectName("menuSign_In_Page");
        SignUpWindows->setMenuBar(menubar);
        statusbar = new QStatusBar(SignUpWindows);
        statusbar->setObjectName("statusbar");
        SignUpWindows->setStatusBar(statusbar);

        menubar->addAction(menuSign_In_Page->menuAction());

        retranslateUi(SignUpWindows);

        QMetaObject::connectSlotsByName(SignUpWindows);
    } // setupUi

    void retranslateUi(QMainWindow *SignUpWindows)
    {
        SignUpWindows->setWindowTitle(QCoreApplication::translate("SignUpWindows", "SignUpWindows", nullptr));
        label_fullName->setText(QCoreApplication::translate("SignUpWindows", "Full name:", nullptr));
        label_email->setText(QCoreApplication::translate("SignUpWindows", "Email address:", nullptr));
        label_password->setText(QCoreApplication::translate("SignUpWindows", "Password:", nullptr));
        label_confirmPass->setText(QCoreApplication::translate("SignUpWindows", "Confirm Password", nullptr));
        pushButton_SignUp->setText(QCoreApplication::translate("SignUpWindows", "Signup", nullptr));
        pushButton_Quit->setText(QCoreApplication::translate("SignUpWindows", "Quit", nullptr));
        label_3->setText(QCoreApplication::translate("SignUpWindows", "Already have an account?", nullptr));
        pushButton_login->setText(QCoreApplication::translate("SignUpWindows", "Login", nullptr));
        menuSign_In_Page->setTitle(QCoreApplication::translate("SignUpWindows", "Create an account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUpWindows: public Ui_SignUpWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPWINDOWS_H
