#include "Datos.h"

Datos::Datos()
{
    importarDatos("equipo 4.csv"); // Ya que el archivo se encuentra en la misma carpeta que los scripts, no hayq eu especificar una direccion. Favor de no alterar la carpeta
}

void Datos::importarDatos(string path)
{
    ifstream fileIn;
    fileIn.open(path);
    string line, partes;
    string valores[8];
    int i = 0;
    while (fileIn.good())
    {
        getline(fileIn, line);
        istringstream flujoEntrada(line);
        while (getline(flujoEntrada, partes, ','))
        {
            valores[i] = partes;
            //std::cout << i << std::endl;
            // cout<<i<<"\n";
            //std::cout << valores[i] << std::endl;
            i++;
            if (i == 8)
                i = 0;
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

// Metodos de búsqueda utilizando Binary Search
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
    if (countTotal == 0)
        std::cout << "No existen registros con esta fecha" << std::endl;
    else
        cout << "\n";
}

void Datos::buscarPorIpFuente(string ipFuenteBuscada)
{
    string current;
    int countTotal = 0;
    std::cout << "Logs con ip fuentes que contienen '" << ipFuenteBuscada << "':" << endl;
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
    if (countTotal == 0)
        std::cout << "No existen registros con este hostname fuente" << std::endl;
    else
        cout << "\n";
}
void Datos::buscarPorPuertoDestino(int puertoDestinoBuscado)
{
    int current, countTotal = 0;
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
    if (countTotal == 0)
        std::cout << "No existen registros con este puerto destino" << std::endl;
    else
        cout << "\n";
}
void Datos::buscarPorHostnameDestino(string hostnameDestinoBuscado)
{
    int current, countTotal = 0;
    std::cout << "Logs con hostname destino '" << hostnameDestinoBuscado << "':" << endl;
    for (int i = 0; i < conexiones.size(); i++)
    {
        if (hostnameDestinoBuscado == conexiones[i].getHostnameDestino())
        {
            std::cout << "---------------------------------------------" << std::endl;
            conexiones[i].displayInfo();
            std::cout << "---------------------------------------------" << std::endl;
            countTotal++;
        }
    }
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