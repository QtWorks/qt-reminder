#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QMenu>
#include <memory>

using std::unique_ptr;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

// Private slots
private slots:
    void addReminder();
    void showAllReminders();

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
};

#endif // MAINWINDOW_H
