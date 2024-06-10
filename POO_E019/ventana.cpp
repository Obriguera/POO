<<<<<<< HEAD
#include "ventana.h"
#include "ui_ventana.h"
#include "pintura.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    Pintura *pintura = new Pintura(this); // Instanciar el widget Pintura
    setCentralWidget(pintura); // Establecer Pintura como widget central
}

Ventana::~Ventana()
{
    delete ui;
}
=======
#include "ventana.h"
#include "ui_ventana.h"
#include "pintura.h"

Ventana::Ventana(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);

    Pintura *pintura = new Pintura(this); // Instanciar el widget Pintura
    setCentralWidget(pintura); // Establecer Pintura como widget central
}

Ventana::~Ventana()
{
    delete ui;
}
>>>>>>> c0a71fc (01 06 24 update)
