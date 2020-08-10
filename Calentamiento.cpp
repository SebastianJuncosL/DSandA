#include <iostream>
#include <string>
using namespace std;

// 1-------------------------------------------------------------------------

void bisiesto()
{
    int year=0;
    std::cout << "Introduce el año: ";
    cin>> year;
    if(year%4==0 && year%100!=0)
        std::cout << "El año "<< year << " es bisiesto" << std::endl;
    else if(year%4 == 0 && year%100 == 0 && year%400 == 0)
        std::cout << "El año "<< year << " es bisiesto" << std::endl;
    else 
        std::cout << "El año no es biciesto" << std::endl;
}

// 2-------------------------------------------------------------------------

void suma()
{
    int *numeros;
    int cantidad = 0, numActual = 0, resultado;
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
    std::cout << "es "<< resultado << std::endl;
    delete []numeros;
}

// 3-------------------------------------------------------------------------

void repetidas()
{
    string palabra, oracion;
    int letters=0, count =0, j=0,k=0;
    std::cout << "Introduce una oración:\t";
    getline(cin, oracion);
    std::cout << "Introduce una palabra:\t";
    cin>>palabra;
    for (int i = 0; i < oracion.length(); i++)
    {
        cout<<oracion[i]<<"\n";
        if ((oracion[i] == palabra[0] && oracion[i-1] == ' ')||(oracion[0] == palabra[0]))
        {
            j=i;
            k=j+(palabra.length()-1);
            if(oracion[j] == palabra[0] && oracion[k] == palabra[palabra.length()-1])
                count++;
        }
        else   
            continue;
    }
    std::cout << "La palabra '"<< palabra<<"' se repite "<< count<<" veces"<< std::endl;
}

// 4-------------------------------------------------------------------------



// 5-------------------------------------------------------------------------

class Animal
{
    
};

// main----------------------------------------------------------------------

int main(int argc, char const *argv[])
{
    repetidas();
    return 0;
}
