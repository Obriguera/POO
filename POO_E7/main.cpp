<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::sort

using namespace std;

class Gato
{
public:
    Gato()
    {
        cout << "Hay un gato" << endl;
    }
    Gato(int x, int y, int z) : patas(x), orejas(y), edad(z)
    {
        cout << "El gato tiene " << patas << " patas" << endl;
        cout << "El gato tiene " << orejas << " orejas" << endl;
        cout << "El gato tiene " << edad << " años de edad" << endl;
    }

    void rejuvenecer()
    {
        if (edad > 15)
        {
            edad -= 10;
            cout << "Si su gato rejuvenece, tendrá " << edad << " años de edad" << endl;
        }
        else
        {
            cout << "El gato es demasiado joven, no puede rejuvenecer" << endl;
        }
    }

    bool operator<(const Gato &other) const
    {
        return edad < other.edad;
    }

public:
    int patas = 0;
    int orejas = 0;
    int edad = 0;
};

int main()
{

    vector<Gato> gatos;
    gatos.push_back(Gato(4, 2, 10));
    gatos.push_back(Gato(3, 2, 5));
    gatos.push_back(Gato(2, 4, 20));
    sort(gatos.begin(), gatos.end());

    cout << "Gatos ordenados por edad:" << endl;
    for (Gato &gato : gatos)
    {
        cout << "Edad: " << gato.edad << " años" << endl;
    }

    return 0;
}
=======
/*
CONSIGNA:
    -Empty qmake Project
    -Utilizar la clase creada en el ejercicio anterior para crear objetos y almacenarlos en un std::vector
    -¿Se pueden ordenar? Qué estrategia utilizaría para ordenarlos de menor a mayor
*/

#include <iostream>
#include <vector>
#include <algorithm> // Para usar std::sort

using namespace std;

class Gato
{
public:
    Gato()
    {
        cout << "Hay un gato" << endl;
    }
    Gato(int x, int y, int z) : patas(x), orejas(y), edad(z)
    {
        cout << "El gato tiene " << patas << " patas" << endl;
        cout << "El gato tiene " << orejas << " orejas" << endl;
        cout << "El gato tiene " << edad << " años de edad" << endl;
    }

    void rejuvenecer()
    {
        if (edad > 15)
        {
            edad -= 10;
            cout << "Si su gato rejuvenece, tendrá " << edad << " años de edad" << endl;
        }
        else
        {
            cout << "El gato es demasiado joven, no puede rejuvenecer" << endl;
        }
    }

    bool operator<(const Gato &other) const
    {
        return edad < other.edad;
    }

public:
    int patas = 0;
    int orejas = 0;
    int edad = 0;
};

int main()
{

    vector<Gato> gatos;
    gatos.push_back(Gato(4, 2, 10));
    gatos.push_back(Gato(3, 2, 5));
    gatos.push_back(Gato(2, 4, 20));
    sort(gatos.begin(), gatos.end());

    cout << "Gatos ordenados por edad:" << endl;
    for (Gato &gato : gatos)
    {
        cout << "Edad: " << gato.edad << " años" << endl;
    }

    return 0;
}
>>>>>>> c0a71fc (01 06 24 update)
