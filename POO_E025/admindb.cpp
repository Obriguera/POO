#include "admindb.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>

QSqlDatabase AdminDB::db = QSqlDatabase::addDatabase("QSQLITE");

QSqlDatabase& AdminDB::getInstance() {
    if (!db.isOpen()) {
        db.setDatabaseName("C:/Qt/db/Usuarios.sqlite");
        if (!db.open()) {
            qDebug() << "Error: connection with database failed";
        } else {
            qDebug() << "Database: connection ok";
        }
    }
    return db;
}

void AdminDB::close() {
    if (db.isOpen()) {
        db.close();
    }
}

bool AdminDB::addUser(const QString& username, const QString& password) {
    QSqlQuery query(getInstance());
    query.prepare("INSERT INTO Usuarios (nombre_usuario, contrasena) VALUES (:username, :password)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "addUser error: " << query.lastError();
        return false;
    }
    return true;
}

bool AdminDB::validateUser(const QString& username, const QString& password) {
    QSqlQuery query(getInstance());
    query.prepare("SELECT * FROM Usuarios WHERE nombre_usuario = :username AND contrasena = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    if (!query.exec()) {
        qDebug() << "validateUser error: " << query.lastError();
        return false;
    }
    return query.next();
}

QVector<QVector<QString>> AdminDB::getAllUsers() {
    QVector<QVector<QString>> users;
    QSqlQuery query(getInstance());
    query.prepare("SELECT ID, nombre_usuario, contrasena FROM Usuarios");
    if (!query.exec()) {
        qDebug() << "getAllUsers error: " << query.lastError();
        return users;
    }
    while (query.next()) {
        QVector<QString> user;
        user.append(query.value(0).toString());
        user.append(query.value(1).toString());
        user.append(query.value(2).toString());
        users.append(user);
    }
    return users;
}
