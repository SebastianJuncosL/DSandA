#include "Datos.h"

Datos::Datos()
{
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
    conexiones[0].displayInfo();
    conexiones[99].displayInfo();
}

// Metodos de ordenamiento utilizando Selection Sort
void Datos::ordenarPorFecha()
{
}

void Datos::ordenarPorIpFuente()
{
}

void Datos::ordenarPorPuertoFuente()
{
}

void Datos::ordenarPorHostnameFuente()
{
}

void Datos::ordenarPorIpDestino()
{
}

void Datos::ordenarPorPuertoDestino()
{
}

void Datos::ordenarPorHostnameDestino()
{
}

// Metodos de búsqueda utilizando Binary Search
void Datos::buscarPorFecha()
{
}
void Datos::buscarPorIpFuente()
{
}
void Datos::buscarPorPuertoFuente()
{
}
void Datos::buscarPorHostnameFuente()
{
}
void Datos::buscarPorIpDestino()
{
}
void Datos::buscarPorPuertoDestino()
{
}
void Datos::buscarPorHostnameDestino()
{
}