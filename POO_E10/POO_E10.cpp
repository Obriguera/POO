<<<<<<< HEAD
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
=======
/*
CONSIGNA:
    -En un Empty qmake Project
    -Crear una clase Jugador con atributos int velocidad, int fuerza y std::string nombre
    -Usar constructor inicializando de la manera recomendada la velocidad en 0, fuerza en 0 y nombre "sin nombre"
    -Crear los métodos setter y getter para setear y obtener los valores de los atributos
    -Incluir el destructor
    -En la función main crear un std::vector< Jugador > e insertar 10 jugadores distintos
    -Por último, publicar los datos de cada uno de los jugadores con std::cout
*/

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
>>>>>>> c0a71fc (01 06 24 update)
