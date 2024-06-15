#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>
#include "ventana.h"
#include "admindb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Login; }
QT_END_NAMESPACE

class Login : public QWidget
{
    Q_OBJECT

public:
    Login(QWidget *parent = nullptr);
    ~Login();

protected:
    void paintEvent(QPaintEvent *event) override;

signals:
    void signal_usuarioValidado(QString usuario);

private:
    Ui::Login *ui;
    Ventana *ventana;
    AdminDB *adminDB;
    QNetworkAccessManager manager;
    QImage imagenFondo;
    bool imagenFondoDownloaded;
    int failedAttempts;
    QTimer lockoutTimer;

private slots:
    void resetFailedAttempts();
    void toggleTempNum();
    void obtenerTemperatura();
    void obtenerImagenFondo(const QString &imageUrl);
    void slot_descargaFinalizada(QNetworkReply *reply);
    void slot_validarUsuario();
};

#endif // LOGIN_H
