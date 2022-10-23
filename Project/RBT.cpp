#include "RBT.hpp"
template <class T>
RBT<T>::RBT() : Tree<T>()
{
}

template <class T>
void RBT<T>::PREORDER1(Node<T> *ptr) //NLR
{
    if (ptr != nullptr)
    {

        int x = ptr->count;
        while(x != 0){
            cout << ptr->data << "   c:" << ptr->colour  << endl;
            x--;
        }
        PREORDER1(ptr->left);
        PREORDER1(ptr->right);
        
    }
}

template <class T>
void RBT<T>::preorder1() 
{
    if (Tree<T>::root == nullptr)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        cout<<" Postorder 1 NLR "<<endl;
        PREORDER1(Tree<T>::root);
    }
}

template <class T>
void RBT<T>::PREORDER2(Node<T> *ptr) //NRL
{
    if (ptr != nullptr)
    {

        int x = ptr->count;
        while(x != 0)
        {
            cout << ptr->data << "   c:" << ptr->colour  << endl;
            x--;
        }
        PREORDER2(ptr->right);
        PREORDER2(ptr->left);

    }
}

template <class T>
void RBT<T>::preorder2()
{
    if (Tree<T>::root == nullptr)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        cout<<" Preorder 2 NRL "<<endl;
        PREORDER2(Tree<T>::root);
    }
}

template <class T>
void RBT<T>::POSTORDER1(Node<T> *ptr) //LRN
{
    if (ptr != nullptr)
    {
        POSTORDER1(ptr->left);
        POSTORDER1(ptr->right);

        int x = ptr->count;
        while(x != 0){
            cout << ptr->data << "   c:" << ptr->colour  << endl;
            x--;
        }
    }
}

template <class T>
void RBT<T>::postorder1()
{
    if (Tree<T>::root == nullptr)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        cout<<" Postorder 1 LRN "<<endl;
        POSTORDER1(Tree<T>::root);
    }
}

template <class T>
void RBT<T>::POSTORDER2(Node<T> *ptr) //RLN
{
    if (ptr != nullptr)
    {

        POSTORDER2(ptr->right);
        POSTORDER2(ptr->left);
        int x = ptr->count;
        while(x != 0){
            cout << ptr->data << "   c:" << ptr->colour  << endl;
            x--;
        }
    }
}

template <class T>
void RBT<T>::postorder2()
{
    if (Tree<T>::root == nullptr)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        cout<<" Postorder 2 RLN "<<endl;
        POSTORDER2(Tree<T>::root);
    }
}

template <class T>
void RBT<T>::INORDER2(Node<T> *ptr ) //RNL
{ 
    if (ptr != nullptr)
    {
        INORDER2(ptr->right);
        int x = ptr->count;
        while(x != 0){
            cout << ptr->data << "   c:" << ptr->colour  << endl;
            x--;
        }
        INORDER2(ptr->left);
    }
}

template <class T>
void RBT<T>::inorder2()
{
    if (Tree<T>::root == nullptr)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        cout<<" Inorder 2 RNL "<<endl;
        INORDER2(Tree<T>::root);
    }
}

