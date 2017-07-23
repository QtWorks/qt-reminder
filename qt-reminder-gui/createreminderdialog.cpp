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
    QDateTime run_time{QDateTime::currentDateTime()};
    QTime start_every = this->ui->timeEdit->time();

    run_time = run_time.addMSecs(QTime(0, 0, 0).msecsTo(start_every));

    const shared_ptr<wstring> title = make_shared<wstring>(this->ui->lineEdit->text().toStdWString());
    const shared_ptr<wstring> description = make_shared<wstring>(this->ui->textEdit->toPlainText().toStdWString());
    bool cyclic = this->ui->checkBox->isChecked();

    MainWindow *parent = qobject_cast<MainWindow*>(this->parent());
    if (parent != nullptr)
    {
        parent->createReminder(run_time, title, description, cyclic);
    }
    this->close();
}

void CreateReminderDialog::onCancelClicked()
{
    this->close();
}
