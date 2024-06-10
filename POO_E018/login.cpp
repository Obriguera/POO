<<<<<<< HEAD
#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login( QWidget * parent ) : QWidget( parent ),
                                   ui( new Ui::Login ),
                                   ventana( new Ventana )
{
    ui->setupUi(this);

    ui->leUsuario->setFocus();

    connect(ui->pbValidar, SIGNAL(pressed()), this, SLOT(slot_validar()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validar()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validar()
{
    if ( ui->leUsuario->text() == "admin" && ui->leClave->text() == "1234" )  {
        qDebug() << "Usuario valido";
        this->hide();
        ventana->show();
    }
    else  {
        qDebug() << "Usuario no valido";
        this->close();
    }
}

=======
#include "login.h"
#include "ui_login.h"
#include <QDebug>

Login::Login( QWidget * parent ) : QWidget( parent ),
                                   ui( new Ui::Login ),
                                   ventana( new Ventana )
{
    ui->setupUi(this);

    ui->leUsuario->setFocus();

    connect(ui->pbValidar, SIGNAL(pressed()), this, SLOT(slot_validar()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validar()));
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validar()
{
    if ( ui->leUsuario->text() == "admin" && ui->leClave->text() == "1234" )  {
        qDebug() << "Usuario valido";
        this->hide();
        ventana->show();
    }
    else  {
        qDebug() << "Usuario no valido";
        this->close();
    }
}

>>>>>>> c0a71fc (01 06 24 update)
