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

// void palabraRepetida()
// {
//     string palabra;
//     string oracion;
//     int count = 0;
//     int j=0;
//     char dummy;
//     std::cout << "Introduce una oración:\t";
//     getline(cin, oracion);
//     std::cout << "Introduce una palabra:\t";
//     cin>>palabra;
//     int palabraLength = palabra.length();
//     // for (char const &c:oracion)
//     // {
//     //     if (c == palabra[i])
//     //     {
//     //         count++;
//     //         i++;
//     //     }
//     //     else if(c!= palabra[i])
//     //         i=0;
//     //     if (i<= palabraLength)
//     //     {
            
//     //         cout<<c<<" "<<i<<" "<<count<<"\n";
//     //         i=0;
//     //     } 
//     // }

//     // for(char const &c:oracion)
//     // {
//     //     dummy = c;
//     //     if(c==palabra[0])
//     //     {
//     //         dummy=oracion[c+palabraLength];
//     //         std::cout << dummy << std::endl;
//     //         if(dummy == palabra[palabraLength-1])
//     //             count++;            
//     //     }
//     //     cout<<c<<"\n";
//     // }
//     std::cout << "La palabra '"<< palabra<<"' se repite "<< count<<" veces"<< std::endl;
//     char dummy2;
//     for(char const &c:oracion)
//     {
//         j++;
//         if(c == palabra[0])
//         {
//             for (int i = 0; i < palabraLength; i++)
//             {
//                 dummy=palabra[i];
//                 dummy2=oracion[j+i];
//                 cout<<dummy2<<"\n";
//             }
//             if(dummy==dummy2)
//                 count++;
//         }
//     }
// }

// 4-------------------------------------------------------------------------



// 5-------------------------------------------------------------------------

class Animal
{
    
};

// main----------------------------------------------------------------------

int main(int argc, char const *argv[])
{
    bisiesto();
    suma();
    return 0;
}
