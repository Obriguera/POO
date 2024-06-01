#include "admindb.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool AdminDB::conectar(QString archivoSqlite)
{
    db.setDatabaseName(archivoSqlite);

    return db.open();
}

QSqlDatabase AdminDB::getDB()
{
    return db;
}

bool AdminDB::validarUsuario(QString tabla, QString usuario, QString clave)
{
    if (db.isOpen()) {
        QSqlQuery query;
        query.prepare("SELECT nombre, apellido FROM " + tabla + " WHERE usuario = :usuario AND clave = :clave");
        query.bindValue(":usuario", usuario);
        query.bindValue(":clave", clave);

        if (query.exec() && query.next()) {
            qDebug() << query.value(0).toString() << " " << query.value(1).toString();
            return true;
        }
    }
    return false;
}
