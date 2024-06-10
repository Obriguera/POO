#include "login.h"
#include "ui_login.h"
#include "admindb.h"
#include "lista.h"
#include "QMessageBox"
#include "registro.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    connect(ui->registerLabel, &QLabel::clicked, this, &Login::on_registerLabel_clicked);
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

void Login::on_registerLabel_clicked() {
    Registro *registerWindow = new Registro(this);
    registerWindow->show();
}
