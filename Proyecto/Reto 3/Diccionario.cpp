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

bool find(string searchHere, string searching)
{
    int j = 1, finalLen = 8;
    bool found;
    for (int i = 1; i < searchHere.size(); i++)
    {

        if (searchHere[i] == searching[j] && searchHere[i - 1] == searching[j - 1])
            j++;
    }
    if (j == finalLen)
        return true;
    return false;
}

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
        if (r.getHostnameDestino() != "-")
        {
            if (cc.find(r.getHostnameDestino()) == cc.end())
            {
                ConexionesComputadora a(r.getIpDestino(), r.getHostnameDestino());
                cc[r.getHostnameDestino()] = a;
            }
            cc[r.getHostnameDestino()].nuevaEntrante(r.getPuertoDestino(), r.getIpDestino(), r.getHostnameFuente());
        }
    }

    // Pregunta 3

    // int cont = 0;
    // for (auto it = cc.begin(); it != cc.end(); it++)
    // {
    //     if (cc[it->first].entrantes.size() > 0 && find(cc[it->first].name, "reto.com"))
    //         cont++;
    // }
    // if (cont == 0)
    //     std::cout << "No hay conexeiones entrantes en los hosts de reto.com" << std::endl;
    // else
    //     std::cout << "Entrantes: " << cont << std::endl;

    // Pregunta 4
    // vector<string> hostsInfectados;
    // for (auto it = cc.begin(); it != cc.end(); it++)
    // {
    //     if (cc[it->first].salientes.size() != 0)
    //     {
    //         list<infoConexion> consalientes = cc[it->first].salientes;
    //         for (auto v : consalientes)
    //         {
    //             if (find(v.remoteName, "reto.com") == true)
    //             {
    //                 std::cout << cc[it->first].name << ": " << cc[it->first].ip << std::endl;
    //                 hostsInfectados.push_back(cc[it->first].name);
    //                 break;
    //             }
    //         }
    //     }
    // }

    // Pregunta 6
    // if (hostsInfectados.size() > 0)
    // {
    //     for (auto it = cc.begin(); it != cc.end(); it++)
    //     {
    //         se crea una lista con los valores de la lista salientes para poder acceder a ella
    //         list<infoConexion> consalientes = cc[it->first].salientes;
    //         for (auto v : consalientes)
    //         {
    //             if (v.remoteName == "go8hmesu6r6ydjrvys1g.org" || v.remoteName == "xi1t1ohvxs4th4c6ylg2.net")
    //             {
    //                 std::cout << cc[it->first].name << ": " << cc[it->first].ip << std::endl;
    //                 break;
    //             }
    //         }
    //     }
    // }

    return 0;
}