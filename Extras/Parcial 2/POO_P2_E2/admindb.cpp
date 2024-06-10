// admindb.cpp
#include "admindb.h"
#include <QSqlQuery>
#include <QSqlError>

AdminDB::AdminDB(const QString &path, QObject *parent) : QObject(parent), m_path(path)
{
    conectar();
}

bool AdminDB::conectar()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    m_database.setDatabaseName(m_path);
    if (!m_database.open())
    {
        qDebug() << "Error al abrir la base de datos:" << m_database.lastError().text();
        return false;
    }
    return true;
}

void AdminDB::desconectar()
{
    if (estaConectado()) {
        m_database.close();
    }
}

bool AdminDB::estaConectado()
{
    return m_database.isOpen();
}

bool AdminDB::verificarCredenciales(const QString& usuario, const QString& clave)
{
    if (!estaConectado())
    {
        qDebug() << "No se puede verificar las credenciales: Base de datos no conectada";
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM usuarios WHERE nombre_usuario = :usuario AND clave = :clave");
    query.bindValue(":usuario", usuario);
    query.bindValue(":clave", clave);
    if (!query.exec()) {
        qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        return false;
    }

    query.next();
    int count = query.value(0).toInt();
    return (count > 0);
}
