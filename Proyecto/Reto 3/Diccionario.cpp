#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <list>

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
    void displayInfo();
};

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

vector<Conexion> conexiones;
void importarDatos(string path)
{
    ifstream fileIn;
    fileIn.open(path);
    string line, partes;
    string valores[9];
    int i = 0;
    while (fileIn.good())
    {
        getline(fileIn, line);

        istringstream flujoEntrada(line);
        while (getline(flujoEntrada, partes, ','))
        {

            valores[i] = partes;
            i++;
        }
        if (valores[7].find('\r') != valores[7].npos)
        {
            valores[7] = valores[7].substr(0, valores[7].size() - 1);
        }

        if (valores[3] == "-" && valores[6] == "-")
            conexiones.push_back(Conexion(valores[0], valores[1], valores[2], 0, valores[4], valores[5], 0, valores[7]));
        else if (valores[3] == "-")
        {
            int pos6 = stoi(valores[6]);
            std::cout << pos6 << std::endl;
            conexiones.push_back(Conexion(valores[0], valores[1], valores[2], 0, valores[4], valores[5], pos6, valores[7]));
        }
        else if (valores[6] == "-")
        {
            int pos3 = stoi(valores[3]);
            conexiones.push_back(Conexion(valores[0], valores[1], valores[2], pos3, valores[4], valores[5], 0, valores[7]));
        }

        else
        {
            int pos3 = stoi(valores[3]);
            int pos6 = stoi(valores[6]);
            conexiones.push_back(Conexion(valores[0], valores[1], valores[2], pos3, valores[4], valores[5], pos6, valores[7]));
        }
        i = 0;
    }
}

// --------------------------------------------------------------------------------------------------------------------------------------

class infoConexion
{
public:
    int remotePort;
    string remoteIP;
    string remoteName;

    infoConexion(int rP, string rIP, string rN)
    {
        remotePort = rP;
        remoteIP = rIP;
        remoteName = rN;
    }

    void printAll()
    {
        std::cout << remotePort << std::endl;
        std::cout << remoteIP << std::endl;
        std::cout << remoteName << std::endl;
        std::cout << "------------------------------------------------------" << std::endl;
    }
};

class ConexionesComputadora
{
public:
    string ip;
    string name;
    list<infoConexion> entrantes;
    list<infoConexion> salientes;

    ConexionesComputadora() {}

    ConexionesComputadora(string ip, string name)
    {
        this->ip = ip;
        this->name = name;
    }

    void nuevaEntrante(int port, string ip, string name)
    {
        infoConexion a(port, ip, name); 
        entrantes.push_front(a);   
    }

    void nuevaSaliente(int port, string ip, string name)
    {
        infoConexion a(port, ip, name);
        salientes.push_back(a);        
    }
};

int main(int argc, const char **argv)
{
    importarDatos("equipo 4.csv");
    unordered_map<string, ConexionesComputadora> cc;
    for (Conexion r : conexiones)
    {
        if (r.getIpFuente() != "-")
        {
            if (cc.find(r.getIpFuente()) == cc.end())
            {
                ConexionesComputadora a(r.getIpFuente(), r.getHostnameFuente());
                cc[r.getIpFuente()] = a;
            }
            cc[r.getIpFuente()].nuevaSaliente(r.getPuertoDestino(), r.getIpDestino(), r.getHostnameDestino());
        }
    }

    // Pregunta 3

    int cont = 0;
    for (auto it = cc.begin(); it != cc.end(); it++)
    {
        if (cc[it->first].entrantes.size() > 0)
        {
            cont++;
            cout << it->first << ":";
            cout << cc[it->first].name << ",";
        }
        cout << endl;
    }
    if (cont == 0)
        std::cout << "No hay conexeiones entrantes en los hosts de reto.com" << std::endl;

    // PRegunta 4
    int i = 0;
    for (auto it = cc.begin(); it != cc.end(); it++)
    {
        if (cc[it->first].entrantes.size() > 0)
        {
            list<infoConexion> entrantes = cc[it->first].entrantes;
            for (auto v: entrantes)
            {
                v.printAll();
                std::cout << v.remoteIP << std::endl;
            }
        }
        cout << endl;
    }
    return 0;
}