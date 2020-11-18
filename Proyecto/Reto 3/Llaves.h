#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "ConexionesComp.h"
using namespace std;

class Llaves
{
private:
    //Conexiones conexion;
    string key;
    ConexionesComp conexiones;

public:
    Llaves();
    Llaves(string);
    // Generador de llave
    string generateKey(string);
    // Inserta en los objetos de tipo Conexiones Computadora
    void insertarEntrante(string, string);
    void insertarSaliente(string, string);
    // Usar la lalve de manera externa
    string getKey();
    // Mostrar especifico
    void mostrarHostsSalientes() { conexiones.mostrarHostsSalientes(); };
    void mostrarHostsEntrantes() { conexiones.mostrarHostsEntrantes(); };
    void mostrarIpsSalientes() { conexiones.mostrarIpsSalientes(); };
    void mostrarIpsEntrantes() { conexiones.mostrarIpsEntrantes(); };
    // Buscar Especifico
    bool buscarHostSaliente(string host) { conexiones.buscarHostSaliente(host); };
    bool buscarHostEntrante(string host) { conexiones.buscarHostEntrante(host); };
    bool buscarIpSaliente(string ip) { conexiones.buscarIpSaliente(ip); };
    bool buscarPiEntrante(string ip) { conexiones.buscarPiEntrante(ip); };
};
