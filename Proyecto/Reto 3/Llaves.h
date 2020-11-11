#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "ConexionesComp.h"
using namespace std;

class Llaves
{
private:
    //Conexiones conexion;
    string key;
    string hostname;
    string ip;
    ConexionesComp conexiones;

public:
    Llaves();
    Llaves(string, string, string);
    string generateKey(string);
    void insertarEntrante(string, string);
    void insertarSaliente(string, string);
    string getKey();
    string getHostname();
    string getIP();
};
