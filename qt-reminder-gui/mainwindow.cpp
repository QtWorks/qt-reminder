#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <createreminderdialog.h>
#include <QDebug>
#include <QtReminder/DatabaseManager.h>
#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if(false == QSystemTrayIcon::isSystemTrayAvailable())
    {
        QMessageBox::critical(this, tr("Cirtical error"), tr("Your system not support tray applications!"));
        QApplication::exit(-1);
    }

    // MainWindowConfiguration
    this->setWindowIcon(this->largeIcon);
    this->setWindowTitle("Simple notifier");


    // Tray action creation
    this->addReminderAction.reset(new QAction{tr("Add reminder"), this});
    connect(this->addReminderAction.get(), SIGNAL(triggered()), this, SLOT(createReminder()));

    this->showAllRemindersAction.reset(new QAction{tr("Show all reminders"), this});
    connect(this->showAllRemindersAction.get(), SIGNAL(triggered()), this, SLOT(showAllReminders()));

    this->quitAction.reset(new QAction{tr("Quit"), this});
    connect(this->quitAction.get(), SIGNAL(triggered()), qApp, SLOT(quit()));


    // Tray menu creation

    this->trayMenu.reset(new QMenu{this});
    this->trayMenu->addAction(this->addReminderAction.get());
    this->trayMenu->addAction(this->showAllRemindersAction.get());
    this->trayMenu->addAction(this->quitAction.get());

    // Tray icon creation
    this->trayIcon.reset(new QSystemTrayIcon{this});

    this->trayIcon->setIcon(this->smallIcon);
    this->trayIcon->setContextMenu(this->trayMenu.get());

    this->trayIcon->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addReminder()
{
    qDebug() <<"Add reminder";
}

void MainWindow::showAllReminders()
{
    this->show();
}

void MainWindow::createReminder()
{
    CreateReminderDialog reminderDialog{this};

    switch(int value = reminderDialog.exec())
    {
        default:
        {
            qDebug() << value;
        }
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(this->isVisible())
    {
        this->hide();
        event->ignore();
    }
}
