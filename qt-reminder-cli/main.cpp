#include <QCoreApplication>
#include <iostream>
#include <QtReminder/DatabaseManager.h>

using QtReminder::DatabaseManager;
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DatabaseManager::get_instance();

    return a.exec();
}

