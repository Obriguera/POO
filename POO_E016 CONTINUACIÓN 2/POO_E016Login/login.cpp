#include "login.h"
#include "ui_login.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Login::onReplyFinished);
}

Login::~Login()
{
    delete ui;
}

void Login::on_loginButton_clicked()
{
    QString usuario = ui->usernameLineEdit->text();
    QString clave = ui->passwordLineEdit->text();

    QJsonObject json;
    json["usuario"] = usuario;
    json["clave"] = clave;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QNetworkRequest request(QUrl("http://127.0.0.1:8000/validar_usuario/"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    networkManager->post(request, data);
}

void Login::onReplyFinished(QNetworkReply* reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response_data = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(response_data);
        QJsonObject jsonObj = jsonDoc.object();

        if (jsonObj.contains("mensaje") && jsonObj["mensaje"] == "Acceso concedido") {
            QString usuario = jsonObj["usuario"].toString();
            QMessageBox::information(this, "Login Successful", "Bienvenido " + usuario);
        } else {
            QMessageBox::warning(this, "Login Failed", "Acceso denegado");
        }
    } else {
        QMessageBox::critical(this, "Error", reply->errorString());
    }
    reply->deleteLater();
}
