#include "admin.h"

Admin::Admin(QObject *parent) : QObject(parent)
{
    adminDB = new AdminDB("./base_poo.sqlite"); // Conectando a la base de datos
    login = new Login(adminDB);
    ventana = new Ventana();
    connect(login, &Login::signal_usuarioValidado, this, &Admin::usuarioValidado);
}

void Admin::iniciar()
{
    login->show();
}

void Admin::usuarioValidado()
{
    login->hide();
    ventana->show();
}
