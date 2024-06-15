#include "login.h"
#include "ui_login.h"
#include <QDebug>
#include <QPainter>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
    , imagenFondoDownloaded(false)
    , failedAttempts(0)
{
    ui->setupUi(this);

    ventana = new Ventana;

    connect(ui->leClave, SIGNAL(returnPressed()), this, SLOT(slot_validarUsuario()));

    adminDB = new AdminDB(this);
    qDebug() << "¿La base se abrió? " << adminDB->conectar("C:/Qt/db/db.sqlite");

    // Configuración para obtener la temperatura y la imagen de fondo
    connect(&manager, &QNetworkAccessManager::finished, this, &Login::slot_descargaFinalizada);
    obtenerTemperatura();
    obtenerImagenFondo("https://miielts.com/wp-content/uploads/2019/11/NZ-2-1200x800.jpg");

    // Agregar botón y funcionalidad para mostrar/ocultar temperatura
    connect(ui->hideTemp, &QPushButton::clicked, this, &Login::toggleTempNum);
}

Login::~Login()
{
    delete ui;
}

void Login::resetFailedAttempts()
{
    ui->leClave->setEnabled(true);
    failedAttempts = 0;
}

void Login::toggleTempNum()
{
    if (ui->lTemp->isVisible()) {
        ui->lTemp->hide();
        ui->hideTemp->setText("Mostrar");
    } else {
        ui->lTemp->show();
        ui->hideTemp->setText("Ocultar");
    }
}

void Login::obtenerTemperatura()
{
    manager.get(QNetworkRequest(QUrl("http://api.openweathermap.org/data/2.5/weather?q=Cordoba&appid=7f63e534bedc6a1a5330982f6812ab10")));
}

void Login::obtenerImagenFondo(const QString &imageUrl)
{
    manager.get(QNetworkRequest(QUrl(imageUrl)));
}

void Login::slot_descargaFinalizada(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        if (reply->url().toString().contains("openweathermap")) {
            QJsonDocument jsonResponse = QJsonDocument::fromJson(reply->readAll());
            QJsonObject jsonObject = jsonResponse.object();
            double temperatura = jsonObject["main"].toObject()["temp"].toDouble() - 273.15; // Convertir de Kelvin a Celsius
            ui->lTemp->setText(QString(" %1 °C").arg(temperatura));
        } else {
            QByteArray imageData = reply->readAll();
            imagenFondo.loadFromData(imageData);
            imagenFondoDownloaded = true;
            update();
        }
    } else {
        qDebug() << "Error al obtener la respuesta:" << reply->errorString();
    }
    reply->deleteLater();
}

void Login::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    if (!imagenFondo.isNull() && imagenFondoDownloaded) {
        painter.drawImage(0, 0, imagenFondo.scaled(size())); // Escalar la imagen al tamaño del widget
    }
    QWidget::paintEvent(event);
}

void Login::slot_validarUsuario()
{
    QString usuario = ui->lUsuario->text();
    QString clave = ui->leClave->text();

    if (!usuario.isEmpty() && !clave.isEmpty()) {
        QStringList datosPersonales = adminDB->validarUsuario("usuarios", usuario, clave);

        if (!datosPersonales.isEmpty()) {
            emit signal_usuarioValidado(usuario);
            ventana->show();
            this->close();
        } else {
            qDebug() << "Usuario Inválido";
            failedAttempts++;
            if (failedAttempts >= 3) {
                ui->leClave->setEnabled(false);
                QTimer::singleShot(30000, this, &Login::resetFailedAttempts); // Bloquear por 30 segundos
            }
        }
    } else {
        qDebug() << "Usuario o clave vacíos";
    }
}
