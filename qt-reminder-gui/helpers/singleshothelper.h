#ifndef SINGLESHOTHELPER
#define SINGLESHOTHELPER

#include <QtReminder/Reminder.h>

class SingleShotHelper
{
    QtReminder::Reminder *r;

public:
    SingleShotHelper() = delete;
    SingleShotHelper(const SingleShotHelper&) = delete;

    /**
     * @brief SingleShotHelper - Ctor
     * @param r - QtReminder::Reminder reference
     */
    SingleShotHelper(QtReminder::Reminder&);

    /**
     * @brief shot - Method for single shot
     */
    void shot();
};

#endif // SINGLESHOTHELPER

