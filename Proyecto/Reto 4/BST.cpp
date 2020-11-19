#include "Node.cpp"
#include <iostream>

class BST
{
public:
    Node *root;
    BST() { root = 0; }
    void insert(string host, int conexiones)
    {
        Node *t = root;
        Node *p;
        Node *r;

        if (root == 0)
        {
            p = new Node;
            p->noConex = conexiones;
            p->host = host;
            p->lchild = p->rchild = 0;
            root = p;
            return;
        }

        while (t != 0)
        {
            r = t;
            if (conexiones < t->noConex)
                t = t->lchild;
            else if (conexiones > t->noConex)
                t = t->rchild;
            else
                return;
        }
        p = new Node;
        p->noConex = conexiones;
        p->host = host;
        p->lchild = p->rchild = 0;

        if (conexiones < r->noConex)
            r->lchild = p;
        else
            r->rchild = p;
    }

    void imprimirTodoElArbol()
    {
        preorder(root);
    }
    void preorder(Node *p)
    {
        if (p)
        {
            std::cout << p->host << ": " << p->noConex << std::endl;
            preorder(p->lchild);
            preorder(p->rchild);
        }
    }
};