// admindb.h
#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QString>
#include <QSqlDatabase>
#include <QDebug>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB(const QString& path, QObject *parent = nullptr);
    bool conectar();
    void desconectar();
    bool estaConectado();
    bool verificarCredenciales(const QString& usuario, const QString& clave);

private:
    QString m_path;
    QSqlDatabase m_database;
};

#endif // ADMINDB_H
