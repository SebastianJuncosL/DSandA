#include <iostream>
#include <string>
using namespace std;

// 1-------------------------------------------------------------------------

void bisisto()
{
    int year;
    std::cout << "Introduce el año: ";
    cin>> year;
    if(year%4==0 && year%100!=0)
    {
        std::cout << "El año "<< year << " es bisiesto" << std::endl;
        return;
    }
    if(year%4 == 0 && year%100 == 0 && year%400 == 0)
    {
        std::cout << "El año "<< year << " es bisiesto" << std::endl;
        return;
    }
}

// 2-------------------------------------------------------------------------

void suma()
{
    int *numeros;
    int cantidad = 0;
    int numActual = 0;
    int resultado;
    std::cout << "Cuántos numeros quieres introducir?\t";
    cin>> cantidad;
    numeros = new int[cantidad];
    std::cout << "Introduce los "<< cantidad<< " numeros" << std::endl;
    for (int i = 0; i < cantidad; i++)
    {
        cin>>numActual;
        numeros[i] = numActual;
    }
    std::cout << "La suma de los numeros ";
    for (int i = 0; i < cantidad; i++)
    {
        cout<<numeros[i]<<" ";
        resultado+=numeros[i];
    }
    std::cout << " es "<< resultado << std::endl;
    delete []numeros;
}

// 3-------------------------------------------------------------------------
