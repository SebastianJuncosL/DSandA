#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Prueba
{
private:
    string conexiones[100000];

public:
    Prueba();
    void cargarDatos();
    void mostrarDominios();
    bool find(string, string);
    void hashing(string);
};

Prueba::Prueba()
{
    for (int i = 0; i < 100000; i++)
    {
        conexiones[i] = "/////";
    }
}

void Prueba::cargarDatos()
{
    ifstream fileIn;
    fileIn.open("equipo 4.csv");
    string line, partes;
    string valores[9];
    int i = 0;
    string current;
    int cont = 0, totalDeValores = 0;
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
        if (valores[7].size() > 3 && find(valores[7], "reto.com") == false)
            hashing(valores[7]);
        if (find(valores[4], "reto.com") == false)
        {
            conexiones[cont] = valores[4];
            cont++;
        }
        totalDeValores++;
        i = 0;
    }
    std::cout << totalDeValores << std::endl;
}

void Prueba::mostrarDominios()
{
    for (int i = 0; i < 100000; i++)
    {
        if (conexiones[i] != "/////")
            std::cout << conexiones[i] << ", ";
    }
    std::cout << "" << std::endl;
}

bool Prueba::find(string searchHere, string searching)
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

void Prueba::hashing(string toInsert)
{
    int pos = toInsert[0] + toInsert[1] + toInsert[2];
    if (conexiones[pos] == "/////")
    {
        conexiones[pos] = toInsert;
        return;
    }
    if (conexiones[pos] == toInsert)
        return;
    else if (conexiones[pos] != "/////" && conexiones[pos] != toInsert)
    {
        for (int i = pos; i < 100000; i++)
        {
            if (conexiones[pos] == "/////")
            {
                conexiones[pos] = toInsert;
                break;
            }
        }
    }
}

int main()
{
    Prueba a;
    a.cargarDatos();
    a.mostrarDominios();
    // a.mostrarFuente();
    return 0;
}