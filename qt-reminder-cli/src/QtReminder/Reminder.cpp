#include <QtReminder/Reminder.h>

using namespace std;

namespace QtReminder
{

Reminder::Reminder(QDateTime &run_time, const shared_ptr<wstring> title, const shared_ptr<wstring> description):
    title{title}, description{description}
{
    this->run_time.swap(run_time);
}

Reminder::Reminder(QDateTime &run_time, const shared_ptr<wstring> title, const shared_ptr<wstring> description,
                   QDateTime &created):
    title{title}, description{description}
{
    this->run_time.swap(run_time);
    this->created.swap(created);
}

Reminder::Reminder(const Reminder &r):
    title{r.title}, description{r.description}
{
    this->run_time.swap(run_time);
    this->created.swap(created);
}

} // namespace QtReminder
