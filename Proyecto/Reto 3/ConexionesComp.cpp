#include "ConexionesComp.h"

ConexionesComp::ConexionesComp(){}

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

bool ConexionesComp::buscarHostSaliente(string hostName)
{
    for (int i = 0; i < hostSalientes.size(); i++)
    {
        if(hostSalientes[i] == hostName)
        {
            std::cout << "Hostname saliente:\t"<< hostSalientes[i]<< std::endl;
            std::cout << "Ip saliente:\t"<<ipsSalientes[i] << std::endl;
            return true;
        }
    }
    return false;    
}

bool ConexionesComp::buscarHostEntrante(string hostName)
{
    for (int i = 0; i < hostEntrantes.size(); i++)
    {
        if(hostEntrantes[i] == hostName)
        {
            std::cout << "Hostname entrante:\t"<< hostEntrantes[i]<< std::endl;
            std::cout << "Ip entrante:\t"<<ipsEntrantes[i] << std::endl;
            return true;
        }
    }
    return false;
}

bool ConexionesComp::buscarIpSaliente(string ip)
{
    for (int i = 0; i < ipsSalientes.size(); i++)
    {
        if(ipsSalientes[i] == ip)
        {
            std::cout << "Hostname saliente:\t"<< hostSalientes[i]<< std::endl;
            std::cout << "Ip saliente:\t"<<ipsSalientes[i] << std::endl;
            return true;
        }
    }
    return false;
}

bool ConexionesComp::buscarPiEntrante(string ip)
{
    for (int i = 0; i < ipsEntrantes.size(); i++)
    {
        if(ipsEntrantes[i] == ip)
        {
            std::cout << "Hostname saliente:\t"<< hostEntrantes[i]<< std::endl;
            std::cout << "Ip saliente:\t"<<ipsEntrantes[i] << std::endl;
            return true;
        }
    }
    return false;
}
