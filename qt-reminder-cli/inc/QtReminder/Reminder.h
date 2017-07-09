#ifndef REMINDER
#define REMINDER
#include <Qt/qdatetime.h>
#include <string>
#include <memory>

namespace QtReminder
{
/**
 * @brief The Reminder class
 */
class Reminder
{
    /// Time where object was created
    QDateTime created;

    /// Time when notification have to be run
    QDateTime run_time;

    /// Title of notification
    std::shared_ptr<std::string> title;

    /// Full description
    std::shared_ptr<std::string> description;

public:
    /**
     * @brief Reminder - Ctor
     * @param run_time - When notification have to be run_time
     * @param title - Title of notification
     * @param description - Its description
     */
    Reminder(QDateTime&, const std::shared_ptr<std::string>, const std::shared_ptr<std::string>);

    /**
     * @brief Reminder - Ctor
     * @param run_time - When notification have to be run_time
     * @param title - Title of notification
     * @param description - Its description
     * @param created - When this reminder was created
     */
    Reminder(QDateTime&, const std::shared_ptr<std::string>, const std::shared_ptr<std::string>, QDateTime&);


    /**
     * @brief Reminder - Ctor
     * @param r - reminder to copy
     */
    Reminder(Reminder const&);
};

}
#endif // REMINDER

