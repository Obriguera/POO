/*
CONSIGNA:
  -En un Empty qmake Project
  -Crear una nueva clase (que no sea Persona, ni Cliente, ni Poste). Invente una clase.
  -Agregar uno o más constructores, agregar sus métodos y sus atributos
  -Crear algunos objetos de esta clase en la función main
*/

#include "iostream"
using namespace std;

class Gato
{
 public:
    Gato()
    {
    cout << "Hay un gato";
    }
  int patas = 0;
  int orejas = 0;
  int edad = 0;
  Gato(int x, int y, int z)
  {
      patas = x;
      orejas = y;
      edad = z;
      cout << "El gato tiene " << patas << " patas" << endl;
      cout << "El gato tiene " << orejas << " orejas" << endl;
      cout << "El gato tiene " << edad << " años de edad" << endl;
  }

  void rejuvenecer()
  {
    if(edad > 15)
    {
        edad = edad - 10;
        cout << "Si su gato rejubenece, tendrá " << edad << " años de edad" << endl;
    }
    else
    {
        cout << "El gato es demaciado joven, no puede rejuvenecer" << endl;
    }
    return;
  }
};



int main()
{
    Gato felino1;
    cout << endl << endl;
    Gato felino2(1,2,600);
    felino2.rejuvenecer();
    return 0;
}
