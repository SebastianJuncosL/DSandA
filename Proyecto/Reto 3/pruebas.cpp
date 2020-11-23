#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "Llaves.h"
#include "conexionesNoReto.cpp"
using namespace std;

// class Prueba
// {
// private:
//     string conexiones[100000];

// public:
//     Prueba();
//     void cargarDatos();
//     void mostrarDominios();
//     bool find(string, string);
//     void hashing(string);
// };

// Prueba::Prueba()
// {
//     for (int i = 0; i < 100000; i++)
//     {
//         conexiones[i] = "/////";
//     }
// }

// void Prueba::cargarDatos()
// {
//     ifstream fileIn;
//     fileIn.open("equipo 4.csv");
//     string line, partes;
//     string valores[9];
//     int i = 0;
//     string current;
//     int cont = 0, totalDeValores = 0;
//     while (fileIn.good())
//     {
//         getline(fileIn, line);
//         istringstream flujoEntrada(line);
//         while (getline(flujoEntrada, partes, ','))
//         {
//             valores[i] = partes;
//             i++;
//         }
//         if (valores[7].find('\r') != valores[7].npos)
//             valores[7] = valores[7].substr(0, valores[7].size() - 1);
//         if (valores[7].size() > 3 && find(valores[7], "reto.com") == false)
//             hashing(valores[7]);
//         if (find(valores[4], "reto.com") == false)
//         {
//             conexiones[cont] = valores[4];
//             cont++;
//         }
//         totalDeValores++;
//         i = 0;
//     }
//     std::cout << totalDeValores << std::endl;
// }

// void Prueba::mostrarDominios()
// {
//     for (int i = 0; i < 100000; i++)
//     {
//         if (conexiones[i] != "/////")
//             std::cout << conexiones[i] << ", ";
//     }
//     std::cout << "" << std::endl;
// }

// bool Prueba::find(string searchHere, string searching)
// {
//     int j = 1, finalLen = 8;
//     bool found;
//     for (int i = 1; i < searchHere.size(); i++)
//     {

//         if (searchHere[i] == searching[j] && searchHere[i - 1] == searching[j - 1])
//             j++;
//     }
//     if (j == finalLen)
//         return true;
//     return false;
// }

// void Prueba::hashing(string toInsert)
// {
//     int pos = toInsert[0] + toInsert[1] + toInsert[2];
//     if (conexiones[pos] == "/////")
//     {
//         conexiones[pos] = toInsert;
//         return;
//     }
//     if (conexiones[pos] == toInsert)
//         return;
//     else if (conexiones[pos] != "/////" && conexiones[pos] != toInsert)
//     {
//         for (int i = pos; i < 100000; i++)
//         {
//             if (conexiones[pos] == "/////")
//             {
//                 conexiones[pos] = toInsert;
//                 break;
//             }
//         }
//     }
// }

// Para el inciso 2------------------------------------------------------------

string generateKey(string hostName)
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
    }
    else
        return "-";
    return name;
}

vector<Llaves> cargarDatos()
{
    vector<Llaves> diccionario;
    ifstream fileIn;
    fileIn.open("equipo 4.csv");
    string line, partes, findKey = "";
    string valores[9];
    int i = 0, j = 0;
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
            valores[7] = valores[7].substr(0, valores[7].size() - 1);
        if (diccionario.size() == 0)
        {
            diccionario.push_back(Llaves(valores[4]));
            diccionario[0].insertarSaliente(valores[5], valores[7]);
            diccionario.push_back(Llaves(valores[7]));
            diccionario[1].insertarSaliente(valores[5], valores[7]);
        }
        else
        {
            int found = 1;
            findKey = generateKey(valores[4]);
            for (j = 0; j < diccionario.size(); j++)
            {
                if (diccionario[i].getKey() == findKey)
                {
                    std::cout << diccionario[i].getKey() << std::endl;
                    diccionario[i].insertarSaliente(valores[5], valores[7]);
                    found = 0;
                    break;
                }
            }
            if (found != 0)
            {
                //std::cout << "no lo encontramos, entonces lo agregamos" << std::endl;
                diccionario.push_back(Llaves(valores[4]));
                diccionario[diccionario.size() - 1].insertarSaliente(valores[5], valores[7]);
                found = 1;
            }
            findKey = generateKey(valores[7]);
            //std::cout << "buscamos host destion" << std::endl;
            for (j = 0; j < diccionario.size(); j++)
            {
                if (diccionario[i].getKey() == findKey)
                {
                    diccionario[i].insertarEntrante(valores[2], valores[4]);
                    j = 0;
                    found = 0;
                    break;
                }
                found++;
            }
            if (found != 0)
            {
                //std::cout << "no lo encontramos, entonces lo agregamos" << std::endl;
                diccionario.push_back(Llaves(valores[7]));
                diccionario[diccionario.size() - 1].insertarEntrante(valores[2], valores[4]);
                found = 1;//
            }
        }
        i = 0;
        if(diccionario.size() == 4)
            break;
    }
    return diccionario;
}

int main()
{
    // string host = generateKey("john.reto.com");
    // std::cout << host << std::endl;
    vector<Llaves> diccionario = cargarDatos();
    std::cout << diccionario.size() << std::endl;
    diccionario[0].mostrarIpsSalientes();
    diccionario[3].mostrarHostsEntrantes();

    return 0;
}