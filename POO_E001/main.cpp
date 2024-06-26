/*
CONSIGNA:
    -Instalar Qt. Lo cual incluye las herramientas de compilación C++, la biblioteca Qt y Qt Creator.
    -Crear un primer programa que muestre por la consola de QtCreator 10 números aleatorios en el intervalo [ 2, 20 ]
    -Cada vez que se ejecute el programa, los números deberán ser aleatorios y distintos en cada ejecución.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main() {
    // Semilla para la generación de números aleatorios
    std::srand(std::time(0));

    // Vector para almacenar los números aleatorios
    std::vector<int> numeros;

    // Generar 10 números aleatorios únicos en el rango [2, 20]
    while (numeros.size() < 10) {
        int num = std::rand() % 19 + 2; // Generar número aleatorio en el rango [2, 20]
        if (std::find(numeros.begin(), numeros.end(), num) == numeros.end()) {
            numeros.push_back(num);
        }
    }

    // Mostrar los números generados
    std::cout << "Los 10 numeros aleatorios en el intervalo [2, 20] son:\n";
    for (int num : numeros) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
