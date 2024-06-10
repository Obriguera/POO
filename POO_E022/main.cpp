/*
Consigna:
    -Crear una clase base llamada Instrumento y las clases derivadas Guitarra, Bateria y Teclado.
    -La clase base tiene una función virtual pura llamada sonar().
    -Defina una función virtual verlo() que publique la marca del instrumento. Por defecto todos los instrumentos son de la marca Yamaha.
    -Utilice en la función main() un std::vector para almacenar punteros a objetos del tipo Instrumento. Instancie 5 objetos y agréguelos al std::vector.
    -Publique la marca de cada instrumento recorriendo el vector.
    -En las clases derivadas agregue los datos miembro "int cuerdas", "int teclas" e "int tambores" según corresponda. Por defecto, guitarra con 6 cuerdas, teclado con 61 teclas y batería con 5 tambores.
    -Haga que la clase Teclado tenga herencia múltiple, heredando además de una nueva clase Electrico. Todos los equipos del tipo "Electrico" tienen por defecto un voltaje de 220 volts. Esta clase deberá tener un destructor que al destruirse publique la leyenda "Desenchufado".
    -Al llamar a la función sonar(), se deberá publicar "Guitarra suena...", "Teclado suena..." o "Batería suena..." según corresponda.
    -Incluya los métodos get y set que crea convenientes.
*/

#include "iostream"
#include "vector"
#include "memory"
using namespace std;
class Instrumento
{
public:
    Instrumento() {}
    virtual void sonar() = 0;
    virtual string verlo(){return "Yamaha";}
};


class electrico
{
public:
    electrico() {}
    ~electrico() { std::cout << "Desenchufado\n"; }
    int getVoltaje() const { return 220; }
};




class Guitarra : public Instrumento
{
protected:
    int cuerdas = 6;
public:
    void sonar() override { std::cout << "La Guitarra suena...\n"; }
    Guitarra() {}
};




class Bateria: public Instrumento
{
protected:
    int tambores = 5;
public:
    void sonar() override { std::cout << "La batería suena...\n"; }
    Bateria() {}
};




class Teclado : public Instrumento, public electrico
{
protected:
    int teclas = 61;
public:
    void sonar() override { std::cout << "El teclado suena MUY BIEN!!!"; }
    Teclado() {}
};


int main()
{

    vector<Instrumento*> instrumentos;

    instrumentos.push_back(new Bateria());
    instrumentos.push_back(new Guitarra());
    instrumentos.push_back(new Teclado());

    for (const auto& instrumento : instrumentos) {
            instrumento->sonar(); // Llama al método sonar() de cada instrumento
        }

        // Liberar memoria
        for (auto& instrumento : instrumentos)
        {
            delete instrumento;
        }
}
