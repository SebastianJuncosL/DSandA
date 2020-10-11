#include "Datos.h"

Datos::Datos()
{
    noDeDatos = 0;
    importarDatos("equipo 4.csv"); // Ya que el archivo se encuentra en la misma carpeta que los scripts, no hayq eu especificar una direccion. Favor de no alterar la carpeta
}

void Datos::importarDatos(string path)
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
        noDeDatos++;
    }
}

// Metodos de ordenamiento utilizando Selection Sort
void Datos::ordenarPorFecha()
{
    for (int i = 0; i < conexiones.size() - 1; i++)
    {
        int fechaAntigua = i;
        for (int j = i + 1; j < conexiones.size(); j++)
        {
            if (conexiones[j].getFecha() < conexiones[fechaAntigua].getFecha())
                fechaAntigua = j;
        }
        iter_swap(conexiones.begin() + i, conexiones.begin() + fechaAntigua);
    }
}

void Datos::ordenarPorIpFuente()
{
    for (int i = 0; i < conexiones.size() - 1; i++)
    {
        int ipMasCorto = i;
        for (int j = i + 1; j < conexiones.size(); j++)
        {
            if (conexiones[j].getIpFuente() < conexiones[ipMasCorto].getIpFuente())
                ipMasCorto = j;
        }
        iter_swap(conexiones.begin() + i, conexiones.begin() + ipMasCorto);
    }
}

void Datos::ordenarPorPuertoFuente()
{
    for (int i = 0; i < conexiones.size() - 1; i++)
    {
        int puertoMasPequenio = i;
        for (int j = i + 1; j < conexiones.size(); j++)
        {
            if (conexiones[j].getPuertoFuente() < conexiones[puertoMasPequenio].getPuertoFuente())
                puertoMasPequenio = j;
        }
        iter_swap(conexiones.begin() + i, conexiones.begin() + puertoMasPequenio);
    }
}

void Datos::ordenarPorHostnameFuente()
{
    for (int i = 0; i < conexiones.size() - 1; i++)
    {
        int hostAlfabetico = i;
        for (int j = i + 1; j < conexiones.size(); j++)
        {
            if (conexiones[j].getHostnameFuente() < conexiones[hostAlfabetico].getHostnameFuente())
                hostAlfabetico = j;
        }
        iter_swap(conexiones.begin() + i, conexiones.begin() + hostAlfabetico);
    }
}

void Datos::ordenarPorIpDestino()
{
    for (int i = 0; i < conexiones.size() - 1; i++)
    {
        int ipMasCorto = i;
        for (int j = i + 1; j < conexiones.size(); j++)
        {
            if (conexiones[j].getIpDestino() < conexiones[ipMasCorto].getIpDestino())
                ipMasCorto = j;
        }
        iter_swap(conexiones.begin() + i, conexiones.begin() + ipMasCorto);
    }
}

void Datos::ordenarPorPuertoDestino()
{
    for (int i = 0; i < conexiones.size() - 1; i++)
    {
        int puertoMasPequenio = i;
        for (int j = i + 1; j < conexiones.size(); j++)
        {
            if (conexiones[j].getPuertoDestino() < conexiones[puertoMasPequenio].getPuertoDestino())
                puertoMasPequenio = j;
        }
        iter_swap(conexiones.begin() + i, conexiones.begin() + puertoMasPequenio);
    }
}

void Datos::ordenarPorHostnameDestino()
{
    for (int i = 0; i < conexiones.size() - 1; i++)
    {
        int hostAlfabetico = i;
        for (int j = i + 1; j < conexiones.size(); j++)
        {
            if (conexiones[j].getHostnameDestino() < conexiones[hostAlfabetico].getHostnameDestino())
                hostAlfabetico = j;
        }
        iter_swap(conexiones.begin() + i, conexiones.begin() + hostAlfabetico);
    }
}

