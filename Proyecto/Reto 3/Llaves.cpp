#include "Llaves.h"

Llaves::Llaves()
{
    key = "-";
    hostname = "-";
    ip = "-";
}

Llaves::Llaves(string newKey, string hostname, string ip)
{
    key = generateKey(newKey);
    this->hostname = hostname;
    this->ip = ip;
}

string Llaves::generateKey(string hostName)
{
    int pos = 0;
    string name = "";
    for (int i = 0; i < hostName.size(); i++)
    {
        if (hostName[i] == '.')
            break;
        name += hostName[i];
    }
    return name;
}

void Llaves::insertarEntrante(string ip, string host)
{
    conexiones.agregarEntrante(ip, host);
}

void Llaves::insertarSaliente(string ip, string host)
{
    conexiones.agregarSaliente(ip, host);
}

string Llaves::getKey()
{
    return key;
}

string Llaves::getHostname()
{
    return hostname;
}

string Llaves::getIP()
{
    return ip;
}