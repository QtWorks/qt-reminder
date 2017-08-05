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
    QDateTime tmp_created{r.created};
    QDateTime tmp_run_time{r.run_time};

    this->created.swap(tmp_created);
    this->run_time.swap(tmp_run_time);
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

Reminder& Reminder::operator =(const Reminder &r)
{
    QDateTime tmp_run_time{r.run_time};
    QDateTime tmp_created{r.created};

    this->created.swap(tmp_created);
    this->cyclic = r.cyclic;
    this->description = r.description;
    this->reminder_id = r.reminder_id;
    this->run_time.swap(tmp_run_time);
    this->title = r.title;
    return *this;
}

QUuid Reminder::getReminderId()
{
    return this->reminder_id;
}

Reminder::~Reminder() {}

} // namespace QtReminder