// Metodos de búsqueda utilizando Linear Search
void Datos::buscarPorFecha(string fechaBuscada)
{
    string current;
    int countTotal = 0;
    std::cout << "Logs con fechas que contienen '" << fechaBuscada << "':" << endl;
    for (int i = 0; i < conexiones.size(); i++)
    {
        current = conexiones[i].getFecha();
        size_t found = current.find(fechaBuscada);
        if (found != string::npos)
        {
            std::cout << "---------------------------------------------" << std::endl;
            conexiones[i].displayInfo();
            std::cout << "---------------------------------------------" << std::endl;
            countTotal++;
        }
    }
    std::cout << "Total de datos con la fecha '" << fechaBuscada << "': " << countTotal << std::endl;
    if (countTotal == 0)
        std::cout << "No existen registros con esta fecha" << std::endl;
    else
        cout << "\n";
}

void Datos::buscarPorIpFuente(string ipFuenteBuscada)
{
    string current;
    int countTotal = 0;
    std::cout << "Logs con ip fuente que contienen '" << ipFuenteBuscada << "':" << endl;
    for (int i = 0; i < conexiones.size(); i++)
    {
        current = conexiones[i].getIpFuente();
        size_t found = current.find(ipFuenteBuscada);
        if (found != string::npos)
        {
            std::cout << "---------------------------------------------" << std::endl;
            conexiones[i].displayInfo();
            std::cout << "---------------------------------------------" << std::endl;
            countTotal++;
        }
    }
    std::cout << "Total de datos con el ip fuente '" << ipFuenteBuscada << "': " << countTotal << std::endl;
    if (countTotal == 0)
        std::cout << "No existen registros con este ip fuente" << std::endl;
    else
        cout << "\n";
}

void Datos::buscarPorPuertoFuente(int puertoFuenteBuscado)
{
    int current, countTotal = 0;
    std::cout << "Logs con puerto fuente '" << puertoFuenteBuscado << "':" << endl;
    for (int i = 0; i < conexiones.size(); i++)
    {
        if (puertoFuenteBuscado == conexiones[i].getPuertoFuente())
        {
            std::cout << "---------------------------------------------" << std::endl;
            conexiones[i].displayInfo();
            std::cout << "---------------------------------------------" << std::endl;
            countTotal++;
        }
    }
    std::cout << "Total de datos con el puerto fuente '" << puertoFuenteBuscado << "': " << countTotal << std::endl;
    if (countTotal == 0)
        std::cout << "No existen registros con este puerto fuente" << std::endl;
    else
        cout << "\n";
}

