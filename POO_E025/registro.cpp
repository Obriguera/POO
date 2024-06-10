#include "registro.h"
#include "ui_registro.h"
#include "admindb.h"
#include <QMessageBox>

Registro::Registro(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registro) {
    ui->setupUi(this);
}

Registro::~Registro() {
    delete ui;
}

void Registro::on_registerButton_clicked() {
    QString username = ui->leUser->text();
    QString password = ui->leClave->text();

    if (AdminDB::addUser(username, password)) {
        QMessageBox::information(this, "Registration Successful", "User has been registered successfully");
        this->close();
    } else {
        QMessageBox::warning(this, "Registration Failed", "Could not register user");
    }
}
