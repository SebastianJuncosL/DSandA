#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Conexion.h"
#pragma once
using namespace std;
class Datos
{
private:
    vector<Conexion> conexiones;
    int noDeDatos;

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
    void buscarPorFecha(string);
    void buscarPorIpFuente(string);
    void buscarPorPuertoFuente(int);
    void buscarPorHostnameFuente(string);
    void buscarPorIpDestino(string);
    void buscarPorPuertoDestino(int);
    void buscarPorHostnameDestino(string);
    // Metodo para imprimir los primeros N datos
    void displayN(int);
    // Metodo para conseguir el número de Datos
    int getNoDeDatos() { return noDeDatos; }
};