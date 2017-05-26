#include <QtReminder/DatabaseManager.h>

namespace QtReminder
{

DatabaseManager::DatabaseManager(const QString path="."): db{QSqlDatabase::addDatabase("QSQLITE")}
{
    this->db.setDatabaseName(this->db_name);
    if (!this->db.open())
    {
        throw db.lastError();
    }
}

DatabaseManager::~DatabaseManager()
{

}

DatabaseManager& DatabaseManager::get_instance()
{
    static DatabaseManager db_manager;

    return db_manager;
}

} // namespace QtReminder
