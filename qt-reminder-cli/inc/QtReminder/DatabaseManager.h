/**
  * @author: Damian Giebas (Draqun)
  * @date: 12.05.2017
  * @version: 1.0
  */

#ifndef DATABASEMANAGER
#define DATABASEMANAGER

#include <QtSql>
#include <memory>

namespace QtReminder
{
/**
 * @brief The DatabaseManager class too handling connection to database
 */
class DatabaseManager
{
    /// Qt database object
    QSqlDatabase db;

    /// Program database name
    QString db_name {"notification_db.sqlite"};

    /**
     * @brief DatabaseManager - Ctor
     * @param path - Path to database file
     */
    DatabaseManager(const QString);

    DatabaseManager(DatabaseManager const&) = delete;
    DatabaseManager(DatabaseManager &&) = delete;
    DatabaseManager& operator=(DatabaseManager const &) = delete;
    DatabaseManager& operator=(DatabaseManager &&) = delete;


public:
    /**
     * @brief get_instance - static function to get DatabaseManager instance
     * @return - Reference to DatabaseManager instance
     */
    static DatabaseManager& get_instance();
    ~DatabaseManager();
};

} // namespace QtReminder

#endif // DATABASEMANAGER

