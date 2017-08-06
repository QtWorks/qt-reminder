#include <mainwindow.h>
#include <ui_mainwindow.h>
#include <createreminderdialog.h>
#include <helpers/singleshothelper.h>

#include <QtReminder/DatabaseManager.h>
#include <QtReminder/Reminder.h>

#include <QCloseEvent>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>


using QtReminder::Reminder;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent}, ui{new Ui::MainWindow}
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
    connect(this->addReminderAction.get(), SIGNAL(triggered()), this, SLOT(showCreateReminderWindow()));

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
    delete this->ui;
    for(auto task: this->cyclic_tasks)
    {
        delete task;
    }
}

void MainWindow::showAllReminders()
{
    this->show();
}

void MainWindow::showCreateReminderWindow()
{
    CreateReminderDialog reminderDialog{this};

    switch(int value = reminderDialog.exec())
    {
        default:
        {
//            qDebug() << value;
        }
    }
}

void MainWindow::addReminderToWidgetList(QtReminder::Reminder &r)
{
    this->ui->listWidget->addItem(QString::fromStdWString(*r.getTitle()));
}

void MainWindow::createReminder(QDateTime run_time, const shared_ptr<wstring> title,
                                const shared_ptr<wstring> description, bool cyclic)
{
    Reminder *r = new Reminder{run_time, title, description, cyclic};
    this->addReminderToWidgetList(*r);
    this->manager.appendReminder(*r);
    this->registerReminder(*r);
}

void MainWindow::removeReminder(int item_index)
{
    if (item_index < 0) { return; }

    QListWidgetItem *item = this->ui->listWidget->takeItem(item_index);

    this->ui->listWidget->removeItemWidget(item);
    this->manager.removeReminder(item_index);

    delete item;
}

void MainWindow::registerReminder(QtReminder::Reminder &r)
{
    if(r.isCyclic())
    {
        auto *task = new CyclicTaskHelper{r, this};
        this->cyclic_tasks.push_back(task);
        task->runTimer();
    }
    else
    {
        auto now = QDateTime::currentDateTime();
        SingleShotHelper *ssh = new SingleShotHelper{r};
        connect(ssh, SIGNAL(reminderShown(const QUuid)), this, SLOT(onReminderShown(const QUuid)));
        QTimer::singleShot(now.msecsTo(r.getRunTime()), [ssh](){ ssh->showReminder(); });
    }
}

void MainWindow::on_removeReminderButton_clicked()
{
    this->removeReminder(this->ui->listWidget->currentRow());
}

void MainWindow::onReminderShown(const QUuid reminder_id)
{
    const int index = this->manager.getReminderIndex(reminder_id);
    QListWidgetItem *item = this->ui->listWidget->takeItem(index);

    this->ui->listWidget->removeItemWidget(item);
    this->manager.removeReminder(reminder_id);

    delete item;
}
