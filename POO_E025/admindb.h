#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QString>
#include <QVector>

class AdminDB
{
public:
    static QSqlDatabase& getInstance();
    static void close();

    static bool addUser(const QString& username, const QString& password);
    static bool validateUser(const QString& username, const QString& password);
    static QVector<QVector<QString>> getAllUsers();

private:
    AdminDB() = default;
    ~AdminDB() = default;
    AdminDB(const AdminDB&) = delete;
    AdminDB& operator=(const AdminDB&) = delete;

    static QSqlDatabase db;
};

#endif // ADMINDB_H
