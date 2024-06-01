<<<<<<< HEAD
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
=======
/*
CONSIGNA:
    -En un Empty qmake Project
    -Crear una función genérica que imprima por consola una descripción de cualquier objeto.
    -El mensaje puede ser algo así: "Persona con nombre Lucrecia", "Poste con altura de 8 metros y 15 cm de diámetro".
    -Probar esta función en main utilizando dos objetos de la clase Persona y dos objetos de la clase Poste.
    -Incluir todo el código fuente en el archivo main.cpp.
    -Pedirle al chat el código, interpretarlo y hacerlo funcionar.
*/

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
>>>>>>> c0a71fc (01 06 24 update)
