#include <iostream>
#include <fstream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    char colour;
    int count;
};
