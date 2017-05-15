#-------------------------------------------------
#
# Project created by QtCreator 2017-05-13T18:40:13
#
#-------------------------------------------------

template = subdirs
INCLUDEPATH += ../qt-reminder-cli/inc
INCLUDEPATH += ../qt-reminder-cli/src

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
QT += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-reminder-gui
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
