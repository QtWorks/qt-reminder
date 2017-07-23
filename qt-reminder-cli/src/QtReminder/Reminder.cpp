#include <QtReminder/Reminder.h>

using namespace std;

namespace QtReminder
{

Reminder::Reminder(QDateTime &run_time, const shared_ptr<wstring> title, const shared_ptr<wstring> description,
                   bool cyclic):
    title{title}, description{description}, cyclic{cyclic}
{
    this->run_time.swap(run_time);
}

Reminder::Reminder(QDateTime &run_time, const shared_ptr<wstring> title, const shared_ptr<wstring> description,
                   QDateTime &created, bool cyclic):
    title{title}, description{description}, cyclic{cyclic}
{
    this->run_time.swap(run_time);
    this->created.swap(created);
}

Reminder::Reminder(const Reminder &r):
    title{r.title}, description{r.description}, reminder_id{r.reminder_id}, cyclic{r.cyclic}
{
    this->run_time.swap(run_time);
    this->created.swap(created);
}

std::wstring* Reminder::getTitle()
{
    return this->title.get();
}

QDateTime Reminder::getRunTime()
{
    return this->run_time;
}

bool Reminder::isCyclic()
{
    return this->cyclic;
}

} // namespace QtReminder
