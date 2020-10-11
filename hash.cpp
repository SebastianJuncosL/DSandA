#include <iostream>
#include <unordered_set>
using namespace std;

unordered_set<int> unir(unordered_set<int> A, unordered_set<int> B)
{
    unordered_set<int> C;
    for (int value : A)
    {
        C.insert(value);
    }
    for (int value : B)
    {
        C.insert(value);
    }
    return C;
}

unordered_set<int> disjoint(unordered_set<int> A, unordered_set<int> B)
{
    unordered_set<int> C;
    for (int value : A)
    {
        if (B.find(value) != B.end())
            continue;
        else
            C.insert(value);
    }
    for (int value : B)
    {
        if (A.find(value) != A.end())
            continue;
        else
            C.insert(value);
    }
    return C;
}