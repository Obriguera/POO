<<<<<<< HEAD
#include <QApplication>
#include "pintura.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Pintura pintura;
    pintura.show();
    return a.exec();
}
=======
/*
CONSIGNA:
    -Crear una clase Pintura que herede de QWidget y que permita dibujar a mano alzada con el mouse.
    -Con el scroll permitirá ampliar y disminuir el tamaño del trazo del pincel.
    -Con las teclas R, G y B se cambia el color del pincel.
    -Con Escape se borra todo lo que esté dibujado.
*/

#include <QApplication>
#include "pintura.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Pintura pintura;
    pintura.show();
    return a.exec();
}
>>>>>>> c0a71fc (01 06 24 update)
