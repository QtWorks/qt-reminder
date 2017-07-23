#-------------------------------------------------
#
# Project created by QtCreator 2017-05-13T18:40:13
#
#-------------------------------------------------

template = subdirs
INCLUDEPATH += ../qt-reminder-cli/inc

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
QT += sql
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt-reminder-gui
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
        createreminderdialog.cpp \
        ../qt-reminder-cli/src/QtReminder/Reminder.cpp \
        ../qt-reminder-cli/src/QtReminder/ReminderManager.cpp

HEADERS += mainwindow.h \
           createreminderdialog.h \
           ../qt-reminder-cli/inc/QtReminder/Reminder.h \
           ../qt-reminder-cli/inc/QtReminder/ReminderManager.h

FORMS    += mainwindow.ui \
            createreminderdialog.ui

RESOURCES += \
    resources.qrc