void Datos::buscarPorHostnameFuente(string hostnameFuenteBuscado)
{
    string current;
    int countTotal = 0;
    std::cout << "Logs con hostname fuente que contienen '" << hostnameFuenteBuscado << "':" << endl;
    for (int i = 0; i < conexiones.size(); i++)
    {
        current = conexiones[i].getHostnameFuente();
        size_t found = current.find(hostnameFuenteBuscado);
        if (found != string::npos)
        {
            std::cout << "---------------------------------------------" << std::endl;
            conexiones[i].displayInfo();
            std::cout << "---------------------------------------------" << std::endl;
            countTotal++;
        }
    }
    std::cout << "Total de datos con el hostname fuente '" << hostnameFuenteBuscado << "': " << countTotal << std::endl;
    if (countTotal == 0)
        std::cout << "No existen registros con este hostname fuente" << std::endl;
    else
        cout << "\n";
}
void Datos::buscarPorIpDestino(string ipDestionBuscado)
{
    string current;
    int countTotal = 0;
    std::cout << "Logs con hostname fuente que contienen '" << ipDestionBuscado << "':" << endl;
    for (int i = 0; i < conexiones.size(); i++)
    {
        current = conexiones[i].getIpDestino();
        size_t found = current.find(ipDestionBuscado);
        if (found != string::npos)
        {
            std::cout << "---------------------------------------------" << std::endl;
            conexiones[i].displayInfo();
            std::cout << "---------------------------------------------" << std::endl;
            countTotal++;
        }
    }
    std::cout << "Total de datos con el ip destino '" << ipDestionBuscado << "': " << countTotal << std::endl;
    if (countTotal == 0)
        std::cout << "No existen registros con este hostname fuente" << std::endl;
    else
        cout << "\n";
}
void Datos::buscarPorPuertoDestino(int puertoDestinoBuscado)
{
    int countTotal = 0;
    std::cout << "Logs con puerto destino '" << puertoDestinoBuscado << "':" << endl;
    for (int i = 0; i < conexiones.size(); i++)
    {
        if (puertoDestinoBuscado == conexiones[i].getPuertoDestino())
        {
            std::cout << "---------------------------------------------" << std::endl;
            conexiones[i].displayInfo();
            std::cout << "---------------------------------------------" << std::endl;
            countTotal++;
        }
    }
    std::cout << "Total de datos con el puerto destino '" << puertoDestinoBuscado << "': " << countTotal << std::endl;
    if (countTotal == 0)
        std::cout << "No existen registros con este puerto destino" << std::endl;
    else
        cout << "\n";
}
void Datos::buscarPorHostnameDestino(string hostnameDestinoBuscado)
{
    string current;
    int countTotal = 0;
    std::cout << "Logs con el hostname destino que contiene '" << hostnameDestinoBuscado << "':" << endl;
    for (int i = 0; i < conexiones.size(); i++)
    {
        current = conexiones[i].getHostnameDestino();
        size_t found = current.find(hostnameDestinoBuscado);
        if (found != string::npos)
        {
            std::cout << "---------------------------------------------" << std::endl;
            conexiones[i].displayInfo();
            std::cout << "---------------------------------------------" << std::endl;
            countTotal++;
        }
    }
    std::cout << "Total de datos con el hostname destino '" << hostnameDestinoBuscado << "': " << countTotal << std::endl;
    if (countTotal == 0)
        std::cout << "No existen registros con este hostname destino" << std::endl;
    else
        cout << "\n";
}

// Metodo para imprimir los primeros N datos
void Datos::displayN(int cuantos)
{
    if (cuantos > conexiones.size())
        cuantos = conexiones.size();
    else if (cuantos < 0)
    {
        std::cout << "No se pueden mostrar los datos porque la cantidad es incorrecta" << std::endl;
        return;
    }

    for (int i = 0; i < cuantos; i++)
    {
        conexiones[i].displayInfo();
        if (i != 3 - 1)
        {
            std::cout << "---------------------------------------------" << std::endl;
        }
    }
}

// Metodos para listar
void Datos::listarFechas()
{
    int fechasCont = 0;
    vector<string> fechas;
    for (int i = 0; i < conexiones.size(); i++)
    {
        auto it = find(fechas.begin(), fechas.end(), conexiones[i].getFecha());
        if (it == fechas.end())
        {
            fechas.push_back(conexiones[i].getFecha());
            fechasCont++;
        }
    }
    std::cout << "Las fechas listadas son las siguientes:" << std::endl;
    for (int i = 0; i < fechas.size(); i++)
    {
        if (i < fechas.size() - 1)
            std::cout << fechas[i] << ", ";
        else
            std::cout << fechas[i] << std::endl;
    }
    std::cout << "Hay " << fechasCont << " fechas" << std::endl;
}

void Datos::listarIpFuente()
{
    int ipCont = 0;
    vector<string> ipFuentes;
    for (int i = 0; i < conexiones.size(); i++)
    {
        auto it = find(ipFuentes.begin(), ipFuentes.end(), conexiones[i].getIpFuente());
        if (it == ipFuentes.end())
        {
            ipFuentes.push_back(conexiones[i].getIpFuente());
            ipCont++;
        }
    }
    std::cout << "Los ips fuente listados son los siguientes:" << std::endl;
    for (int i = 0; i < ipFuentes.size(); i++)
    {
        if (i < ipFuentes.size() - 1)
            std::cout << ipFuentes[i] << ", ";
        else
            std::cout << ipFuentes[i] << std::endl;
    }
    std::cout << "Hay " << ipCont << " ips" << std::endl;
}

