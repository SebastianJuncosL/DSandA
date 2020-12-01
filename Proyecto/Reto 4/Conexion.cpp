#include <string>
#include <iostream>
using namespace std;

class Conexion
{
public:
    string fecha;
    string hora;
    string ipFuente;
    int puertoFuente;
    string hostnameFuente;
    string ipDestino;
    int puertoDestino;
    string hostnameDestino;

    Conexion()
    {
        fecha = "";
        hora = "";
        ipFuente = "";
        puertoFuente = 0;
        hostnameFuente = "";
        ipDestino = "";
        puertoDestino = 0;
        hostnameDestino = "";
    }
    Conexion(string fecha, string hora, string ipFuente, int puertoFuente, string hostnameFuente, string ipDestino, int puertoDestino, string hostnameDestino)
    {
        this->fecha = fecha;
        this->hora = hora;
        this->ipFuente = ipFuente;
        this->puertoFuente = puertoFuente;
        this->hostnameFuente = hostnameFuente;
        this->ipDestino = ipDestino;
        this->puertoDestino = puertoDestino;
        this->hostnameDestino = hostnameDestino;
    }

    void displayInfo()
    {
        std::cout << "Fecha: " << fecha << std::endl;
        std::cout << "Hora: " << hora << std::endl;
        std::cout << "Ip Fuente: " << ipFuente << std::endl;
        std::cout << "Puerto Fuente: " << puertoFuente << std::endl;
        std::cout << "Hostname Fuente: " << hostnameFuente << std::endl;
        std::cout << "Ip Destino: " << ipDestino << std::endl;
        std::cout << "Puerto Destino: " << puertoDestino << std::endl;
        std::cout << "Hostname Destino: " << hostnameDestino << std::endl;
    }
};