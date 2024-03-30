#include <iostream>
#include <vector>
#include <string>

class Jugador {
private:
    int velocidad;
    int fuerza;
    std::string nombre;

public:
    Jugador() : velocidad(0), fuerza(0), nombre("Sin Nombre") {}

    ~Jugador() {}

    void setter()
    {
        int a;
        int b;
        std::string c;
        std::cout << "Cargue un numero para establecer la FUERZA: ";
        std::cin >> a;
        std::cout << "Cargue un numero para establecer la VELOCIDAD: ";
        std::cin >> b;
        std::cout << "Cargue un Nombre: ";
        std::cin >> c;

        //Cargo valores
        velocidad = a;
        fuerza = b;
        nombre = c;
    }

    void getter() const
    {
        std::cout << "Velocidad: " << velocidad << std::endl;
        std::cout << "Fuerza: " << fuerza << std::endl;
        std::cout << "Nombre: " << nombre << std::endl;
    }
};

int main() {
    std::vector<Jugador> jugadores(10);

    for (int i = 0; i < 10; ++i)
    {
        Jugador jugador;
        jugador.setter();
        jugadores[i] = jugador;
    }

    for (int i = 0; i < 10; ++i) {
        std::cout << "Jugador " << i + 1 << ": " << std::endl;
        jugadores[i].getter();
        std::cout << std::endl;
    }

    return 0;
}
