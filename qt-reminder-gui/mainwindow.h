#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QDateTime>
#include <QMainWindow>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QUuid>

#include <helpers/cyclictaskhelper.h>
#include <QtReminder/Reminder.h>
#include <QtReminder/ReminderManager.h>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void createReminder(QDateTime, const shared_ptr<wstring>, const shared_ptr<wstring>, bool);
    void removeReminder(int);

// Private slots
private slots:
    void showAllReminders();
    void showCreateReminderWindow();

    void on_removeReminderButton_clicked();
    void onReminderShown(const QUuid);

private:
    Ui::MainWindow *ui;

    unique_ptr<QSystemTrayIcon> trayIcon;

    QIcon largeIcon = QIcon(":/res/alarm-bell-large.png");
    QIcon smallIcon = QIcon(":/res/alarm-bell.png");

    unique_ptr<QMenu> trayMenu;

    unique_ptr<QAction> addReminderAction;
    unique_ptr<QAction> showAllRemindersAction;
    unique_ptr<QAction> quitAction;

    QtReminder::ReminderManager manager{};

    std::vector<CyclicTaskHelper*> cyclic_tasks;

    void addReminderToWidgetList(QtReminder::Reminder&);
    void registerReminder(QtReminder::Reminder&);
};

#endif // MAINWINDOW_H
