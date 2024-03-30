#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;

public:
    Persona(const std::string& nombre) : nombre(nombre) {}

    std::string getNombre() const {
        return nombre;
    }
};

class Poste {
private:
    double altura;
    double diametro;

public:
    Poste(double altura, double diametro) : altura(altura), diametro(diametro) {}

    double getAltura() const {
        return altura;
    }

    double getDiametro() const {
        return diametro;
    }
};

template <class T>
void imprimirDescripcion(const T& objeto) {
    std::cout << "Descripción del objeto: ";
}

template <>
void imprimirDescripcion(const Persona& persona) {
    std::cout << "Persona con nombre " << persona.getNombre() << std::endl;
}

template <>
void imprimirDescripcion(const Poste& poste) {
    std::cout << "Poste con altura de " << poste.getAltura() << " metros y "
              << poste.getDiametro() << " cm de diámetro" << std::endl;
}

int main() {
    Persona persona1("Lucrecia");
    Persona persona2("Juan");

    Poste poste1(8.15, 15.0);
    Poste poste2(10.0, 20.5);


    imprimirDescripcion(persona1);
    imprimirDescripcion(persona2);
    imprimirDescripcion(poste1);
    imprimirDescripcion(poste2);

    return 0;
}
