#include <QtReminder/ReminderManager.h>
#include <QDebug>
namespace QtReminder
{

ReminderManager::ReminderManager(){}

ReminderManager::~ReminderManager()
{
    this->reminders.clear();
}

std::vector<Reminder>::iterator ReminderManager::getElementIterator(const QUuid reminder_id)
{
    return std::find_if(std::begin(this->reminders), std::end(this->reminders),
                           [reminder_id](Reminder &r) { return r.getReminderId() == reminder_id; });
}

void ReminderManager::appendReminder(Reminder &r)
{
    this->reminders.push_back(r);
}

void ReminderManager::removeReminder(const int index)
{
    this->reminders.erase(this->reminders.begin() + index);
}

void ReminderManager::removeReminder(const QUuid reminder_id)
{
    this->reminders.erase(getElementIterator(reminder_id));
}

const int ReminderManager::getReminderIndex(const QUuid reminder_id)
{
    auto begin = std::begin(this->reminders);
    auto it = getElementIterator(reminder_id);
    return std::distance(begin, it);
}

} // namespace QtReminder
