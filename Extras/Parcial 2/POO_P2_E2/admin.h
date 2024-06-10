#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include "login.h"
#include "ventana.h"
#include "admindb.h"

class Admin : public QObject
{
    Q_OBJECT
public:
    explicit Admin(QObject *parent = nullptr);
    void iniciar();

private slots:
    void usuarioValidado();

private:
    Login *login;
    Ventana *ventana;
    AdminDB *adminDB;
};

#endif // ADMIN_H