template <class T>
void RBT<T>::check(Node<T> *ptr)
{
    
    if (ptr->left != nullptr)
    {
        if (ptr->left->colour == 'R' && ptr->colour == 'R')
        {
            // cout << "PTR LEFT = " << ptr->left->data << " c:" << ptr->left->colour << ".  PTR = " << ptr->data << " c:" << ptr->colour << endl;
            // cout << "Issue is Found!!!!!!!!" << endl;

            Node<T> *t = ptr->left;
            Node<T> *P = Tree<T>::root;
            Node<T> *G = Tree<T>::root;
            Node<T> *GG = Tree<T>::root;
            Node<T> *U = nullptr;

            while (1)
            {
                if (ptr->data > P->data)
                {
                    GG = G;
                    G = P;
                    P = P->right;
                }
                else if (ptr->data < P->data)
                {
                    GG = G;
                    G = P;
                    P = P->left;
                }
                else if (ptr == P)
                {
                    if (G->right == P && G->left != nullptr)
                    {
                        U = G->left;
                    }
                    if (G->left == P && G->right != nullptr)
                    {
                        U = G->right;
                    }

                    //Check Values of Family
                    // cout << "1...G.   Grand P = " << GG->data << ".   c: " << GG->colour << endl;
                    // cout << "2...Grand P = " << G->data << ".   c: " << G->colour << endl;
                    // cout << "3...Parent = " << P->data << ".   c: " << P->colour << endl;
                    // if (U != nullptr)
                    // {
                    //     cout << "4...Uncle = " << U->data << ".   c: " << U->colour << endl;
                    // }

                    //ALL CASES

                    if (U == nullptr)
                    {

                        //CASE - 4
                        if (G->left == P && P->right == t)
                        {
                            Node<T> *tt = P;
                            t->left = P;
                            G->left = t;
                            P->right = nullptr;
                            P = t;
                            t = tt;
                        }
                        if (G->right == P && P->left == t)
                        {
                            Node<T> *tt = P;
                            t->right = P;
                            G->right = t;
                            P->left = nullptr;
                            P = t;
                            t = tt;
                        }

                        //Case - 5
                        if (G->left == P && P->left == t)
                        {
                            if (G != Tree<T>::root)
                            {
                                if (G == GG->right)
                                {
                                    GG->right = P;
                                }
                                else
                                {
                                    GG->left = P;
                                }
                            }
                            G->left = P->right;
                            P->right = G;

                            //Re-Color after a CASE 4,5
                            P->colour = 'B';
                            G->colour = 'R';
                            if (G == Tree<T>::root)
                            {
                                Tree<T>::root = P;
                            }
                        }
                        if (G->right == P && P->right == t)
                        {
                            if (G != Tree<T>::root)
                            {
                                if (G == GG->right)
                                {
                                    GG->right = P;
                                }
                                else
                                {
                                    GG->left = P;
                                }
                            }
                            G->right = P->left;
                            P->left = G;
                            //Re-Color after a CASE 4,5
                            P->colour = 'B';
                            G->colour = 'R';
                            if (G == Tree<T>::root)
                            {
                                Tree<T>::root = P;
                            }
                        }
                    }
                    else if (U->colour == 'B')
                    {
                        //CASE - 4
                        if (G->left == P && P->right == t)
                        {
                            Node<T> *tn = P;
                            t->left = P;
                            G->left = t;
                            P->right = nullptr;
                            P = t;
                            t = tn;
                        }
                        if (G->right == P && P->left == t)
                        {
                            Node<T> *tn = P;

                            t->right = P;
                            G->right = t;
                            P->left = nullptr;
                            
                            P = t;
                            t = tn;
                        }

                        //Case - 5
                        if (G->left == P && P->left == t)
                        {
                            if (G != Tree<T>::root)
                            {
                                if (G == GG->right)
                                {
                                    GG->right = P;
                                }
                                else
                                {
                                    GG->left = P;
                                }
                            }

                            G->left = P->right;
                            P->right = G;

                            //Re-Color after a CASE 4,5
                            P->colour = 'B';
                            G->colour = 'R';

                            if (G == Tree<T>::root)
                            {
                                Tree<T>::root = P;
                            }
                        }
                        if (G->right == P && P->right == t)
                        {
                            if (G != Tree<T>::root)
                            {
                                if (G == GG->right)
                                {
                                    GG->right = P;
                                }
                                else
                                {
                                    GG->left = P;
                                }
                            }

                            G->right = P->left;
                            P->left = G;

                            //Re-Color after a CASE 4,5
                            P->colour = 'B';
                            G->colour = 'R';
                            if (G == Tree<T>::root)
                            {
                                Tree<T>::root = P;
                            }
                        }
                    }
                    else
                    {
                        //Color Cases
                        if (U->colour == 'R' && G == Tree<T>::root)
                        {
                            U->colour = 'B';
                            P->colour = 'B';
                        }
                        else if (U->colour == 'R' && G != Tree<T>::root)
                        {
                            G->colour = 'R';
                            U->colour = 'B';
                            P->colour = 'B';
                        }
                    }

                    ptr = Tree<T>::root;
                    break;
                }
            }
        }
        check(ptr->left);
    }
    
    if (ptr->right != nullptr)
    {
        if (ptr->right->colour == 'R' && ptr->colour == 'R')
        {
            // cout << "PTR Right = " << ptr->right->data << ".  PTR = " << ptr->data << endl;
            // cout << "Issue is Found!!!!!!!!" << endl;

            Node<T> *t = ptr->right;
            Node<T> *P = Tree<T>::root;
            Node<T> *G = Tree<T>::root;
            Node<T> *GG = Tree<T>::root;
            Node<T> *U = nullptr;

            while (1)
            {
                if (ptr->data > P->data)
                {
                    GG = G;
                    G = P;
                    P = P->right;
                }
                else if (ptr->data < P->data)
                {
                    GG = G;
                    G = P;
                    P = P->left;
                }
                else if (ptr == P)
                {
                    if (G->right == P && G->left != nullptr)
                    {
                        U = G->left;
                    }
                    if (G->left == P && G->right != nullptr)
                    {
                        U = G->right;
                    }


                    // cout << "1...G.   Grand P = " << GG->data << ".   c: " << GG->colour << endl;
                    // cout << "2...Grand P = " << G->data << ".   c: " << G->colour << endl;
                    // cout << "3...Parent = " << P->data << ".   c: " << P->colour << endl;
                    // if (U != nullptr)
                    // {
                    //     cout << "4...Uncle = " << U->data << ".   c: " << U->colour << endl;
                    // }

                    //ALL CASES

                    if (U == nullptr)
                    {

                        //CASE - 4
                        if (G->left == P && P->right == t)
                        {
                            Node<T> *tt = P;
                            t->left = P;
                            G->left = t;
                            P->right = nullptr;
                            P = t;
                            t = tt;
                        }
                        if (G->right == P && P->left == t)
                        {
                            Node<T> *tt = P;
                            t->right = P;
                            G->right = t;
                            P->left = nullptr;
                            P = t;
                            t = tt;
                        }

                        //Case - 5
                        if (G->left == P && P->left == t)
                        {
                            if (G != Tree<T>::root)
                            {
                                if (G == GG->right)
                                {
                                    GG->right = P;
                                }
                                else
                                {
                                    GG->left = P;
                                }
                            }
                            G->left = P->right;
                            P->right = G;

                            //Re-Color after a CASE 4,5

                            P->colour = 'B';
                            G->colour = 'R';
                            if (G == Tree<T>::root)
                            {
                                Tree<T>::root = P;
                            }
                        }
                        if (G->right == P && P->right == t)
                        {
                            if (G != Tree<T>::root)
                            {
                                if (G == GG->right)
                                {
                                    GG->right = P;
                                }
                                else
                                {
                                    GG->left = P;
                                }
                            }
                            G->right = P->left;
                            P->left = G;
                            //Re-Color after a CASE 4,5
                            P->colour = 'B';
                            G->colour = 'R';
                            if (G == Tree<T>::root)
                            {
                                Tree<T>::root = P;
                            }
                        }
                    }
                    else if (U->colour == 'B')
                    {
                        //CASE - 4
                        if (G->left == P && P->right == t)
                        {
                            Node<T> *tn = P;
                            
                            t->left = P;
                            G->left = t;
                            P->right = nullptr;

                            P = t;
                            t = tn;
                        }
                        if (G->right == P && P->left == t)
                        {
                            Node<T> *tn = P;
                            
                            t->right = P;
                            G->right = t;
                            P->left = nullptr;

                            P = t;
                            t = tn;
                        }

                        //Case - 5
                        if (G->left == P && P->left == t)
                        {

                            if (G != Tree<T>::root)
                            {
                                if (G == GG->right)
                                {
                                    GG->right = P;
                                }
                                else
                                {
                                    GG->left = P;
                                }
                            }

                            G->left = P->right;
                            P->right = G;

                            //Re-Color after a CASE 4,5
                            P->colour = 'B';
                            G->colour = 'R';

                            if (G == Tree<T>::root)
                            {
                                Tree<T>::root = P;
                            }
                        }
                        if (G->right == P && P->right == t)
                        {

                            if (G != Tree<T>::root)
                            {
                                if (G == GG->right)
                                {
                                    GG->right = P;
                                }
                                else
                                {
                                    GG->left = P;
                                }
                            }
                            G->right = P->left;
                            P->left = G;

                            //Re-Color after a CASE 4,5
                            P->colour = 'B';
                            G->colour = 'R';
                            if (G == Tree<T>::root)
                            {
                                Tree<T>::root = P;
                            }
                        }
                    }
                    else
                    {
                        //Color Cases
                        if (U->colour == 'R' && G == Tree<T>::root)
                        {
                            U->colour = 'B';
                            P->colour = 'B';
                        }
                        else if (U->colour == 'R' && G != Tree<T>::root)
                        {
                            G->colour = 'R';
                            U->colour = 'B';
                            P->colour = 'B';
                        }
                    }

                    ptr = Tree<T>::root;
                    break;
                }
            }
        }
        check(ptr->right);

    }
}

