#include "admindb.h"
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

QSqlDatabase AdminDB::db = QSqlDatabase::addDatabase("QSQLITE");

QSqlDatabase& AdminDB::getInstance()
{
    if (!db.isOpen()) {
        db.setDatabaseName("C:/Qt/db/rectangles.sqlite");  // Especificar la ruta completa de la base de datos
        if (!db.open()) {
            qDebug() << "Error: Unable to connect to database." << db.lastError();
        } else {
            qDebug() << "Database connected successfully.";
        }
    }
    return db;
}

void AdminDB::close()
{
    if (db.isOpen()) {
        db.close();
    }
}