void Datos::listarPuertosFuente()
{
    int puertosCont = 0;
    vector<int> puertosFuente;
    for (int i = 0; i < conexiones.size(); i++)
    {
        auto it = find(puertosFuente.begin(), puertosFuente.end(), conexiones[i].getPuertoFuente());
        if (it == puertosFuente.end())
        {
            puertosFuente.push_back(conexiones[i].getPuertoFuente());
            puertosCont++;
        }
    }
    std::cout << "Los puertos fuente listados son los siguientes:" << std::endl;
    for (int i = 0; i < puertosFuente.size(); i++)
    {
        if (i < puertosFuente.size() - 1)
            std::cout << puertosFuente[i] << ", ";
        else
            std::cout << puertosFuente[i] << std::endl;
    }
    std::cout << "Hay " << puertosCont << " puertos fuente" << std::endl;
}

void Datos::listarHostnameFuente()
{
    int hostCont = 0;
    vector<string> hostNames;
    for (int i = 0; i < conexiones.size(); i++)
    {
        auto it = find(hostNames.begin(), hostNames.end(), conexiones[i].getHostnameFuente());
        if (it == hostNames.end())
        {
            hostNames.push_back(conexiones[i].getHostnameFuente());
            hostCont++;
        }
    }
    std::cout << "Los hostname fuente listados son los siguientes:" << std::endl;
    for (int i = 0; i < hostNames.size(); i++)
    {
        if (i < hostNames.size() - 1)
            std::cout << hostNames[i] << ", ";
        else
            std::cout << hostNames[i] << std::endl;
    }
    std::cout << "Hay " << hostCont << " hostnames fuente" << std::endl;
}
void Datos::listarIpDestino()
{
    int ipCont = 0;
    vector<string> ipsDestino;
    for (int i = 0; i < conexiones.size(); i++)
    {
        auto it = find(ipsDestino.begin(), ipsDestino.end(), conexiones[i].getIpDestino());
        if (it == ipsDestino.end())
        {
            ipsDestino.push_back(conexiones[i].getIpDestino());
            ipCont++;
        }
    }
    std::cout << "Los ips destino listados son los siguientes:" << std::endl;
    for (int i = 0; i < ipsDestino.size(); i++)
    {
        if (i < ipsDestino.size() - 1)
            std::cout << ipsDestino[i] << ", ";
        else
            std::cout << ipsDestino[i] << std::endl;
    }
    std::cout << "Hay " << ipCont << " ips destino" << std::endl;
}

void Datos::listarPuertosDestino()
{
    int puertosCont = 0;
    vector<int> puertosDestino;
    for (int i = 0; i < conexiones.size(); i++)
    {
        auto it = find(puertosDestino.begin(), puertosDestino.end(), conexiones[i].getPuertoDestino());
        if (it == puertosDestino.end())
        {
            puertosDestino.push_back(conexiones[i].getPuertoDestino());
            puertosCont++;
        }
    }
    std::cout << "Los puertos destino listados son los siguientes:" << std::endl;
    for (int i = 0; i < puertosDestino.size(); i++)
    {
        if (i < puertosDestino.size() - 1)
            std::cout << puertosDestino[i] << ", ";
        else
            std::cout << puertosDestino[i] << std::endl;
    }
    std::cout << "Hay " << puertosCont << " puertos destino" << std::endl;
}

void Datos::listarHostnameDestino()
{
    int hostCont = 0;
    vector<string> hostNames;
    for (int i = 0; i < conexiones.size(); i++)
    {
        auto it = find(hostNames.begin(), hostNames.end(), conexiones[i].getHostnameDestino());
        if (it == hostNames.end())
        {
            hostNames.push_back(conexiones[i].getHostnameDestino());
            hostCont++;
        }
    }
    std::cout << "Los hostname destino listados son los siguientes:" << std::endl;
    for (int i = 0; i < hostNames.size(); i++)
    {
        if (i < hostNames.size() - 1)
            std::cout << hostNames[i] << ", ";
        else
            std::cout << hostNames[i] << std::endl;
    }
    std::cout << "Hay " << hostCont << " hostnames destino" << std::endl;
}
