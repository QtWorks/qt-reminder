#ifndef CYCLICTASKHELPER_H
#define CYCLICTASKHELPER_H

#include <QObject>
#include <QSignalMapper>
#include <QTimer>

#include <QtReminder/Reminder.h>

class CyclicTaskHelper : public QObject
{
    Q_OBJECT

private:
    QtReminder::Reminder *r;
    QTimer *timer;

public:
    CyclicTaskHelper() = delete;
    CyclicTaskHelper(const CyclicTaskHelper&) = delete;
    CyclicTaskHelper(CyclicTaskHelper&&) = delete;
    CyclicTaskHelper& operator=(const CyclicTaskHelper&) = delete;
    CyclicTaskHelper& operator=(CyclicTaskHelper&&) = delete;

    /**
     * @brief CyclicTaskHelper - Ctor
     * @param r - reminder reference
     * @param parent - pointer to QObject
     */
    explicit CyclicTaskHelper(QtReminder::Reminder&, QObject*);

    /**
     * @brief - ~CyclicTaskHelper - Dtor
     */
    ~CyclicTaskHelper();

    /**
     * @brief runTimer - function starting timer work
     * @param startdate - start datetime object, defautl value is QDateTime::currentDateTime()
     */
    void runTimer(QDateTime = QDateTime::currentDateTime());

signals:

public slots:
    void showReminder();
};

#endif // CYCLICTASKHELPER_H
