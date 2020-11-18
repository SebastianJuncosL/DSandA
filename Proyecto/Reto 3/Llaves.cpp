#include "Llaves.h"

Llaves::Llaves()
{
    key = "-";
}

Llaves::Llaves(string newKey)
{
    key = generateKey(newKey);
}

string Llaves::generateKey(string hostName)
{
    int pos = 0;
    string name = "";
    if (hostName.size() > 3)
    {
        for (int i = 0; i < hostName.size(); i++)
        {
            if (hostName[i] == '.')
                break;
            name += hostName[i];
        }
        return name;
    }
    else
        return "-";
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

