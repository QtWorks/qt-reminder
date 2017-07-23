#ifndef REMINDERMANAGER
#define REMINDERMANAGER
#include <vector>
#include <QtReminder/Reminder.h>

using QtReminder::Reminder;

namespace QtReminder
{

class ReminderManager
{
    /// Reminders container
    std::vector<Reminder> reminders;
public:

    /**
     * @brief ReminderManager - Ctor
     */
    ReminderManager();
    ~ReminderManager();

    /**
     * @brief append_reminder - function appending reminder to container
     * @param r - Reminder object
     */
    void append_reminder(Reminder&);

    /**
     * @brief remove_reminder - function removing reminder from container
     * @param index - index of element
     */
    void remove_reminder(int);
};

}
#endif // REMINDERMANAGER