template <class T>
void RBT<T>::DESTROYTREE(Node<T> *ptr)
{
    if (ptr != nullptr)
    {
        DESTROYTREE(ptr->left);
        DESTROYTREE(ptr->right);
        Node<T> *t = ptr;
        if (ptr == Tree<T>::root)
        {
            Tree<T>::root = nullptr;
        }
        delete t;
        t = nullptr;
    }
}

template <class T>
void RBT<T>::DestroyTree()
{
    if (Tree<T>::root == nullptr)
    {
        cout << "It's already NULL" << endl;
    }
    else
    {
        DESTROYTREE(Tree<T>::root);
        cout<<"Tree is Destroyed!"<<endl;
    }
}

template <class T>
void RBT<T>::DELETEDUPLI(Node<T> *ptr)
{
    if (ptr != nullptr)
    {
        DELETEDUPLI(ptr->left);
        ptr->count = 1;
        DELETEDUPLI(ptr->right);
    }
}

template <class T>
void RBT<T>::DeleteDuplicates()
{
    if (Tree<T>::root == nullptr)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        DELETEDUPLI(Tree<T>::root);
        cout<<"Duplicates has been Deleted!"<<endl;
    }
}

template <class T>
void RBT<T>::CHANGECOUNT(Node<T> *ptr, T value)
{
    if (ptr != nullptr)
    {
        CHANGECOUNT(ptr->left, value);
        if (value == ptr->data)
        {
            ptr->count++;
        }
        CHANGECOUNT(ptr->right, value);
    }
}

