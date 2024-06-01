/*
CONSIGNA:
    -En un Empty qmake Project
    -Crear una función genérica que imprima por consola sus valores ordenados
    -Es decir, se le pasa un array con sus valores en cualquier orden, y la función genérica los imprime ordenados
    -Que el prototipo sea: template < class T > void imprimir( T * v, int cantidad, bool mayor_a_menor );
    -Utilizar el método de ordenamiento por inserción
    -Probar esta función en main utilizando dos arrays (int y float) y ordenar de mayor a menor y el otro al revés.
*/

#include <iostream>
using namespace std;

template <class T> void imprimir(T *v, int cantidad, bool mayor_a_menor)
{
    // Implementación del ordenamiento por inserción
    for (int i = 1; i < cantidad; ++i)
    {
        T temp = v[i];
        int j = i - 1;
        if (mayor_a_menor)
        {
            while (j >= 0 && v[j] < temp)
            {
                v[j + 1] = v[j];
                j--;
            }
        } else
        {
            while (j >= 0 && v[j] > temp)
            {
                v[j + 1] = v[j];
                j--;
            }
        }
        v[j + 1] = temp;
    }

    // Imprimir los valores ordenados
    std::cout << "Valores ordenados: ";
    if (mayor_a_menor) {
        for (int i = 0; i < cantidad; ++i) {
            std::cout << v[i] << " ";
        }
    } else {
        for (int i = cantidad - 1; i >= 0; --i) {
            std::cout << v[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    int intArray[] = {5, 2, 9, 1, 7};
    float floatArray[] = {3.5, 1.2, 4.7, 2.8, 0.9};

    // Ordenar de mayor a menor
    std::cout << "Ordenado de mayor a menor:" << std::endl;
    imprimir(intArray, 5, true);
    imprimir(floatArray, 5, true);

    // Ordenar de menor a mayor
    std::cout << "\nOrdenado de menor a mayor:" << std::endl;
    imprimir(intArray, 5, false);
    imprimir(floatArray, 5, false);

    return 0;
}
