#-------------------------------------------------
#
# Project created by QtCreator 2019-06-05T23:11:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HERO_SQUARE
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        body.cpp \
        gamewindow.cpp \
        main.cpp \
        mainwindow.cpp \
        pausewindow.cpp \
        trainingwindow.cpp

HEADERS += \
        body.h \
        gamewindow.h \
        mainwindow.h \
        pausewindow.h \
        trainingwindow.h

FORMS += \
        gamewindow.ui \
        mainwindow.ui \
        pausewindow.ui \
        trainingwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    sounds/OST — Calling all units (www.mixmuz.ru).mp3 \
    sounds/PAYDAY 2 Soundtrack — 08 - Fuse Box (www.mixmuz.ru).mp3 \
    sounds/Payday 2 — Full Force Forward (www.mixmuz.ru).mp3 \
    sounds/Simon Viklund — Black Yellow Moebius(PAYDAY 2 the Soundtrack) (www.mixmuz.ru).mp3 \
    sounds/Simon Viklund — Time Window (Payday 2 OST) (www.mixmuz.ru).mp3



