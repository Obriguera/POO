#include "ventana.h"
#include "ui_ventana.h"

ventana::ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ventana)
{
    ui->setupUi(this);
    slot_bienvenido();
}

ventana::~ventana()
{
    delete ui;
}

//Método para determinar el tipo de usuario
void ventana::slot_bienvenido()
{
    if(this->es_admin)
    {
        ui->lBienvenida->setText("Hola admin");
    }
    else
    {
        ui->lBienvenida->setText("Hola user");
    }
}
