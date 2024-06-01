<<<<<<< HEAD
#include <Windows.h> // Para cargar la DLL en Windows
#include <iostream>
#include "../Saludos/saludos.h"

int main() {
    HINSTANCE hDLL = LoadLibraryA("Saludos.dll");
    if (hDLL == nullptr) {
        std::cerr << "Error al cargar la librería" << std::endl;
        return 1;
    }

    // Obtener el puntero a la función
    typedef void (*ImprimirHolaFunc)();
    ImprimirHolaFunc imprimirHola = (ImprimirHolaFunc)GetProcAddress(hDLL, "imprimirHola");
    if (imprimirHola == nullptr) {
        std::cerr << "Error al obtener la función" << std::endl;
        return 1;
    }

    // Invocar a la función y mostrar el mensaje
    imprimirHola();

    // Liberar la librería
    FreeLibrary(hDLL);

    return 0;
}
=======
/*
CONSIGNA:
    /Objetivo: Familiarización con librerías, archivos DLL y variable de entorno PATH. Tener presente la distinción entre biblioteca, librería y library.
    -Descripción: Crear un programa simple en C++ que utilice una librería externa (en forma de archivo DLL o similar en otros sistemas operativos) y que haga uso de la variable de entorno PATH para ubicar dicha librería.
Pasos a seguir:
    -Crear una librería en C++ y compilarla como un archivo DLL 8o similar en otros sistemas operativos). Programar en la librería una función que imprima un mensaje simple, como "Hola, desde la biblioteca".
    -Crear un programa principal en C++ que utilice esta librería. Hacer referencia (o linkear) a la librería de manera dinámica.
    -Incluir la ruta al archivo DLL en la variable de entorno PATH.
    -En el programa principal, cargar la librería, invocar a la función y mostrar el mensaje.
*/

#include <Windows.h> // Para cargar la DLL en Windows
#include <iostream>
#include "../Saludos/saludos.h"

int main() {
    HINSTANCE hDLL = LoadLibraryA("Saludos.dll");
    if (hDLL == nullptr) {
        std::cerr << "Error al cargar la librería" << std::endl;
        return 1;
    }

    // Obtener el puntero a la función
    typedef void (*ImprimirHolaFunc)();
    ImprimirHolaFunc imprimirHola = (ImprimirHolaFunc)GetProcAddress(hDLL, "imprimirHola");
    if (imprimirHola == nullptr) {
        std::cerr << "Error al obtener la función" << std::endl;
        return 1;
    }

    // Invocar a la función y mostrar el mensaje
    imprimirHola();

    // Liberar la librería
    FreeLibrary(hDLL);

    return 0;
}
>>>>>>> c0a71fc (01 06 24 update)
