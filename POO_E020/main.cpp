/*
CONSIGNA:
    -Crear un proyecto Qt Widget Application con un QWidget que sea la clase Ventana
    -Crear una clase Boton que hereda de QWidget
    -Redefinir paintEvent en Boton y usar fillRect para dibujarlo de algún color
    -Definir el siguiente método en Boton:
    -Usar QtDesigner para Ventana y Boton. Es decir, Designer Form Class
    -Definir la enumeración en Boton
    -Abrir el designer de Ventana y agregar 5 botones (objetos de la clase Boton). Promocionarlos
    -Que esta Ventana con botones quede lo más parecido a la siguiente imagen
*/

#include "ventana.h"
#include "boton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Ventana w;
    w.show();
    return a.exec();
}
