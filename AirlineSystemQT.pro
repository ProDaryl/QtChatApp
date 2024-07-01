QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# Path to the libcurl headers
INCLUDEPATH += C:/Users/Administrator/Documents/AirlineSystemQT/libcurl/libcurl_files/include

# Path to the libcurl library
LIBS += -LC:/Users/Administrator/Documents/AirlineSystemQT/libcurl/libcurl_files/lib -lcurl


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatwindow.cpp \
    databasemanager.cpp \
    groupchatwindow.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    message.cpp \
    messagewidget.cpp \
    sessionmanager.cpp \
    signupwindows.cpp \
    usercredentialsmanager.cpp

HEADERS += \
    chatwindow.h \
    databasemanager.h \
    groupchatwindow.h \
    loginwindow.h \
    mainwindow.h \
    message.h \
    messagewidget.h \
    sessionmanager.h \
    signupwindows.h \
    usercredentialsmanager.h

FORMS += \
    chatwindow.ui \
    groupchatwindow.ui \
    loginwindow.ui \
    mainwindow.ui \
    messagewidget.ui \
    signupwindows.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
