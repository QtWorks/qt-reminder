#ifndef REMINDERMANAGER
#define REMINDERMANAGER

#include <vector>

#include <QUuid>

#include <QtReminder/Reminder.h>

using QtReminder::Reminder;

namespace QtReminder
{

class ReminderManager
{
    /// Reminders container
    std::vector<Reminder> reminders;

    /**
     * @brief getElementIterator - Function return iterator to element with id
     * @param reminder_id - id of element
     * @return iterator
     */
    std::vector<Reminder>::iterator getElementIterator(const QUuid);

public:

    /**
     * @brief ReminderManager - Ctor
     */
    ReminderManager();
    ~ReminderManager();

    /**
     * @brief appendReminder - function appending reminder to container
     * @param r - Reminder object
     */
    void appendReminder(Reminder&);

    /**
     * @brief removeReminder - function removing reminder from container
     * @param index - index of element
     */
    void removeReminder(const int);

    /**
     * @brief removeReminder - function removing reminder from container
     * @param reminder_id - id of element
     */
    void removeReminder(const QUuid);

    /**
     * @brief getReminderIndex - get index of reminder with id
     * @param reminder_id - id of element
     * @return index of element
     */
    const int getReminderIndex(const QUuid);
};

}
#endif // REMINDERMANAGER

