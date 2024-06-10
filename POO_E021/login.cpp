#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);

    connect(ui->loginButton, &QPushButton::clicked, this, &Login::on_loginButton_clicked);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    QString username = ui->leUsuario->text();
    QString password = ui->leClave->text();
    emit credentialsEntered(username, password);
}
