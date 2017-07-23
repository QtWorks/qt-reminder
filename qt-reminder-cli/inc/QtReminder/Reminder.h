#ifndef REMINDER
#define REMINDER
#include <string>
#include <memory>

#include <QDateTime>
#include <QUuid>

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
    std::shared_ptr<std::wstring> title;

    /// Full description
    std::shared_ptr<std::wstring> description;

    /// Uuid
    QUuid reminder_id = QUuid::createUuid();

    /// Cyclic
    bool cyclic;

public:
    /**
     * @brief Reminder - Ctor
     * @param run_time - When notification have to be run_time
     * @param title - Title of notification
     * @param description - Its description
     * @param cyclic - Should be run cyclic
     */
    Reminder(QDateTime&, const std::shared_ptr<std::wstring>, const std::shared_ptr<std::wstring>, bool);

    /**
     * @brief Reminder - Ctor
     * @param run_time - When notification have to be run_time
     * @param title - Title of notification
     * @param description - Its description
     * @param created - When this reminder was created
     * @param cyclic - Should be run cyclic
     */
    Reminder(QDateTime&, const std::shared_ptr<std::wstring>, const std::shared_ptr<std::wstring>, QDateTime&, bool);

    /**
     * @brief Reminder - Ctor
     * @param r - reminder to copy
     */
    Reminder(Reminder const&);

    /**
     * @brief getTitle - Title of reminder
     * @return pointer to std::wstring
     */
    std::wstring* getTitle();

    /**
     * @brief isCyclic - Getter for cyclic value
     * @return True if run cyclic, in other case false
     */
    bool isCyclic();

    /**
     * @brief getRunTime - Getter for run_time
     * @return QDateTime object
     */
    QDateTime getRunTime();
};

}
#endif // REMINDER

