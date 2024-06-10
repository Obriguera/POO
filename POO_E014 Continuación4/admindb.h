
#ifndef ADMINDB_H
#define ADMINDB_H

// "mabuelo"      "1234"
#include <QObject>
#include <QSqlDatabase>
#include <QString>
#include <QCryptographicHash>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);

    bool conectar( QString archivoSqlite );
    QSqlDatabase getDB();

   bool validarUsuario( QString tabla, QString usuario, QString clave );

    //QStringList validarUsuario( QString tabla, QString usuario, QString clave );
private:
    QSqlDatabase db;

};

#endif // ADMINDB_H
