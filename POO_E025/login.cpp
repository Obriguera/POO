// login.cpp
#include "login.h"
#include "ui_login.h"
#include "registro.h"
#include "QMessageBox"
#include "admindb.h"
#include "lista.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->lregistrar, &QPushButton::clicked, this, &Login::on_lregistrar_clicked);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked() {
    QString username = ui->leUsuario->text();
    QString password = ui->leClave->text();

    if (AdminDB::validateUser(username, password)) {
        Lista *userListWindow = new Lista(this);
        userListWindow->show();
        this->hide();
    } else {
        QMessageBox::warning(this, "Login Failed", "Invalid username or password");
    }
}

void Login::on_lregistrar_clicked() {
    Registro *registerWindow = new Registro(this);
    registerWindow->show();
}
