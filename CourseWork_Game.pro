QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    heroes/Lina/lina.cpp \
    heroes/Lina/linadetails.cpp \
    heroes/Phoenix/phoenix.cpp \
    heroes/Phoenix/phoenixdetails.cpp \
    heroes/hero.cpp \
    main.cpp \
    mainwindow.cpp \
    player/player.cpp

HEADERS += \
    heroes/Lina/lina.h \
    heroes/Lina/linadetails.h \
    heroes/Phoenix/phoenix.h \
    heroes/Phoenix/phoenixdetails.h \
    heroes/hero.h \
    mainwindow.h \
    player/player.h

FORMS += \
    heroes/Lina/linadetails.ui \
    heroes/Phoenix/phoenixdetails.ui \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    db/PlayersDataBase.txt
