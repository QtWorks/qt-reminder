#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDateTime>
#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <memory>
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

    void createReminder(QDateTime, const shared_ptr<wstring>, const shared_ptr<wstring>);

// Private slots
private slots:
    void addReminder();
    void showAllReminders();
    void showCreateReminderWindow();

// Private variables
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
};

#endif // MAINWINDOW_H
