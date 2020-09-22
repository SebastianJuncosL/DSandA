#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Conexion.h"
#pragma once
using namespace std;
class Datos
{
private:
    vector<Conexion> conexiones;

public:
    Datos();
    void importarDatos(string);
    // Metodos de ordenamiento utilizando Selection Sort
    void ordenarPorFecha();
    void ordenarPorIpFuente();
    void ordenarPorPuertoFuente();
    void ordenarPorHostnameFuente();
    void ordenarPorIpDestino();
    void ordenarPorPuertoDestino();
    void ordenarPorHostnameDestino();
    // Metodos de búsqueda utilizando Binary Search
    void buscarPorFecha();
    void buscarPorIpFuente();
    void buscarPorPuertoFuente();
    void buscarPorHostnameFuente();
    void buscarPorIpDestino();
    void buscarPorPuertoDestino();
    void buscarPorHostnameDestino();
};