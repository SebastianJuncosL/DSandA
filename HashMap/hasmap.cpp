#include <iostream>
#include <string>
#include <vector>

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

    void append(T value)
    {
        Node<T> *t = new Node<T>;
        t->data = value;
        t->next = 0;
        if (head == 0)
            head = t;
        else
        {
            Node<T> *traverse = head;
            while (traverse->next)
                traverse = traverse->next;
            traverse->next = t;
        }
    }

    void printList()
    {
        Node<T> *dummy = head;
        if (dummy == 0)
            return;
        else
        {
            while (dummy)
            {
                std::cout << dummy->data << ", ";
                dummy = dummy->next;
            }
        }
    }

    void deleteList()
    {
        Node<T> *t = head, *tail;
        head = 0;
        if (head == 0)
            return;
        while (t)
        {
            tail = t;
            t = t->next;
            delete tail;
        }
    }
};

class hashMap
{
public:
    LinkedList<int> hashM[10];

    void agregar(int x)
    {
        int pos = x % 10;
        hashM[pos].append(x);
    }

    void borrarLenP(int x)
    {
        int pos = x % 10;
        hashM[pos].deleteList();
    }

    void borrarT()
    {
        for (int i = 0; i < 10; i++)
        {
            hashM[i].deleteList();
        }
    }

    void printHM()
    {
        for (int i = 0; i < 10; i++)
        {
            std::cout << i + 1 << ": ";
            hashM[i].printList();
            cout << "\n";
        }
        cout << "\n";
    }
};

int main(int argc, char const *argv[])
{
    hashMap a;
    std::cout << "a" << std::endl;
    a.agregar(1);
    a.agregar(85);
    a.agregar(34);
    a.agregar(100);
    a.agregar(99);
    a.agregar(0);
    a.printHM();
    a.borrarLenP(0);
    a.printHM();
    a.borrarT();
    a.printHM();
    return 0;
}