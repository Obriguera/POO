<<<<<<< HEAD
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QImage>
#include <QMainWindow>

// Supongamos que la clase Ventana se define de la siguiente manera:
class Ventana : public QMainWindow {
    Q_OBJECT
public:
    Ventana(const QPixmap &imagen, QWidget *parent = nullptr) : QMainWindow(parent) {
        // Configurar la ventana para ocupar toda la pantalla
        setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        setWindowState(Qt::WindowFullScreen);

        // Mostrar la imagen en la ventana principal
        QLabel *imagenLabel = new QLabel(this);
        imagenLabel->setPixmap(imagen.scaled(this->size(), Qt::KeepAspectRatioByExpanding));
        setCentralWidget(imagenLabel);
    }
};


class Login : public QWidget {
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);

private:
    QLabel *lUsuario;
    QLabel *lClave;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbIngresar;
    QPixmap imagenFondo;
    QNetworkAccessManager *manager;
    Ventana * ventana;

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void slot_validarUsuario();
    void slot_descargaFinalizada(QNetworkReply *reply);
};

#endif // LOGIN_H
=======
#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QImage>
#include <QMainWindow>

// Supongamos que la clase Ventana se define de la siguiente manera:
class Ventana : public QMainWindow {
    Q_OBJECT
public:
    Ventana(const QPixmap &imagen, QWidget *parent = nullptr) : QMainWindow(parent) {
        // Configurar la ventana para ocupar toda la pantalla
        setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        setWindowState(Qt::WindowFullScreen);

        // Mostrar la imagen en la ventana principal
        QLabel *imagenLabel = new QLabel(this);
        imagenLabel->setPixmap(imagen.scaled(this->size(), Qt::KeepAspectRatioByExpanding));
        setCentralWidget(imagenLabel);
    }
};


class Login : public QWidget {
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr);

private:
    QLabel *lUsuario;
    QLabel *lClave;
    QLineEdit *leUsuario;
    QLineEdit *leClave;
    QPushButton *pbIngresar;
    QPixmap imagenFondo;
    QNetworkAccessManager *manager;
    Ventana * ventana;

protected:
    void paintEvent(QPaintEvent *);

private slots:
    void slot_validarUsuario();
    void slot_descargaFinalizada(QNetworkReply *reply);
};

#endif // LOGIN_H
>>>>>>> c0a71fc (01 06 24 update)
