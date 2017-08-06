#include "singleshothelper.h"

#include <QtCore>

SingleShotHelper::SingleShotHelper(QtReminder::Reminder &r, QObject *parent):
    QObject{parent}, r{&r}
{
}

void SingleShotHelper::showReminder()
{
    qDebug()<<r->getReminderId().toString() <<" " <<r->getTitle();
    emit reminderShown(r->getReminderId());
    delete this;
}
