#include "login.h"
#include "ui_login.h"

Login::Login(AdminDB *adminDB, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login),
    adminDB(adminDB)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_pbLogin_clicked()
{
    QString usuario = ui->leUser->text();
    QString clave = ui->leClave->text();

    if (adminDB->verificarCredenciales(usuario, clave)) {
        emit signal_usuarioValidado();
    } else {
        qDebug() << "Credenciales incorrectas";
        // Aquí podrías mostrar un mensaje de error al usuario
    }
}
