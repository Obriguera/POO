#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QCryptographicHash>
#include <QVector>
#include <QStringList>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);

    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();
    QStringList validarUsuario( QString tabla, QString usuario, QString clave );
    QVector< QStringList > select( QString comando );

private:
    QSqlDatabase db;
};

#endif // ADMINDB_H
