#include "Conexiones.h"

ConexionesComputadora::ConexionesComputadora()
{
    ip = "-";
    nombre = "vacío";
    conexionesEntrantes = conexionesSalientes = 0;
    cEnCount = cSaCount = 0;
}

ConexionesComputadora::ConexionesComputadora(string nombre, string terminacion)
{
    ip = "192.168.112." + terminacion;
    this->nombre = nombre;
    conexionesEntrantes = conexionesSalientes = 0;
    cEnCount = cSaCount = 0;
}

ConexionesComputadora::ConexionesComputadora(string terminacion)
{
    ip = "192.168.112." + terminacion;
    nombre = "vacio";
    conexionesEntrantes = conexionesSalientes = 0;
    cEnCount = cSaCount = 0;
}

ConexionesComputadora::~ConexionesComputadora()
{
    Node<string> *p;
    while (conexionesEntrantes)
    {
        p = conexionesEntrantes;
        conexionesEntrantes = conexionesEntrantes->next;
        delete p;
    }
    while (conexionesSalientes)
    {
        p = conexionesSalientes;
        conexionesSalientes = conexionesSalientes->next;
        delete p;
    }
    std::cout << "Conexion eliminada" << std::endl;
}

void ConexionesComputadora::obtenerConexionesE()
{
    ifstream fileIn;
    fileIn.open("equipo 4.csv");
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
        if (valores[5] == ip)
        {
            if (conexionesEntrantes == 0)
            {
                Node<string> *t = new Node<string>;
                t->data = valores[2];
                t->next = 0;
                conexionesEntrantes = t;
            }
            else
            {
                Node<string> *t = new Node<string>;
                t->data = valores[2];
                t->next = conexionesEntrantes;
                conexionesEntrantes = t;
            }
            cEnCount++;
        }
        i = 0;
    }
}

void ConexionesComputadora::obtenerConexionesS()
{
    ifstream fileIn;
    fileIn.open("equipo 4.csv");
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
        if (valores[2] == ip)
        {
            if (conexionesSalientes == 0)
            {
                Node<string> *t = new Node<string>;
                t->data = valores[5];
                t->next = 0;
                conexionesSalientes = t;
            }
            else
            {
                Node<string> *t = new Node<string>;
                Node<string> *p = conexionesSalientes;
                t->data = valores[5];
                t->next = 0;
                while (p->next)
                    p = p->next;
                p->next = t;
            }
            cSaCount++;
        }
        i = 0;
    }
}

void ConexionesComputadora::printConexionesE()
{
    Node<string> *p = conexionesEntrantes;
    while (p)
    {
        if (p->next)
            cout << p->data << ", ";
        else
            cout << p->data << "\n";
        p = p->next;
    }
    cout << "\nHay " << cEnCount << " conexiones entrantes\n";
}

void ConexionesComputadora::printConexionesS()
{
    Node<string> *p = conexionesSalientes;
    while (p)
    {
        if (p->next)
            cout << p->data << ", ";
        else
            cout << p->data << "\n";
        p = p->next;
    }
    cout << "\nHay " << cSaCount << " conexiones salientes\n";
}

void ConexionesComputadora::repeatedConnections()
{
    if (conexionesSalientes != 0 && cSaCount >= 3)
    {
        Node<string> *p = conexionesSalientes;
        int cont = 0;
        while (p->next->next)
        {
            if (p->data == p->next->data && p->next->data == p->next->next->data)
                cont++;
            p = p->next;
        }
        if(cont == 0)
            std::cout << "No hay mas de 3 conexiones salientes a una pagina" << std::endl;
        else  
            std::cout << "Hay "<< cont<< " conexiones salientes que ocurren 3 veces seguidas" << std::endl;
    }
    else
        std::cout << "No hay mas de 3 conexiones salientes desde esta computadora" << std::endl;
}