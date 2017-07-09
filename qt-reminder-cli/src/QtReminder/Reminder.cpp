#include <QtReminder/Reminder.h>

using namespace std;

namespace QtReminder
{

Reminder::Reminder(QDateTime &run_time, const shared_ptr<string> title, const shared_ptr<string> description):
    run_time{run_time}, title{title}, description{description}, created(QDateTime::currentDateTimeUtc())
{}

Reminder::Reminder(QDateTime &run_time, const shared_ptr<string> title, const shared_ptr<string> description,
                   QDateTime &created):
    run_time{run_time}, title{title}, description{description}, created{created}
{}

Reminder::Reminder(const Reminder &r):
    run_time{r.run_time}, title{r.title}, description{r.description},  created{r.created}
{}

} // namespace QtReminder
