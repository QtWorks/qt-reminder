#-------------------------------------------------
#
# Project created by QtCreator 2017-05-13T18:40:13
#
#-------------------------------------------------

INCLUDEPATH += ../qt-simple-notifier
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-simple-notifier-gui
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    addreminderdialog.cpp

HEADERS += mainwindow.h \
    addreminderdialog.h

FORMS    += mainwindow.ui \
    addreminderdialog.ui

RESOURCES += \
    resources.qrc

DISTFILES += \
    LICENSE \
    README.md
