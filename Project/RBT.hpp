#include "Tree.hpp"
template <class T>
class RBT : public Tree<T>
{
private:
    //ORDER TRAVERSAL
    void INORDER1(Node<T> *ptr);
    void INORDER2(Node<T> *ptr);
    void PREORDER1(Node<T>* ptr);
    void PREORDER2(Node<T>* ptr);
    void POSTORDER1(Node<T>* ptr);
    void POSTORDER2(Node<T>* ptr);


    void CHANGECOUNT(Node<T> *ptr, T );
    void DELETEDUPLI(Node<T> *ptr);
    void DESTROYTREE(Node<T> *ptr);
    void check(Node<T> *ptr);

public:
    RBT();
    void insert(T);

    void Root();
    void readFile(RBT &obj);
    bool search(T);
    void changeCount(T val);
    void DeleteDuplicates();
    void DestroyTree();

    //ORDER TRAVERSAL
    void inorder1();   //LRN
    void preorder1();  //NLR
    void postorder1(); //LRN

    void inorder2();   //RNL
    void preorder2();  //NRL
    void postorder2(); //RLN
};