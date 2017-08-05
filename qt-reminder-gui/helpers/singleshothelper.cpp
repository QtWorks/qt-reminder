#include "singleshothelper.h"

#include <QtCore>

SingleShotHelper::SingleShotHelper(QtReminder::Reminder &r):
    r{&r}
{
}

void SingleShotHelper::shot()
{
    qDebug()<<r->getReminderId().toString() <<" " <<r->getTitle();
    delete this;
}
