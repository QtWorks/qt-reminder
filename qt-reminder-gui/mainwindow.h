#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>

#include <QDateTime>
#include <QMainWindow>
#include <QMenu>
#include <QSignalMapper>
#include <QSystemTrayIcon>
#include <QTimer>

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
    void showReminder(const QString);

    void on_removeReminderButton_clicked();

signals:
    void timeToRemind(const QString);

private:
    Ui::MainWindow *ui;

    unique_ptr<QSystemTrayIcon> trayIcon;

    QIcon largeIcon = QIcon(":/res/alarm-bell-large.png");
    QIcon smallIcon = QIcon(":/res/alarm-bell.png");

    unique_ptr<QMenu> trayMenu;

    unique_ptr<QAction> addReminderAction;
    unique_ptr<QAction> showAllRemindersAction;
    std::vector<QSignalMapper*> signal_mappers;
    std::vector<QTimer*> timers;
    unique_ptr<QAction> quitAction;

    QtReminder::ReminderManager manager{};

    void addReminderToWidgetList(QtReminder::Reminder&);
    void registerReminder(QtReminder::Reminder&);
};

#endif // MAINWINDOW_H
