<<<<<<< HEAD
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear un QLabel
    QLabel label;

    // Cargar la imagen desde un archivo JPG
    QPixmap imagen("/vegetto.jpg");

    // Escalar la imagen para ajustarse al tamaño del QLabel sin deformación
    imagen = imagen.scaled(label.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Establecer la imagen en el QLabel
    label.setPixmap(imagen);

    // Mostrar el QLabel de forma maximizada
    label.showMaximized();

    // Configurar un temporizador para cerrar la aplicación después de 3 segundos
    QTimer::singleShot(3000, &app, SLOT(quit()));

    return app.exec();
}
=======
/*
CONSIGNAS
    -En un Empty qmake Project
    -En la función main crear un objeto de la clase QLabel y pegarle en el mismo objeto QLabel una imagen de alta resolución.
    -Que la imagen se obtenga desde un archivo JPG del disco duro
    -Mostrar el QLabel de forma maximizada y que la imagen no se deforme.
    -Al cabo de 3 segundos, el QLabel y la aplicación se deberá cerrar
*/

#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Crear un QLabel
    QLabel label;

    // Cargar la imagen desde un archivo JPG
    QPixmap imagen("/vegetto.jpg");

    // Escalar la imagen para ajustarse al tamaño del QLabel sin deformación
    imagen = imagen.scaled(label.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);

    // Establecer la imagen en el QLabel
    label.setPixmap(imagen);

    // Mostrar el QLabel de forma maximizada
    label.showMaximized();

    // Configurar un temporizador para cerrar la aplicación después de 3 segundos
    QTimer::singleShot(3000, &app, SLOT(quit()));

    return app.exec();
}
>>>>>>> c0a71fc (01 06 24 update)
