#include <QtReminder/ReminderManager.h>

namespace QtReminder
{

ReminderManager::ReminderManager(){}

ReminderManager::~ReminderManager()
{
    this->reminders.clear();
}

void ReminderManager::append_reminder(Reminder &r)
{
    this->reminders.push_back(r);
}

void ReminderManager::remove_reminder(int index)
{
    this->reminders.erase(this->reminders.begin() + index);
}

} // namespace QtReminder
