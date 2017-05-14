#-------------------------------------------------
#
# Project created by QtCreator 2017-05-13T18:40:13
#
#-------------------------------------------------

template = subdirs
SUBDIRS += ../qt-simple-notifier

#include(../qt-simple-notifier/qt-simple-notifier/inc/*)
#include(../qt-simple-notifier/qt-simple-notifier/src/*)

INCLUDEPATH += ../qt-simple-notifier
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-simple-notifier-gui
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    createreminderdialog.cpp

HEADERS += mainwindow.h \
    createreminderdialog.h

FORMS    += mainwindow.ui \
    createreminderdialog.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    LICENSE \
    README.md
