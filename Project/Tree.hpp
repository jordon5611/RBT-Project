#include "Node.hpp"
template <class T>
class Tree {
protected:
        Node<T>* root;
public:
        Tree();
        virtual void insert(T) = 0;
        virtual void inorder1() = 0;  //LNR
        virtual void preorder1() = 0; //NLR
        virtual void postorder1() = 0;//LRN

        virtual void inorder2() = 0;  //RNL
        virtual void preorder2() = 0; //NRL
        virtual void postorder2() = 0;//RLN
        virtual void Root() = 0;
        virtual bool search(T) = 0;
        virtual void changeCount(T val) = 0;
        virtual void DeleteDuplicates() = 0;
        virtual void DestroyTree() = 0;
};

template <class T>
Tree<T>::Tree(){

    root = nullptr;
}