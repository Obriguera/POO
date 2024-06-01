/*
CONSIGNA:
    -Crear un std::vector para contener int
    -Cargar 30 valores pseudo aleatorios entre 1 y 15
    -Publicar la moda

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

int generarNumeroAleatorio(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int encontrarModa (std::vector<int>& numeros)
{
    std::unordered_map<int, int> conteo;

    // Contar la frecuencia de cada número
    for (int num : numeros)
    {
        conteo[num]++;
    }

    // Encontrar el número con la frecuencia máxima
    int moda = 0;
    int frecuenciaMaxima = 0;
    for (const auto& par : conteo) {
        if (par.second > frecuenciaMaxima) {
            moda = par.first;
            frecuenciaMaxima = par.second;
        }
    }

    return moda;
}

int main()
{
    std::vector<int> valores;
    // Cargar 30 valores pseudoaleatorios entre 1 y 15
        for (int i = 0; i < 30; ++i) {
            valores.push_back(generarNumeroAleatorio(1, 15));
        }

        // Imprimir los valores generados
        std::cout << "Valores generados:" << std::endl;
        for (int num : valores) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        // Encontrar y publicar la moda
        int moda = encontrarModa(valores);
        std::cout << "La moda es: " << moda << std::endl;

        return 0;
}
