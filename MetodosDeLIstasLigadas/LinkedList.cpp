#include <iostream>
#include <string>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
};

template <class T>
class LinkedList
{
private:
    Node<T> *head;

public:
    LinkedList() { head = 0; }

    // Agrega un nuevo nodo al final de la lista
    // Complejidad Espacial = O(1); Temporal = O(n)
    void append(T value)
    {
        // Generamos el nuevo nodo a agregar
        Node<T> *t = new Node<T>;
        // Definimos los atributos del nodo
        t->data = value;
        t->next = 0;
        // Checamos que si haya valores en la lista
        if (head == 0)
            head = t;
        else
        {
            // Generamos un apuntador para recorrer la lista,
            // empezando en head
            Node<T> *traverse = head;
            while (traverse->next)
                traverse = traverse->next;
            // Agregamos el nodo al final de la lista
            traverse->next = t;
        }
    }

    // Contar el n;umero de veces que un elemento se repite
    // Complejidad Espacial = O(1); Temporal = O(n)
    int count(T searching)
    {
        // Inicializamos el contador y un apuntador para
        // recorrer la lista, empezanod en head
        int times = 0;
        Node<T> *p = head;
        // Checamos que si haya valores en la lista
        if (head == 0)
            return -1;
        // Iteramos en la lista
        while (p)
        {
            // Checamos si el valor del nodo es el mismo
            // valor que el buscado
            if (p->data == searching)
                times++;
            p = p->next;
        }
        // Regresamos el número de veces que se encuentra este valor
        return times;
    }

    // Borrar la lista y poner head en NULL
    // Complejidad Espacial = O(1); Temporal = O(n)
    void deleteList()
    {
        // Generamos 2 apuntadores, uno para no perder la lista,
        // y el otro para borrar los nodos "sueltos"
        Node<T> *t = head, *tail;
        head = 0;
        // Checamos que si haya valores en la lista
        if (head == 0)
            return;
        //Iteramos en la lista y borramos uno por uno
        while (t)
        {
            tail = t;
            t = t->next;
            delete tail;
        }
    }

    // Insertamos un nodo en una lista ordenada de menor a mayor
    // Complejidad Espacial = O(1); Temporal = O(n)
    void sortedInsert(T value)
    {
        // Generamos el nodo que queremos insertar
        Node<T> *inserted = new Node<T>;
        // Apuntadores para no perder los nodos que van junto al
        // nuevo nodo que se va a insertar
        Node<T> *p = head, *tail;
        // Asignamos los valores a los atributos del nuevo nodo
        inserted->data = value;
        inserted->next = 0;
        // Checamos que si haya valores en la lista
        if (head == 0)
            head = inserted;
        else
        {
            // Iteramos en la lista buscando donde insertar el nodo
            while (p && p->data < value)
            {
                tail = p;
                p = p->next;
            }
            // Si el nodo va al final, hacemos un append
            if (p == 0)
                tail->next = inserted;
            // Insertamos el nuevo nodo en medio de 2 nodos
            else
            {
                tail->next = inserted;
                inserted->next = p;
            }
        }
    }

    // Remover un valor duplicado en una lista ordenada
    // de menor a mayor
    // Complejidad Espacial = O(1); Temporal = O(n)
    void removeDuplicates()
    {
        // Generamos 2 apuntadores para borrar un nodo y
        // no perder los nodos que le siguen
        Node<T> *p, *tail;
        p = head;
        // Checamos que si haya valores en la lista
        if (head == 0)
            return;
        // Iteramos la lista
        while (p->next)
        {
            tail = p;
            p = p->next;
            // Checamos si 2 nodos consecutivos son iguales
            // y borramos uno si es el caso
            if (tail->data == p->data)
            {
                tail->next = p->next;
                delete p;
                p = tail->next;
            }
        }
    }

    // Invierte el orden de una lista
    // Complejidad Espacial = O(1); Temporal = O(n)
    void reverse()
    {
        // Generamos 3 nodos, uno que tiene el nuevo head,
        // y los otros 2 son para "cambiar la dierección de la lista"
        Node<T> *p, *tail, *lead;
        // Checamos que si haya valores en la lista
        if (head == 0)
            return;
        else
        {
            p = head;
            lead = head->next;
            // Iteramos la lista
            while (lead)
            {
                tail = p;
                p = lead;
                lead = lead->next;
                // Checamos el caso especial de head
                if (tail == head)
                    tail->next = 0;
                // voltemos en Nodo->next
                p->next = tail;
            }
            // Asignamos head al que anteriormente era el
            // ultimo nodo en nuestra lista, ya que esta
            // ya fue invertida
            head = p;
        }
    }

    // Impreme los nodos de una lista
    // Complejidad Espacial = O(1); Temporal = O(n)
    void printNodes()
    {
        Node<T> *p = head;
        // Checamos que si haya valores en la lista
        if (head == 0)
        {
            std::cout << "Linked list is empty" << std::endl;
            return;
        }
        // Iteramos la lista
        while (p)
        {
            // mostramos los nodos y usamos condicionales
            // para darle una mejor presentacion
            if (p->next != 0)
                std::cout << p->data << ", ";
            else
                std::cout << p->data << std::endl;
            p = p->next;
        }
    }
};

int main()
{
    LinkedList<int> *lista = new LinkedList<int>;
    lista->append(3);
    lista->append(5);
    lista->append(8);
    lista->append(8);
    lista->append(10);
    lista->append(15);

    // Imprimimos los nodos para comprobar que
    // la lista esté de manera correcta
    lista->printNodes();
    // 1.- Count()
    //cout << lista->count(8) << endl;
    // El metodo de DeleteList se encuentra al final
    // 3.- SortedInsert()
    //lista->sortedInsert(9);
    // 4-. Remove duplicates
    // lista->removeDuplicates();
    // 5.- Reverse()
    //lista->reverse();
    // Volvemos a imprimir la lista para ver los
    // cambios
    lista->printNodes();
    // 2.- DeleteList()
    lista->deleteList();
    // Checamos si la lista se borró de manera correcta
    lista->printNodes();
    return 0;
}