template <class T>
void RBT<T>::changeCount(T val)
{
    if (Tree<T>::root == nullptr)
    {
        cout << "Root is empty";
    }
    else
    {

        CHANGECOUNT(Tree<T>::root, val);
    }
}


template <class T>
bool RBT<T>::search(T value)
{
    if (Tree<T>::root == nullptr)
    {
        return false;
    }
    else
    {
        Node<T>* t = Tree<T>::root;

        while(1){
            if(value > t->data){
                if(t->right == nullptr){
                    return false;
                }
                t = t->right;
            }else if(value < t->data){
                if(t->left == nullptr){
                    return false;
                }
                t = t->left;
            }else{
                return true;
            }
        }
        
    }
}

template <class T>
void RBT<T>::Root()
{
    if (Tree<T>::root == nullptr)
    {
        cout << "Root = NullPtr\n";
    }
    else
    {
        cout << "Root = " << Tree<T>::root->data << endl;
    }
}

template <class T>
void RBT<T>::INORDER1(Node<T> *Ptr) //LNR
{
    if (Ptr != nullptr)
    {
        INORDER1(Ptr->left);
        int x = Ptr->count;
        while(x != 0){
            cout << Ptr->data << "   c:" << Ptr->colour  << endl;
            x--;
        }
        
        INORDER1(Ptr->right);
    }
}

template <class T>
void RBT<T>::inorder1()
{
    if (Tree<T>::root == nullptr)
    {
        cout << "Empty!" << endl;
    }
    else
    {
        cout<<" Inorder 1 LNR "<<endl;
        INORDER1(Tree<T>::root);
    }
}

