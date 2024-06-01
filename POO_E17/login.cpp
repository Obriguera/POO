// login.cpp

#include "login.h"

#include <QDebug>
#include <QPainter>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

Login::Login(QWidget *parent) : QWidget(parent) {
    setWindowTitle("Login");

    // Crear los elementos de la interfaz
    lUsuario = new QLabel("Usuario:");
    lClave = new QLabel("Clave:");
    leUsuario = new QLineEdit();
    leClave = new QLineEdit();
    leClave->setEchoMode(QLineEdit::Password);
    pbIngresar = new QPushButton("Ingresar");

    // Crear el layout y añadir los elementos
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->addWidget(lUsuario, 0, 0);
    gridLayout->addWidget(leUsuario, 0, 1, 1, 2);
    gridLayout->addWidget(lClave, 1, 0);
    gridLayout->addWidget(leClave, 1, 1, 1, 2);
    gridLayout->addWidget(pbIngresar, 2, 1, 1, 1);

    // Conectar el clic del botón al slot_validarUsuario
    connect(pbIngresar, SIGNAL(pressed()), this, SLOT(slot_validarUsuario()));

    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(slot_descargaFinalizada(QNetworkReply*)));

    // Descargar la imagen de fondo para el login
    QUrl url("https://miielts.com/wp-content/uploads/2019/11/NZ-2-1200x800.jpg");
    QNetworkRequest request(url);
    manager->get(request);
}


//// DEFINICIONES DE FUNCIONES ////

void Login::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    if (!imagenFondo.isNull()) {
        painter.drawPixmap(0, 0, width(), height(), imagenFondo);
    }
    // Dibujar otros elementos sobre la imagen de fondo...
}

void Login::slot_validarUsuario() {
    if (leUsuario->text() == "admin" && leClave->text() == "1234")
    {
        qDebug() << "Usuario válido";

        // Descargar la segunda imagen
        QUrl url("https://cadenaser.com/resizer/V-yainfi6WrSpqf9K6_Vs5swd6s=/736x414/filters:format(jpg):quality(70)/cloudfront-eu-central-1.images.arcpublishing.com/prisaradio/4CH6HJSDMRJNLHRH4B6DTJP37U.jpg");
        QNetworkRequest request(url);
        manager->get(request);
    }
    else
    {
        qDebug() << "Usuario Inválido";
        leClave->clear();
    }
}


void Login::slot_descargaFinalizada(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError)
    {
        if (reply->url().toString() == "https://miielts.com/wp-content/uploads/2019/11/NZ-2-1200x800.jpg")
        {
            imagenFondo.loadFromData(reply->readAll());
            update();
        }
        else if (reply->url().toString() == "https://cadenaser.com/resizer/V-yainfi6WrSpqf9K6_Vs5swd6s=/736x414/filters:format(jpg):quality(70)/cloudfront-eu-central-1.images.arcpublishing.com/prisaradio/4CH6HJSDMRJNLHRH4B6DTJP37U.jpg")
        {
            QPixmap imagenVentana;
            imagenVentana.loadFromData(reply->readAll());

            // Crear la segunda ventana
            Ventana *ventana = new Ventana(imagenVentana);
            ventana->showFullScreen();
        }
    }
    else
    {
        qDebug() << "Error al obtener la respuesta:" << reply->errorString();
    }
    reply->deleteLater();
}
