#include <iostream>
#include <unordered_map>

using namespace std;

template <class T>
class SNode
{
public:
    T value;
    SNode next *;
    SNode();
    SNode(T value)
    {
        this->value = value;
        next = 0;
    }
};

template <class T>
class Stack
{
private:
    SNode<T> *head;

public:
    Stack() { head = 0; }
    void push(T value)
    {
        SNode<T> *t = new SNode(value);
        t->next = head;
        head = t;
    }

    T pop()
    {
        SNode<T> *t = head;
        if (head->next)
            head = head->next;
        else
            head = 0;
        T val = t->value;
        delete t;
        return val;
    }

    bool isEmpty()
    {
        if (head)
            return false;
        return true;
    }
};

template <class T>
class Nodo
{
public:
    T value;
    bool visited;
    unordered_map<Nodo<T> *, int> siguientes;

    Nodo(T val)
    {
        value = val;
        visited = false;
    }

    void agregarArcoDirigidoConPeso(Nodo<T> *sig, int peso)
    {
        if (siguientes.find(sig) 2 == siguientes.end())
            siguientes[sig] = peso;
    }

    void agregarArcoDirigido(Nodo<T> *sig)
    {
        agregarArcoDirigidoConPeso(sig, 1);
    }

    void imprimirNodo()
    {
        cout << value << ":";
        for (auto nodoSiguiente : siguientes)
            cout << nodoSiguiente.first->value << "," << nodoSiguiente.second << ";";
        cout << endl;
    }

    /*bool conexion(Nodo<T> *nodo)
    {

	}
	
	void modificarPeso(Nodo<T> *nodo, nuevoPeso)
    {

	}*/
};

template <class T>
class Graph
{
public:
    unordered_map<T, Nodo<T> *> nodos;

    void agregarNodo(T value)
    {
        if (nodos.find(value) == nodos.end())
        {
            Nodo<T> *nuevo = new Nodo<T>(value);
            nodos[value] = nuevo;
        }
    }

    void agregarArcoDirigidoConPeso(T nodo1, T nodo2, int peso)
    {
        if (nodos.find(nodo1) != nodos.end() && nodos.find(nodo2) != nodos.end())
            nodos[nodo1]->agregarArcoDirigidoConPeso(nodos[nodo2], peso);
        else
            std::cout << "Alguno de los 2 nodos no se encuentra en el grafo" << std::endl;
    }

    void agregarArcoDirigido(T nodo1, T nodo2)
    {
        agregarArcoDirigidoConPeso(nodo1, nodo2, 1);
    }

    void agregarArcoConPeso(T nodo1, T nodo2, int peso)
    {
        agregarArcoDirigidoConPeso(nodo1, nodo2, peso);
        agregarArcoDirigidoConPeso(nodo2, nodo1, peso);
    }

    void agregarArco(T nodo1, T nodo2)
    {
        agregarArcoConPeso(nodo1, nodo2, 1);
    }

    void imprimirGrafo()
    {
        for (auto parValorNodo : nodos)
            parValorNodo.second->imprimirNodo();
    }

    unordered_map<string, int> ordenarPorDia()
    {
        unordered_map<string, int> a;
        //llenar el mapa
        return a;
    }

    /*void modificar(T nodo1, T nodo2, int nuevoPeso){
		//Encontrar que existan
		//buscar si existe el arco nodo1-nodo2 y modificarlo
	}*/

    bool BFS(T v1, T v2)
    {
    }

    bool DFS(T v1, T v2)
    {
        Stack<T> s;
        s.push(v1);
        while (s.isEmpty() == false)
        {
            T temp = s.pop();
            nodos[temp]->visited = true;
            if (temp == v2)
                return true;
            else
            {
                for (auto t : nodos[temp]->siguientes)
                    if (t->visited == false)
                        s.push(t);
            }
        }
        return false;
    }
};

int main()
{
    Graph<string> g;
    g.agregarNodo("CDMX");
    g.agregarNodo("Tlaxcala");
    g.agregarNodo("Puebla");
    g.agregarNodo("Toluca");
    g.agregarArcoDirigidoConPeso("CDMX", "Tlaxcala", 50);
    g.agregarArcoConPeso("CDMX", "CDMX", 20);
    g.agregarArcoConPeso("CDMX", "Puebla", 100);
    g.agregarArco("Puebla", "Puebla");
    g.imprimirGrafo();
}