#include <string>
#include <vector>
#include <iostream>

using namespace std;

class ConexionesComp
{
private:
    vector<string> hostSalientes;
    vector<string> hostEntrantes;
    vector<string> ipsSalientes;
    vector<string> ipsEntrantes;

public:
    ConexionesComp();
    void agregarEntrante(string, string);
    void agregarSaliente(string, string);
    // funciones para mostrar info en los vectores
    void mostrarHostsSalientes();
    void mostrarHostsEntrantes();
    void mostrarIpsSalientes();
    void mostrarIpsEntrantes();
    // funciones para buscar dentro de los vectores
    bool buscarHostSaliente(string);
    bool buscarHostEntrante(string);
    bool buscarIpSaliente(string);
    bool buscarPiEntrante(string);
};