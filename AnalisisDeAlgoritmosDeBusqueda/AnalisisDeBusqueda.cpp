#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
using namespace std;
using namespace std::chrono;
template <class T>
class Busqueda
{
private:
    vector<T> elementos;

public:
    Busqueda();
    int busquedaSecuencial(T buscado);
    int busquedaOrdenada1(T buscado);
    int busquedaOrdenada2(T buscado);
    int busquedaBinaria(T buscado);
};

template <class T>
Busqueda<T>::Busqueda()
{
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(1, 1000000);
    for (int i = 0; i < 100000; i++)
    {
        elementos.push_back(distribution(generator));
    }
    sort(elementos.begin(), elementos.end());
    // cout << elementos[10] << " " << elementos[5030] << " " << elementos[99999] << endl;
}

template <class T>
int Busqueda<T>::busquedaSecuencial(T buscado)
{
    for (int i = 0; i < elementos.size(); i++)
    {
        if (elementos[i] == buscado)
            return i;
    }
    return -1;
}

template <class T>
int Busqueda<T>::busquedaOrdenada1(T buscado)
{
    for (int i = 0; i < elementos.size(); i++)
    {
        if (elementos[i] > buscado)
            return -1;
        if (elementos[i] == buscado)
            return i;
    }
    return -1;
}

template <class T>
int Busqueda<T>::busquedaOrdenada2(T buscado)
{
    int paso = 2;
    int inicio = 0;
    int fin;
    while (inicio < elementos.size())
    {
        fin = inicio + paso;
        if (fin > elementos.size())
            fin = elementos.size();
        if (elementos[fin - 1] >= buscado)
        {
            for (int i = inicio; i < fin; i++)
            {
                if (elementos[i] == buscado)
                    return i;
            }
            return -1;
        }
        inicio = fin;
    }
    return -1;
}

template <class T>
int Busqueda<T>::busquedaBinaria(T buscado)
{
    int inicio = 0;
    int fin = elementos.size() - 1;
    if (buscado > elementos[fin] || buscado < elementos[inicio])
        return -1;
    while (fin >= inicio)
    {
        int medio = (inicio + fin) / 2;
        if (elementos[medio] == buscado)
            return medio;
        else if (buscado > elementos[medio])
            inicio = medio + 1;
        else
            fin = medio - 1;
    }
    return -1;
}

int main()
{
    Busqueda<int> a;
    // Numeros a buscar: 71, 51015, 999993, 1236194
    int buscado = 1236194;
    int x;
    //Busqueda secuencial
    cout << "Secuencial ";
    auto inicio = high_resolution_clock::now();
    x = a.busquedaSecuencial(buscado);
    auto fin = high_resolution_clock::now();
    auto tiempo = duration_cast<microseconds>(fin - inicio).count();
    cout << "posicion: " << x << ", tiempo: " << tiempo << endl;
    //Busqueda Ordenada 1
    cout << "Ordenada 1 ";
    inicio = high_resolution_clock::now();
    x = a.busquedaOrdenada1(buscado);
    fin = high_resolution_clock::now();
    tiempo = duration_cast<microseconds>(fin - inicio).count();
    cout << "posicion: " << x << ", tiempo: " << tiempo << endl;
    //Busqueda Ordenada 2
    cout << "Ordenada 2 ";
    inicio = high_resolution_clock::now();
    x = a.busquedaOrdenada2(buscado);
    fin = high_resolution_clock::now();
    tiempo = duration_cast<microseconds>(fin - inicio).count();
    cout << "posicion: " << x << ", tiempo: " << tiempo << endl;
    //Busqueda binaria
    cout << "Binaria ";
    inicio = high_resolution_clock::now();
    x = a.busquedaBinaria(buscado);
    fin = high_resolution_clock::now();
    tiempo = duration_cast<microseconds>(fin - inicio).count();
    cout << "posicion: " << x << ", tiempo: " << tiempo << endl;
    return 0;
}