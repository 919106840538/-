#-------------------------------------------------
#
# Project created by QtCreator 2020-10-08T18:27:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = demo_00
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    set_admin.cpp \
    log_in.cpp \
    in.cpp \
    changeinf.cpp \
    lookfor.cpp \
    remove.cpp \
    vipguanli.cpp \
    vipzhuce.cpp \
    findvip.cpp

HEADERS += \
        mainwindow.h \
    set_admin.h \
    log_in.h \
    in.h \
    changeinf.h \
    lookfor.h \
    remove.h \
    vipguanli.h \
    vipzhuce.h \
    findvip.h

FORMS += \
        mainwindow.ui \
    set_admin.ui \
    log_in.ui \
    in.ui \
    changeinf.ui \
    lookfor.ui \
    remove.ui \
    vipguanli.ui \
    vipzhuce.ui \
    findvip.ui

RESOURCES += \
    icon.qrc
