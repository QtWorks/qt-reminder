#ifndef SINGLESHOTHELPER
#define SINGLESHOTHELPER

#include <QObject>
#include <QUuid>

#include <QtReminder/Reminder.h>

class SingleShotHelper: public QObject
{
    Q_OBJECT

private:
    QtReminder::Reminder *r;

public:
    SingleShotHelper() = delete;
    SingleShotHelper(const SingleShotHelper&) = delete;
    SingleShotHelper(SingleShotHelper&&) = delete;
    SingleShotHelper& operator=(const SingleShotHelper&) = delete;
    SingleShotHelper& operator=(SingleShotHelper&&) = delete;

    /**
     * @brief SingleShotHelper - Ctor
     * @param r - QtReminder::Reminder reference
     * @param parent - Object pointer, nullptr default
     */
    SingleShotHelper(QtReminder::Reminder&, QObject* = nullptr);

    /**
     * @brief showReminder - Show reminder
     */
    void showReminder();

    /**
     * @brief ~SingleShotHelper - virtual Dtor
     */
    virtual ~SingleShotHelper(){}

signals:
    /**
     * @brief reminderShown - signal send after show reminder. Parameter is a QUuid of shown reminder.
     */
    void reminderShown(const QUuid);
};

#endif // SINGLESHOTHELPER

