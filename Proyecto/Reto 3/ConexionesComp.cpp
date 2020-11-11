#include "ConexionesComp.h"

void ConexionesComp::agregarEntrante(string ip, string host)
{
    hostEntrantes.push_back(host);
    ipsEntrantes.push_back(ip);
}

void ConexionesComp::agregarSaliente(string ip, string host)
{
    hostSalientes.push_back(host);
    ipsSalientes.push_back(ip);
}

void ConexionesComp::mostrarHostsSalientes()
{
    if (hostSalientes.size() > 0)
    {
        for (int i = 0; i < hostSalientes.size(); i++)
        {
            if (i < hostSalientes.size() - 1)
                std::cout << hostSalientes[i] << ", ";
            else
                std::cout << hostSalientes[i] << std::endl;
        }
    }
    else
    {
        std::cout << "No hay conexiones salientes" << std::endl;
    }
}

void ConexionesComp::mostrarHostsEntrantes()
{
    if (hostEntrantes.size() > 0)
    {
        for (int i = 0; i < hostEntrantes.size(); i++)
        {
            if (i < hostEntrantes.size() - 1)
                std::cout << hostEntrantes[i] << ", ";
            else
                std::cout << hostEntrantes[i] << std::endl;
        }
    }
    else
    {
        std::cout << "No hay conexiones entrantes" << std::endl;
    }
}

void ConexionesComp::mostrarIpsSalientes()
{
    if (ipsSalientes.size() > 0)
    {
        for (int i = 0; i < ipsSalientes.size(); i++)
        {
            if (i < ipsSalientes.size() - 1)
                std::cout << ipsSalientes[i] << ", ";
            else
                std::cout << ipsSalientes[i] << std::endl;
        }
    }
    else
    {
        std::cout << "No hay ips salientes" << std::endl;
    }
}

void ConexionesComp::mostrarIpsEntrantes()
{
    if (ipsEntrantes.size() > 0)
    {
        for (int i = 0; i < ipsEntrantes.size(); i++)
        {
            if (i < ipsEntrantes.size() - 1)
                std::cout << ipsEntrantes[i] << ", ";
            else
                std::cout << ipsEntrantes[i] << std::endl;
        }
    }
    else
    {
        std::cout << "No hay ips entrantes" << std::endl;
    }
}