#include "addreminderdialog.h"
#include "ui_addreminderdialog.h"

AddReminderDialog::AddReminderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReminderDialog)
{
    ui->setupUi(this);

    ui->comboBox->addItem(tr("sec"));
    ui->comboBox->addItem(tr("min"));
    ui->comboBox->addItem(tr("hours"));
}

AddReminderDialog::~AddReminderDialog()
{
    delete ui;
}
