#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
using namespace std;
int main()
{
    std::vector<std::string> frases;
    std::string Auxiliar;
    int iterador = 5;

    for (int i = 0; i < iterador; i++)
    {
    std::cout << "Escriba una expresion ideomatica " << i+1 << "/5" << std::endl;
    getline(cin,Auxiliar);
    frases.push_back(Auxiliar);
    }

    sort(frases.begin(),frases.end());

    std::cout << "Expresionews ideomaticas ordenadas" << std::endl;
    for(string expresion : frases)
    {
        cout << expresion;
    }
    return 0;
}
