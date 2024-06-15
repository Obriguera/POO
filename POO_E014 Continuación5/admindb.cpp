#include "admindb.h"
#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

bool AdminDB::conectar(QString archivoSqlite) {
    db.setDatabaseName(archivoSqlite);

    if (db.open())
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB() {
    return db;
}

QStringList AdminDB::validarUsuario(QString tabla, QString usuario, QString clave) {
    QStringList datosPersonales;

    if (!db.isOpen())
        return datosPersonales;

    QSqlQuery query(db);
    QString claveMd5 = QCryptographicHash::hash(clave.toUtf8(), QCryptographicHash::Md5).toHex();

    query.exec("SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" + usuario + "' AND clave = '" + claveMd5 + "'");

    while (query.next()) {
        QSqlRecord registro = query.record();

        datosPersonales << query.value(registro.indexOf("nombre")).toString();
        datosPersonales << query.value(registro.indexOf("apellido")).toString();
    }

    return datosPersonales;
}


QVector<QStringList> AdminDB::select(QString comando) {
    QVector<QStringList> resultados;

    if (!db.isOpen())
        return resultados;

    QSqlQuery query(db);
    query.exec(comando);

    while (query.next()) {
        QSqlRecord registro = query.record();
        QStringList fila;
        for (int i = 0; i < registro.count(); ++i) {
            fila << query.value(i).toString();
        }
        resultados.append(fila);
    }

    return resultados;
}
