// acceso.cpp
#include "ui_acceso.h"
#include "QDebug"
#include "acceso.h"
#include <QPainter>

Acceso::Acceso(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Acceso),
    ventana( new class ventana ),
    manager( new QNetworkAccessManager( this ) )


{
    ui->setupUi(this);

    ui->leUsuario->setFocus();

    //Conexiones de los botones
    connect(ui->pbIngresar, SIGNAL(clicked()), this, SLOT(slot_validar()));
    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validar()));



    connect( manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargaFinalizada(QNetworkReply*)));
    QString sUrl = "https://media.istockphoto.com/id/1312444511/es/v%C3%ADdeo/fondo-colorido-rosa-amarillo-y-azul-en-v%C3%ADdeo-4k.jpg?b=1&s=640x640&k=20&c=uQK_P0Tpf2QD8hp0CV2ViJEXTb6m9adEC27rD8aafR0=";
    manager->get( QNetworkRequest( QUrl( sUrl ) ) );

    //Tamaño máximo de la ventana
    setMaximumSize(400,200);
}

Acceso::~Acceso()
{
    delete ui;
}

int intentos = 0; //Variable para hacer el seguimiento de la cantidad de intentos
void Acceso::slot_validar()
{
    // Verificar cantidad de intentos
    if (intentos >= 2)
    {
        this->close();
        return;
    }

    // Verificar el tipo de usuario y procesar
    if (ui->leUsuario->text() == "admin" && ui->leClave->text() == "1234")
    {
        qDebug() << "Bienvenido Administrador";
        this->hide();
        ventana->es_admin = true;
        ventana->show();
    }
    else if(ui->leUsuario->text() == "user" && ui->leClave->text() == "4321")
    {
        qDebug() << "Bienvenido Usuario";
        this->hide();
        ventana->es_admin = false;
        ventana->show();
    }
    else
    {
        ui->leClave->clear();
        intentos++;
    }
}

void Acceso::paintEvent(QPaintEvent *)
{
    QPainter painter( this );

    if ( ! im.isNull() )
        painter.drawImage( 0, 0, im.scaled( this->width(), this->height() ) );

}

void Acceso::slot_descargaFinalizada(QNetworkReply *reply)
{
    im = QImage::fromData( reply->readAll() );
    this->repaint();
}
