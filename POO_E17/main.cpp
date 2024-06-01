<<<<<<< HEAD
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Login login;
    login.show();

    return a.exec();
}
=======
/*
CONSIGNA:
    -Diseñar un login que cargue como fondo, una imagen descargada de internet
    -Cuando un usuario sea válido, que se abra en full screen otra ventana (definida en la clase Ventana) y que tenga otra imagen descargada de internet en su interior, abarcando toda la ventana.
    -Esta ventana no deberá abrirse hasta tanto se haya descargado la imagen.
    -La imagen no se debe deformar al visualizarse.
*/

#include <QApplication>
#include "login.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Login login;
    login.show();

    return a.exec();
}
>>>>>>> c0a71fc (01 06 24 update)
