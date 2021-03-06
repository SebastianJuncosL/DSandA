#include "Conexion.h"

Conexion::Conexion()
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
Conexion::Conexion(string fecha, string hora, string ipFuente, int puertoFuente, string hostnameFuente, string ipDestino, int puertoDestino, string hostnameDestino)
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

string Conexion::getFecha()
{
    return fecha;
}
string Conexion::getHora()
{
    return hora;
}
string Conexion::getIpFuente()
{
    return ipFuente;
}
int Conexion::getPuertoFuente()
{
    return puertoFuente;
}
string Conexion::getHostnameFuente()
{
    return hostnameFuente;
}
string Conexion::getIpDestino()
{
    return ipDestino;
}
int Conexion::getPuertoDestino()
{
    return puertoDestino;
}
string Conexion::getHostnameDestino()
{
    return hostnameDestino;
}

void Conexion::displayInfo()
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