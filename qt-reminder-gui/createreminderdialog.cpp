#include "createreminderdialog.h"
#include "ui_createreminderdialog.h"
#include <QCloseEvent>
#include <QDebug>

CreateReminderDialog::CreateReminderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateReminderDialog)
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
    qDebug() <<"ok";
}

void CreateReminderDialog::onCancelClicked()
{
    this->close();
}


void CreateReminderDialog::closeEvent(QCloseEvent *event)
{
    QDialog::closeEvent(event);
    event->ignore();
}
