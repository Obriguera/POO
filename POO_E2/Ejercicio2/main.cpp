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
