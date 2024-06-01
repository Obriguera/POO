<<<<<<< HEAD
#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
     connect(ui->pbConseguirHTML, SIGNAL(pressed()), this, SLOT(slot_mostrar_html()));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::slot_mostrar_html() {
    QString url = ui->leLink->text();

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply){
        if(reply->error() == QNetworkReply::NoError) {
            QString html = reply->readAll();
            ui->teMostrarCodigo->setPlainText(html);
        } else {
            qDebug() << "Error al obtener la respuesta:" << reply->errorString();
        }
        reply->deleteLater();
    });

    QNetworkRequest request(url);
    manager->get(request);
}

=======
#include "ventana.h"
#include "ui_ventana.h"

Ventana::Ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Ventana)
{
    ui->setupUi(this);
     connect(ui->pbConseguirHTML, SIGNAL(pressed()), this, SLOT(slot_mostrar_html()));
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::slot_mostrar_html() {
    QString url = ui->leLink->text();

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, &QNetworkAccessManager::finished, [=](QNetworkReply *reply){
        if(reply->error() == QNetworkReply::NoError) {
            QString html = reply->readAll();
            ui->teMostrarCodigo->setPlainText(html);
        } else {
            qDebug() << "Error al obtener la respuesta:" << reply->errorString();
        }
        reply->deleteLater();
    });

    QNetworkRequest request(url);
    manager->get(request);
}

>>>>>>> c0a71fc (01 06 24 update)
