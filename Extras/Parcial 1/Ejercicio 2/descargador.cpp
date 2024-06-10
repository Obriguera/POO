#include "descargador.h"
#include <QHBoxLayout>
#include <QPainter>

Descargador::Descargador(QWidget *parent) : QWidget(parent)
{
    iniciarInterfaz();
}

Descargador::~Descargador()
{
    delete urlLineEdit;
    delete descargarButton;
    delete progressBar;
    delete networkManager;
}

void Descargador::iniciarInterfaz()
{
    //link de la imagen a descargar
    urlLineEdit = new QLineEdit("https://images.pexels.com/photos/417074/pexels-photo-417074.jpeg");
    urlLineEdit->setReadOnly(true);

    descargarButton = new QPushButton("Descargar");

    QObject::connect(descargarButton, SIGNAL(clicked()), this, SLOT(descargarImagen()));

    progressBar = new QProgressBar;

    //posicionamiento de los elementos
    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(urlLineEdit, 0, 0, 1, 3);
    layout->addWidget(descargarButton, 0, 3, 1, 1);
    layout->addWidget(progressBar, 1, 0, 1, 4);

    setLayout(layout);

    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Descargador::descargaFinalizada);
}

void Descargador::descargarImagen()
{
    QUrl url(urlLineEdit->text());
    QNetworkRequest request(url);
    QNetworkReply *reply = networkManager->get(request);
    connect(reply, &QNetworkReply::downloadProgress, this, &Descargador::actualizarProgreso);
}

void Descargador::descargaFinalizada(QNetworkReply *reply)
{
    imagen.loadFromData(reply->readAll());
    reply->deleteLater();
    progressBar->setValue(0);
    update();
}

void Descargador::actualizarProgreso(qint64 bytesRecibidos, qint64 bytesTotales)
{
    progressBar->setMaximum(bytesTotales);
    progressBar->setValue(bytesRecibidos);
}

void Descargador::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if (!imagen.isNull())
        painter.drawImage(0, 0, imagen.scaled(size()));
}
