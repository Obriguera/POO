/*
Consigna:
    -Definir dos QWidgets (una clase Login y una clase Ventana).
    -El Login validará al usuario contra una base SQLite
    -La Ventana sólo mostrará un QPushButton para "Volver" al login.
    -Crear solamente un objeto de Ventana y uno solo de Login.
    -Si sucede un problema en la compilación, analizar los motivos (respetar el enunciado).
    -Solucionar ese problema y ver la alternativa de hacerlo con Manager.
*/

#include <QApplication>
#include "manager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Manager manager;

    return app.exec();
}
