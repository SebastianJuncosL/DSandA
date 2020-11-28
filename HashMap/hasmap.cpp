#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <unistd.h>

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
                if (dummy->next)
                    std::cout << dummy->data << ", ";
                else
                    std::cout << dummy->data;
                dummy = dummy->next;
            }
        }
    }

    bool find(T x)
    {
        Node<T> *dummy = head;
        while (dummy)
        {
            if (dummy->data == x)
                return true;
            dummy = dummy->next;
        }
        return false;
    }

    void deleteList()
    {
        Node<T> *t = head, *tail;
        head = 0;
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
        if (find(x))
            return;
        hashM[pos].append(x);
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

    bool find(int x)
    {
        int pos = x % 10;
        return hashM[pos].find(x);
    }

    void borrarLenP(int x)
    {
        int pos = x % 10;
        hashM[pos].deleteList();
    }

    void borrarT()
    {
        for (int i = 0; i < 10; i++)
            hashM[i].deleteList();
    }
};

int main(int argc, char const *argv[])
{
    hashMap a;
    for (int i = 0; i < 1000; i++)
    {
        srand(time(0));
        int val = rand() % 1000;
        a.agregar(val);

        unsigned int microsecond = 10000;
        usleep(microsecond); //sleeps for 3 second
    }
    a.printHM();
    a.borrarT();
    a.printHM();
    return 0;
}