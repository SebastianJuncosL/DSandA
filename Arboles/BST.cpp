#include "Node.h"
#include <iostream>
using namespace std;
template <class T>
class BST
{
public:
    Node<T> *root;

    BST()
    {
        root = 0;
    }
    void add(T data)
    {
        Node<T> *t = root;
        Node<T> *p;
        Node<T> *r;

        if (root == 0)
        {
            p = new Node<T>;
            p->value = data;
            p->lchild = 0;
            p->rchild = 0;
            root = p;
            return;
        }

        while (t != 0)
        {
            r = t;
            if (data < t->value)
                t = t->lchild;
            else if (data > t->value)
                t = t->rchild;
            else
                return;
        }
        p = new Node<T>;
        p->value = data;
        p->lchild = 0;
        p->rchild = 0;

        if (data < r->value)
            r->lchild = p;
        else
            r->rchild = p;
    }

    void imprimirTodoElArbol(Node<T> *p)
    {
        if (p)
        {
            std::cout << p->value << " " << std::endl;
            imprimirTodoElArbol(p->lchild);
            imprimirTodoElArbol(p->rchild);
        }
    }

    int profundidad(T data)
    {
        int cont = 0;
        Node<T> *t = root;
        while (t)
        {
            if (data > t->value)
            {
                cont++;
                t = t->rchild;
            }
            else if (data < t->value)
            {
                cont++;
                t = t->lchild;
            }
            else
            {
                return cont;
            }
        }
        return -1;
    }

    int altura(Node<T> *t)
    {
        int x = 0, y = 0;
        if (t == 0)
            return 0;
        x = altura(t->lchild);
        y = altura(t->rchild);
        if (x > y)
            return x + 1;
        else
            return y + 1;
    }

    int alturaArbol()
    {
        if (root != 0)
            return altura(root);
        return -1;
    }

    void descendientes(T value)
    {
        Node<T> *t = root;
        if (t == 0)
            return;
        while (t)
        {
            if (value > t->value)
                t = t->rchild;
            else if (value < t->value)
                t = t->lchild;
            else
            {
                postorder(t, t);
                return;
            }
        }
    }
    void postorder(Node<T> *p, Node<T> *original)
    {
        if (p)
        {
            postorder(p->lchild, original);
            postorder(p->rchild, original);
            if (p->value != original->value)
                std::cout << p->value << " " << std::endl;
        }
    }

    void ancestros(T value)
    {
        if (find(value) == false)
            std::cout << "Ese valor no existe en el arbol" << std::endl;
        else
        {
            Node<T> *t = root;
            if (t == 0)
            {
                std::cout << "Ese valor no existe en el arbol" << std::endl;
                return;
            }
            while (t)
            {
                if (value > t->value)
                {
                    std::cout << t->value << ", ";
                    t = t->rchild;
                }
                else if (value < t->value)
                {
                    std::cout << t->value << ", ";
                    t = t->lchild;
                }
                else
                {
                    break;
                }
            }
        }
    }
    bool find(T value)
    {
        Node<T> *t = root;
        if (t == 0)
            return false;
        while (t)
        {
            if (value > t->value)
                t = t->rchild;
            else if (value < t->value)
                t = t->lchild;
            else
                return true;
        }
        return false;
    }

    void checarAncestro(T ancestro, T descendiente)
    {
        if (find(descendiente) == true)
        {
            Node<T> *t = root;
            while (t)
            {
                if (t->value == ancestro)
                {
                    std::cout << ancestro << " si es ancestro de " << descendiente << std::endl;
                    return;
                }
                if (descendiente > t->value)
                    t = t->rchild;
                else if (descendiente < t->value)
                    t = t->lchild;
                else
                    break;
            }
            std::cout << ancestro << " no es ancestro de " << descendiente << std::endl;
        }
        else
            std::cout << "El nodo descendiente que buscas no existe en el arbol" << std::endl;
    }

    void mismoNivel(T value)
    {
        if (find(value) == false)
        {
            std::cout << "El nodo no existe" << std::endl;
            return;
        }
        Node<T> *t = root;
        int level = 1;
        while (t)
        {
            if (value > t->value)
            {
                level++;
                t = t->rchild;
            }
            else if (value < t->value)
            {
                level++;
                t = t->lchild;
            }
            else
                break;
        }
        inorderByLevel(root, level, 1, value);
    }
    void inorderByLevel(Node<T> *p, int desired, int currentL,T searched)
    {
        if (p)
        {
            if (currentL == desired && p->value!= searched)
                std::cout << p->value << endl;
            currentL++;
            inorderByLevel(p->lchild, desired, currentL, searched);
            inorderByLevel(p->rchild, desired, currentL, searched);
        }
    }

    void hermanos(T a, T b)
    {
        Node<T> *t = root;
        Node<T> *r;
        if (t == 0)
            return;
        while (t->lchild || t->rchild)
        {
            r = t;
            if (a > t->value)
                t = t->rchild;
            else if (a < t->value)
                t = t->lchild;
            else if (t->value == a)
                break;
        }
        if (r->lchild == 0 || r->rchild == 0)
        {
            std::cout << "No son hermanos" << std::endl;
            return;
        }
        if (r->lchild->value == a)
        {
            if (r->rchild->value == b)
                std::cout << "Si son hermanos" << std::endl;
            else
                std::cout << "No son hermanos" << std::endl;
        }
        else if (r->rchild->value == a)
        {
            if (r->lchild->value == b)
                std::cout << "Si son hermanos" << std::endl;
            else
                std::cout << "No son hermanos" << std::endl;
        }
    }

    void hermano(T a)
    {
        Node<T> *t = root;
        Node<T> *r;
        if (t == 0)
            return;
        while (t->lchild || t->rchild)
        {
            r = t;
            if (a > t->value)
                t = t->rchild;
            if (a < t->value)
                t = t->lchild;
            if (t->value == a)
                break;
        }
        if (r->lchild->value == a)
        {
            if (r->rchild)
                std::cout << r->rchild->value << std::endl;
        }
        else if (r->rchild->value == a)
        {
            if (r->lchild)
                std::cout << r->lchild->value << std::endl;
        }
    }
};
