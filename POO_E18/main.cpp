<<<<<<< HEAD
#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}
=======
/*
CONSIGNA:
    -Utilizar un proyecto con un login cualquiera que valide admin:1234
    -Cuando el usuario es válido, abrir una nueva ventana que tenga un QTextEdit que permita mostrar código HTML.
    -Esta ventana deberá tener un QLineEdit que permita ingresar una URL
    -Cuando se pulse Enter, se deberá buscar el html de la URL escrita y se deberá publicar en el QTextEdit.
*/

#include "login.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login w;
    w.show();
    return a.exec();
}
>>>>>>> c0a71fc (01 06 24 update)
