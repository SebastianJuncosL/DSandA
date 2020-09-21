#include <iostream>
#include <vector>
#include "Conexion.h"
#pragma once
using namespace std;
class Datos
{
private:
    vector<Conexion> conexiones;

public:
    Datos();
    Datos(string, string, string, int, string, string, int, string);
    void importarDatos();
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