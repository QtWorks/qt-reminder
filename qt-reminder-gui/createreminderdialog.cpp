#include "createreminderdialog.h"
#include "ui_createreminderdialog.h"
#include <QCloseEvent>
#include <QDebug>
#include <QDateTime>
#include <memory>
#include <mainwindow.h>

using namespace std;

CreateReminderDialog::CreateReminderDialog(QWidget *parent) :
    QDialog{parent},
    ui{new Ui::CreateReminderDialog}
{
    ui->setupUi(this);

    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(onOkClicked()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(onCancelClicked()));
}

CreateReminderDialog::~CreateReminderDialog()
{
    delete ui;
}

void CreateReminderDialog::onOkClicked()
{
    // TODO add QTime to QDateTime, because this only replace time and this is BUG
    QDateTime run_time{QDateTime::currentDateTimeUtc()};
    run_time.setTime(this->ui->timeEdit->time());
    const shared_ptr<wstring> title = make_shared<wstring>(this->ui->lineEdit->text().toStdWString());
    const shared_ptr<wstring> description = make_shared<wstring>(this->ui->textEdit->toPlainText().toStdWString());

    MainWindow *parent = qobject_cast<MainWindow*>(this->parent());
    if (parent != nullptr)
    {
        parent->createReminder(run_time, title, description);
    }
    this->close();
}

void CreateReminderDialog::onCancelClicked()
{
    this->close();
}
