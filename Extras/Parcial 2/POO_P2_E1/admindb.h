#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>

class AdminDB
{
public:
    static QSqlDatabase& getInstance();
    static void close();

private:
    AdminDB() = default;
    ~AdminDB() = default;
    AdminDB(const AdminDB&) = delete;
    AdminDB& operator=(const AdminDB&) = delete;

    static QSqlDatabase db;
};

#endif // ADMINDB_H
