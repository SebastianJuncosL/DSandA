#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>
#include "BST.cpp"
#include "Conexion.cpp"
#include "ConexionesPag.cpp"

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
            valores[7] = valores[7].substr(0, valores[7].size() - 1);
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
    //cout << conexiones.size() << endl;
}

bool find(string searchHere, string searching)
{
    int j = 1, finalLen = 6;
    bool found;
    for (int i = 1; i < searchHere.size(); i++)
    {
        if (searchHere[i] == searching[j] && searchHere[i - 1] == searching[j - 1])
            j++;
    }
    if (j >= finalLen)
        return true;
    return false;
}
unordered_map<string, ConexionesPag> cc;
unordered_map<string, int> cE;
unordered_map<string, int> conexionesPorDia(string date)
{
    for (Conexion a : conexiones)
    {
        if (a.fecha == date && a.hostnameDestino != "-" && find(a.hostnameDestino, "reto.com") == false)
        {
            if (cc.find(a.hostnameDestino) == cc.end())
            {
                ConexionesPag b(a.hostnameDestino);
                cc[a.hostnameDestino] = b;
            }
            cc[a.hostnameDestino].agregarE(a.hostnameFuente);
        }
    }
    for (auto it = cc.begin(); it != cc.end(); it++)
        cE[it->first] = cc[it->first].conexE;
    return cE;
}

bool top(int n, string fecha)
{
    conexionesPorDia(fecha);
    BST pag;
    map<int, vector<string>> dominios;
    for (auto it = cE.begin(); it != cE.end(); it++)
    {
        pag.insert(it->first, it->second);
        dominios[it->second].push_back(it->first);
    }
    int cont = 0;
    for (auto it = dominios.rbegin(); it != dominios.rend(); it++)
    {
        if (cont < n)
        {
            cout << it->first << ":";
            for (string s : dominios[it->first])
            {
                cout << s << ", ";
                cont++;
            }
            if (cont >= n)
            {
                cout << endl;
                return true;
            }
            cout << endl;
        }
        else
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    importarDatos("equipo 4.csv");
    vector<string> fechas;
    fechas.push_back(conexiones[0].fecha);
    for (Conexion a : conexiones)
    {
        if (fechas[fechas.size() - 1] != a.fecha)
            fechas.push_back(a.fecha);
    }
    for (int i = 0; i < fechas.size(); i++)
    {
        cout << "---- " << fechas[i] << " ----" << endl;
        top(4, fechas[i]);
        cout << endl;
    }

    return 0;
}
