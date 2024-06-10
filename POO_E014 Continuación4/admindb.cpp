
#include "admindb.h"

#include <QSqlQuery>
#include <QVariant>
#include <QDebug>
#include <QSqlRecord>

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase( "QSQLITE" );
}


bool AdminDB::conectar( QString archivoSqlite )  {
    db.setDatabaseName( archivoSqlite );

    if( db.open() )
        return true;

    return false;
}

QSqlDatabase AdminDB::getDB()  {
    return db;
}
/*
QStringList AdminDB::validarUsuario( QString tabla, QString usuario, QString clave )  {

    QStringList datosPersonales;

    if ( ! db.isOpen() )
        return datosPersonales;

    QSqlQuery * query = new QSqlQuery( db );
    QString claveMd5 = QCryptographicHash::hash( clave.toUtf8(),
                                                 QCryptographicHash::Md5 ).toHex();

    query->exec( "SELECT nombre, apellido FROM " +
                 tabla + " WHERE usuario = '" + usuario +
                 "' AND clave = '" + claveMd5 + "'" );

    while( query->next() )
    {
        QSqlRecord registro = query->record();

        datosPersonales << query->value( registro.indexOf( "nombre" ) ).toString();
        datosPersonales << query->value( registro.indexOf( "apellido" ) ).toString();
    }

    return datosPersonales;
}
*/

bool AdminDB::validarUsuario(QString tabla, QString usuario, QString clave)
{
    if ( db.open() )  {
        QSqlQuery query = db.exec( "SELECT nombre, apellido FROM " + tabla + " WHERE usuario = '" + usuario + "' AND clave = '" + clave + "'" );

        while( query.next() )
        {
            qDebug() << query.value( 0 ).toString() << " " << query.value( 1 ).toString();
            return true;
        }
    }
    return false;
}





