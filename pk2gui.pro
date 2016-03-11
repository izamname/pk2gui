#-------------------------------------------------
#
# Project created by QtCreator 2016-03-11T00:53:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = pk2gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pk2cmd.cpp

HEADERS  += mainwindow.h \
    degisken.h \
    pk2cmd.h

FORMS    += mainwindow.ui

RESOURCES += \
    resimler.qrc
