#include <iostream>
#include <unordered_map>

using namespace std;

template <class T>
class SNode
{
public:
    T value;
    SNode *next;
    SNode() {}
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
        SNode<T> *t = new SNode<T>(value);
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
class QNode
{
public:
    T value;
    QNode *next;
    QNode *prev;
    QNode(){};
    QNode(T val)
    {
        value = val;
        next = NULL;
        prev = NULL;
    }
};

template <class T>
class Queue
{
public:
    QNode<T> *front;
    QNode<T> *back;
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void enqueue(T value)
    {
        QNode<T> *nuevo = new QNode<T>(value);
        if (back == NULL)
        {
            back = nuevo;
            front = back;
        }
        else
        {
            back->next = nuevo;
            nuevo->prev = back;
            back = nuevo;
        }
    }

    T dequeue()
    {
        QNode<T> *t = front;
        if (front->next)
            front = front->next;
        else
            front = back = 0;
        T value = t->value;
        delete t;
        return value;
    }

    bool isEmpty()
    {
        if (back)
        {
            return false;
        }
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
        if (siguientes.find(sig) == siguientes.end())
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

    bool BFS(T v1, T v2)
    {
        quitarVisita();
        Queue<T> s;
        s.enqueue(v1);
        while (s.isEmpty() == false)
        {
            T temp = s.dequeue();
            //std::cout << temp << std::endl;
            nodos[temp]->visited = true;
            if (temp == v2)
                return true;
            else
            {
                for (auto t : nodos[temp]->siguientes)
                {
                    if (t.first->visited == false)
                        s.enqueue(t.first->value);
                }
            }
        }
        return false;
    }

    bool DFS(T v1, T v2)
    {
        quitarVisita();
        Stack<T> s;
        s.push(v1);
        while (s.isEmpty() == false)
        {
            T temp = s.pop();
            //std::cout << temp << std::endl;
            nodos[temp]->visited = true;
            if (temp == v2)
                return true;
            else
            {
                for (auto t : nodos[temp]->siguientes)
                {
                    if (t.first->visited == false)
                        s.push(t.first->value);
                }
            }
        }
        return false;
    }

    void quitarVisita()
    {
        for (auto t : nodos)
        {
            t.second->visited = false;
        }
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
    bool x = g.DFS("CDMX", "Puebla");
    if (x == true)
        std::cout << "si" << std::endl;
    else
        std::cout << "no" << std::endl;

    x = g.BFS("CDMX", "Toluca");
    if (x == true)
        std::cout << "si" << std::endl;
    else
        std::cout << "no" << std::endl;
}