template <class T>
void RBT<T>::insert(T value)
{
    if (search(value))
    {
        // cout<<value<<endl;
        // cout << "IT'S ALREADY AVAILABLE ---" <<value<< endl;
        changeCount(value);
    }
    else
    {

        Node<T> *nn = new Node<T>;
        nn->colour = 'R';
        nn->left = nullptr;
        nn->right = nullptr;
        nn->data = value;
        nn->count = 1;

        if (Tree<T>::root == nullptr)
        {
            nn->colour = 'B';
            Tree<T>::root = nn;
        }
        else
        {


            
            Node<T> *P = Tree<T>::root;
            Node<T> *GG = Tree<T>::root;
            Node<T> *G = Tree<T>::root;
            Node<T> *U = nullptr;

            while (1)
            {
                if (value >= P->data)
                {
                    if (P->right == nullptr)
                    {
                        P->right = nn;
                        break;
                    }
                    GG = G;
                    G = P;
                    P = P->right;
                }
                else
                {
                    if (P->left == nullptr)
                    {
                        P->left = nn;
                        break;
                    }
                    GG = G;
                    G = P;
                    P = P->left;
                }
            }

            if (G->right == P && G->left != nullptr)
            {
                U = G->left;
            }
            if (G->left == P && G->right != nullptr)
            {
                U = G->right;
            }

            // TO KNOW THE FAMILY
            //cout << value << " is Added"<< endl;
            // cout << "G.   Grand P = " << GG->data << ".   c: " << GG->colour << endl;
            // cout << "Grand P = " << G->data << ".   c: " << G->colour << endl;
            // cout << "Parent = " << P->data << ".   c: " << P->colour << endl;
            // if (U != nullptr)
            // {

            //     cout << "Uncle = " << U->data << ".   c: " << U->colour << endl;
            // }
            // else
            // {

            //     cout << "Uncle = NULLPTR" << endl;
            // }

            if (P->colour == 'R')
            {

                //ROTATION CASES

                if (U == nullptr)
                {

                    //CASE - 4
                    if (G->left == P && P->right == nn)
                    {
                        Node<T> *t = P;
                        nn->left = P;
                        G->left = nn;
                        P->right = nullptr;
                        P = nn;
                        nn = t;
                    }
                    else if (G->right == P && P->left == nn)
                    {
                        Node<T> *t = P;
                        nn->right = P;
                        G->right = nn;
                        P->left = nullptr;
                        P = nn;
                        nn = t;
                    }

                    //Case - 5
                    if (G->left == P && P->left == nn)
                    {
                        if (G != Tree<T>::root)
                        {
                            if (G == GG->right)
                            {
                                GG->right = P;
                            }
                            else if(G == GG->left)
                            {
                                GG->left = P;
                            }
                        }
                        G->left = P->right;
                        P->right = G;

                        //Re-Color after a CASE 4,5
                        P->colour = 'B';
                        G->colour = 'R';
                        if (G == Tree<T>::root)
                        {
                            Tree<T>::root = P;
                        }
                    }
                    else if (G->right == P && P->right == nn)
                    {
                        if (G != Tree<T>::root)
                        {

                            if (G == GG->right)
                            {
                                GG->right = P;
                            }
                            else if(G == GG->left)
                            {
                                GG->left = P;
                            }
                        }
                        G->right = P->left;
                        P->left = G;
                        //Re-Color after a CASE 4,5
                        P->colour = 'B';
                        G->colour = 'R';
                        if (G == Tree<T>::root)
                        {
                            Tree<T>::root = P;
                        }
                    }
                }

                else if (U->colour == 'B')
                {
                    //CASE - 4
                    if (G->left == P && P->right == nn)
                    {
                        Node<T> *t = P;
                        nn->left = P;
                        G->left = nn;
                        P->right = nullptr;
                        P = nn;
                        nn = t;
                    }
                    if (G->right == P && P->left == nn)
                    {
                        Node<T> *t = P;
                        nn->right = P;
                        G->right = nn;
                        P->left = nullptr;
                        P = nn;
                        nn = t;
                    }

                    //Case - 5
                    if (G->left == P && P->left == nn)
                    {
                        if (G != Tree<T>::root)
                        {
                            if (G == GG->right)
                            {
                                GG->right = P;
                            }
                            else if(G == GG->left)
                            {
                                GG->left = P;
                            }
                        }
                        G->left = P->right;
                        P->right = G;

                        //Re-Color after a CASE 4,5
                        P->colour = 'B';
                        G->colour = 'R';

                        if (G == Tree<T>::root)
                        {
                            Tree<T>::root = P;
                        }
                    }
                    if (G->right == P && P->right == nn)
                    {
                        if (G != Tree<T>::root)
                        {
                            if (G == GG->right)
                            {
                                GG->right = P;
                            }
                            else if(G == GG->left)
                            {
                                GG->left = P;
                            }
                        }
                        G->right = P->left;
                        P->left = G;

                        //Re-Color after a CASE 4,5
                        P->colour = 'B';
                        G->colour = 'R';
                        if (G == Tree<T>::root)
                        {
                            Tree<T>::root = P;
                        }
                    }
                }
                else
                {
                    //Color Cases
                    if (U->colour == 'R' && G == Tree<T>::root)
                    {
                        U->colour = 'B';
                        P->colour = 'B';
                    }
                    else if (U->colour == 'R' && G != Tree<T>::root)
                    {
                        G->colour = 'R';
                        U->colour = 'B';
                        P->colour = 'B';
                    }
                }
            }

            check(Tree<T>::root);
            
        }
    }
}

template <class T>
void RBT<T>::readFile(RBT &obj)
{
    ifstream fin;
    fin.open("Text.txt");
    T x ;
    if (fin.is_open())
    {
        //cout << "Exist file\n";
        while (!fin.eof())
        {
            fin >> x;
            //cout << x << endl;

            obj.insert(x);
        }
        cout<<"Data has been Capture from the File"<<endl;
    }
    else
    {
        cout << "File Not found\n";
    }
}