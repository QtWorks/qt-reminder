#include "cyclictaskhelper.h"

#include <QDebug>

using QtReminder::Reminder;

CyclicTaskHelper::CyclicTaskHelper(Reminder &r, QObject *parent):
    QObject{parent}, r{&r}, timer{new QTimer{this}}
{
    connect(this->timer, SIGNAL(timeout()), this, SLOT(showReminder()));
}

CyclicTaskHelper::~CyclicTaskHelper()
{
    this->timer->stop();
    disconnect(this->timer, SIGNAL(timeout()), 0, 0);

    delete this->timer;
}

void CyclicTaskHelper::showReminder()
{
    qDebug()<< this->r->getReminderId().toString();
}

void CyclicTaskHelper::runTimer(QDateTime startdate)
{
    this->timer->start(startdate.msecsTo(r->getRunTime()));
}
