#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <iostream>

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

    this->setWindowIcon(this->largeIcon);


    // Tray action creation
    this->quitAction.reset(new QAction(tr("Quit"), this));
    connect(this->quitAction.get(), SIGNAL(triggered()), qApp, SLOT(quit()));

    // Tray menu creation
    this->trayMenu.reset(new QMenu(this));
    this->trayMenu->addAction(this->quitAction.get());

    // Tray icon creation
    this->trayIcon.reset(new QSystemTrayIcon(this));

    this->trayIcon->setIcon(this->smallIcon);
    this->trayIcon->setContextMenu(this->trayMenu.get());

    this->trayIcon->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
