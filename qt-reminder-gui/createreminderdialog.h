#ifndef CREATEREMINDERDIALOG_H
#define CREATEREMINDERDIALOG_H

#include <QDialog>
#include <QAbstractButton>

namespace Ui {
class CreateReminderDialog;
}

class CreateReminderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateReminderDialog(QWidget *parent = 0);
    ~CreateReminderDialog();

private slots:
    void onOkClicked();
    void onCancelClicked();

private:
    Ui::CreateReminderDialog *ui;

protected:
    void closeEvent(QCloseEvent *) override;
};

#endif // CREATEREMINDERDIALOG_H
