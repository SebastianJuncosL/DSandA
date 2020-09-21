#include <string>
#pragma once
using namespace std;

class Conexion
{
private:
    string fecha;
    string hora;
    string ipFuente;
    int puertoFuente;
    string hostnameFuente;
    string ipDestino;
    int puertoDestino;
    string hostnameDestino;

public:
    Conexion();
    Conexion(string, string, string, int, string, string, int, string);
    string getFecha();
    string getHora();
    string getIpFuente();
    int getPuertoFuente();
    string getHostnameFuente();
    string getIpDestino();
    int getPuertoDestino();
    string getHostnameDestino();
};
