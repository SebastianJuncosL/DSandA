#include "Node.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class ConexionesComputadora
{
private:
    string ip;
    string nombre;
    int cEnCount;
    int cSaCount;
    Node<string> *conexionesEntrantes; // ip destino --> ip a la que accede otro equipo
    Node<string> *conexionesSalientes; // ip fuente --> misma ip que la de arriba
public:
    ConexionesComputadora();
    ConexionesComputadora(string);
    ConexionesComputadora(string, string);
    ~ConexionesComputadora();
    void obtenerConexionesE();
    void obtenerConexionesS();
    void printConexionesE();
    void printConexionesS();
    void repeatedConnections();
};