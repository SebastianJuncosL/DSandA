#include "BST.cpp"
#include <iostream>
using namespace std;

int main()
{
    BST<int> a;
    a.add(50);
    a.add(20);
    a.add(70);
    a.add(10);
    a.add(30);
    a.add(60);
    a.add(80);
    //a.imprimirTodoElArbol(a.getRoot());
    // 1
    //cout << a.profundidad(10) << endl;
    // 2
    //cout << a.altura(a.root) << endl;
    // 3
    //cout << a.alturaArbol() << endl;
    // 4
    //a.descendientes(50);
    // 5
    //a.ancestros(10);
    // 6
    //a.checarAncestro(50,10);
    // 7
    // arreglar
    //a.mismoNivel(10);
    // 9
    //a.hermanos(10, 30);
    // 10
    //a.hermano(20);
    return 0;
}
