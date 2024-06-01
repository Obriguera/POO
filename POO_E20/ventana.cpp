#include "ventana.h"
#include "ui_ventana.h"
#include "boton.h"
#include <QPainter>
#include <QDebug>
#include <QNetworkRequest>
#include <QUrl>

Ventana::Ventana(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Ventana)
{
    ui->setupUi(this);

    // Conectar la señal signal_clic() de cada botón al slot handleButtonClick()
    connect(findChild<Boton*>("pushButton"), &Boton::signal_clic, this, &Ventana::handleButtonClick);
    connect(findChild<Boton*>("pushButton_2"), &Boton::signal_clic, this, &Ventana::handleButtonClick);
    connect(findChild<Boton*>("pushButton_3"), &Boton::signal_clic, this, &Ventana::handleButtonClick);
    connect(findChild<Boton*>("pushButton_4"), &Boton::signal_clic, this, &Ventana::handleButtonClick);
    connect(findChild<Boton*>("pushButton_5"), &Boton::signal_clic, this, &Ventana::handleButtonClick);

    // Inicializar QNetworkAccessManager
    networkManager = new QNetworkAccessManager(this);

    // Conectar la señal de finalización de la descarga al slot correspondiente
    connect(networkManager, &QNetworkAccessManager::finished, this, &Ventana::onImageDownloaded);

    // Solicitar la imagen desde internet
    QUrl imageUrl("https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcRF1IwK6-SxM83UpFVY6WtUZxXx-phss_gAUfdKbkTfau6VWVkt");  // Reemplaza con la URL de tu imagen
    QNetworkRequest request(imageUrl);
    networkManager->get(request);
}

Ventana::~Ventana()
{
    delete ui;
}

void Ventana::handleButtonClick()
{
    // Aquí puedes manejar el evento de clic del botón como desees
    qDebug() << "Botón clicado";
}

void Ventana::onImageDownloaded(QNetworkReply* reply)
{
    if(reply->error() == QNetworkReply::NoError) {
        QByteArray imageData = reply->readAll();
        backgroundImage.loadFromData(imageData);
        update();  // Fuerza la actualización del widget para repintar el fondo con la imagen descargada
    } else {
        qDebug() << "Error descargando la imagen:" << reply->errorString();
    }
    reply->deleteLater();
}

void Ventana::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    QPainter painter(this);

    if (!backgroundImage.isNull()) {
        painter.drawImage(rect(), backgroundImage);
    } else {
        // Dibujar un fondo de color sólido si la imagen no está disponible
        painter.fillRect(rect(), Qt::white);
    }
}
