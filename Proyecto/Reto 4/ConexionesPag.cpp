#include <list>
#include <string>
using namespace std;

class ConexionesPag
{
public:
    string name;
    int conexE;
    int conexS;
    list<string> entrantes;
    list<string> salientes;
    ConexionesPag()
    {
        name = "";
        conexE = conexS = 0;
    }
    ConexionesPag(string nombre)
    {
        name = nombre;
        conexE = conexS = 0;
    }
    void agregarE(string entrante)
    {
        entrantes.push_front(entrante);
        conexE++;
    }

    void agregarS(string saliente)
    {
        salientes.push_back(saliente);
        conexS++;
    }
};
