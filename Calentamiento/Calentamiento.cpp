#include <iostream>
#include <string>

using namespace std;

// 1-------------------------------------------------------------------------

void bisiesto()
{
    int year = 0;
    std::cout << "Introduce el año: ";
    cin >> year;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0))
        std::cout << "El año " << year << " es bisiesto" << std::endl;
    else
        std::cout << "El año no es biciesto" << std::endl;
}

// 2-------------------------------------------------------------------------

void suma()
{
    int *numeros;
    int cantidad = 0, numActual = 0, resultado = 0;
    std::cout << "Cuántos numeros quieres introducir?\t";
    cin >> cantidad;
    numeros = new int[cantidad];
    std::cout << "Introduce los " << cantidad << " numeros" << std::endl;
    for (int i = 0; i < cantidad; i++)
    {
        cin >> numActual;
        numeros[i] = numActual;
    }
    std::cout << "La suma de los numeros ";
    for (int i = 0; i < cantidad; i++)
    {
        cout << numeros[i] << " ";
        resultado += numeros[i];
    }
    std::cout << "es " << resultado << std::endl;
    delete[] numeros;
}

// 3-------------------------------------------------------------------------

// void vectorRepetidas()
// {
//     vector<string> palabras;
//     string oracion, palabra, palabraVector = "";
//     int count = 0;
//     std::cout << "Introduce una oración:\t";
//     getline(cin, oracion);
//     std::cout << "Introduce una palabra:\t";
//     cin>>palabra;
//     for (int i = 0; i <= oracion.length(); i++)
//     {
//         if (oracion[i] == ' ' || oracion[i]=='\0')
//         {
//             if (palabraVector != "")
//                 palabras.push_back(palabraVector);
//             palabraVector = "";
//         }
//         else
//             palabraVector+=oracion[i];
//     }
//     for (int i = 0; i < palabras.size(); i++)
//     {
//         if (palabras[i] == palabra)
//             count++;
//     }
//     std::cout << "La palabra '"<< palabra<<"' se repite "<< count<<" veces"<< std::endl;
// }

void repetidas()
{
    string palabra, oracion;
    int count = 0, j = 0, i = 0;
    cin.ignore();
    std::cout << "Introduce una oración:\t";
    getline(cin, oracion);
    std::cout << "Introduce una palabra:\t";
    cin >> palabra;
    for (i = 0; i < palabra.length(); i++)
    {
        if (oracion[i] != palabra[i])
            break;
    }
    if (i == palabra.length())
        count++;
    i = 0;

    for (i = 0; i < oracion.length(); i++)
    {
        if ((oracion[i - 1] == 32 && oracion[i] == palabra[0]) && (oracion[i + palabra.length()] == 32 || oracion[i + palabra.length()] == '\0'))
        {
            for (j = 0; j < palabra.length(); j++)
            {
                if (oracion[i + j] == palabra[j])
                    continue;
                break;
            }
            if (j == palabra.length())
                count++;
        }
    }
    std::cout << "La palabra '" << palabra << "' se repite " << count << " veces" << std::endl;
}

// 4-------------------------------------------------------------------------

template <class C>
class Calculadora
{
public:
    C sumar(C a, C b) { return a + b; };
    C restar(C a, C b) { return a - b; };
    C dividir(C a, C b) { return a / b; };
    C multiplicar(C a, C b) { return a * b; };
};

// 5-------------------------------------------------------------------------

class Animal
{
public:
    int patas;
    bool pelo;
    string llanto;
    void hacerRuido() { std::cout << llanto << std::endl; }
};

class Perro : public Animal
{
public:
    Perro() { llanto = "woof"; };
};
class Gato : public Animal
{
public:
    Gato() { llanto = "meow"; };
};
class Perico : public Animal
{
public:
    Perico() { llanto = "krraaa"; };
};
class Serpiente : public Animal
{
public:
    Serpiente() { llanto = "ssssss"; };
};

template <class T>
class Veterinario
{
public:
    void inyectarAnimal(T animal) { animal.hacerRuido(); };
};
// main----------------------------------------------------------------------

int main()
{
    // bisiesto();
    suma();
    repetidas();
    // Calculadora<int> calc;
    // cout<<calc.sumar(5,4)<<"\n";
    // Calculadora<float> cal;
    // cout<<cal.dividir(5.4,3.2);
    // Perro a;
    // Gato b;
    // Serpiente c;
    // Veterinario<Perro> veta;
    // veta.inyectarAnimal(a);
    // Veterinario<Gato> vetb;
    // vetb.inyectarAnimal(b);
    // Veterinario<Serpiente> vetc;
    // vetc.inyectarAnimal(c);
    return 0;
}
