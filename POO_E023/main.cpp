/*
Consigna:
    -Reutilizar el código fuente de cualquier otro ejericio y utilizar herencia múltiple, inline y friend.
    -Implementar herencia múltiple, inline y friend cuando sea beneficioso hacerlo.
*/

#include <iostream>
#include <vector>
using namespace std;

class Instrumento
{
public:
    Instrumento() {}
    virtual void sonar() = 0;
    virtual string verlo(){return "Yamaha";}
    virtual ~Instrumento() {}
};

class electrico
{
public:
    electrico() {}
    ~electrico() { std::cout << "Desenchufado\n"; }
    int getVoltaje() const { return 220; }
};


class Bateria: public Instrumento
{
private:
    int tambores = 5;
public:
    void sonar() override { std::cout << "La batería suena...\n"; }
    Bateria() {}
    friend void configurarBateria(Bateria& bateria); // Declaración de función friend
};

void configurarBateria(Bateria& bateria)
{
    bateria.tambores = 10;
    std::cout << "Batería configurada con " << bateria.tambores << " tambores.\n";
}


class Guitarra : public Instrumento
{
protected:
    int cuerdas = 6;
public:
    void sonar() override { std::cout << "La Guitarra suena...\n"; }
    Guitarra() {}
};


class Teclado : public Instrumento, public electrico
{
protected:
    int teclas = 61;
public:
    void sonar() override { std::cout << "El teclado suena MUY BIEN!!! \n"; }
    Teclado() {}
};

inline string calculo(bool a)
{
    if(a == true)
    {
    return "La tienda de música esta abierta";
    }
    else
    {
    return "La tienda de música esta cerrada";
    }

}

int main()
{
    vector<Instrumento*> instrumentos;
    bool a= true;
    cout << calculo(a) << endl;


    instrumentos.push_back(new Bateria());
    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Teclado());

    for (const auto& instrumento : instrumentos) {
            instrumento->sonar();
        }

    for (auto& instrumento : instrumentos)
    {
        delete instrumento;

    }
    Bateria bateria;
    configurarBateria(bateria);

    a = false;
    cout << calculo(a) << endl;
}
