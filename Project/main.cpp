#include "Link-RBT.hpp"

int main()
{
    int NUM = 0;

    RBT<int> obj;


    while (1)
    {
        cout << "Press 1 to insert values in the tree (one by one)" << endl;
        cout << "Press 2 for searching a value from the tree" << endl;
        cout << "Press 3 for pre-order traversal NLR" << endl;
        cout << "Press 4 for in-order traversal LNR" << endl;
        cout << "Press 5 for post-order traversal LRN" << endl;
        cout << "Press 6 for pre-order traversal 2 NRL" << endl;
        cout << "Press 7 for in-order traversal 2 RNL" << endl;
        cout << "Press 8 for post-order traversal 2 RLN" << endl;
        cout << "Press 9 for displaying parent of a node present in Tree" << endl;
        cout << "Press 10 to Read int value from the file input.txt to create a red-black tree" << endl;
        cout << "Press 11 to delete all duplicate values from the tree" << endl;
        cout << "Press 12 to destroy the complete tree" << endl;
        cout << "Press 13 to EXIT" << endl;

        cout << "PRESS ANY KEY TO OPERATE" << endl;
        cin >> NUM;



        if (NUM == 1)
        {
            int value ;
            cout << "Enter a Value to Insert in the Tree" << endl;
            cin >> value;
            obj.insert(value);
            cout << value << " Value is Inserted" << endl;
        }
        else if (NUM == 2)
        {
            int value ;
            cout << "Enter a Value to Search in the Tree" << endl;
            cin >> value;

            if (obj.search(value))
            {
                cout << "Yes " << value << " is Available"<<endl;
            }
            else
            {
                cout << "NO " << value << " isn't Available"<<endl;
            }
        }
        else if (NUM == 3)
        {
            obj.preorder1();
        }
        else if (NUM == 4)
        {
            obj.inorder1();
        }
        else if (NUM == 5)
        {
            obj.postorder1();
        }
        else if (NUM == 6)
        {
            obj.preorder2();
        }
        else if (NUM == 7)
        {
            obj.inorder2();
        }
        else if (NUM == 8)
        {
            obj.postorder2();
        }
        else if (NUM == 9)
        {
            obj.Root();
        }
        else if (NUM == 10)
        {
            
            obj.readFile(obj);
            
        }
        else if (NUM == 11)
        {
            obj.DeleteDuplicates();
            
        }
        else if (NUM == 12)
        {
            obj.DestroyTree();
            
        }
        else if (NUM == 13)
        {
            cout << "EXITED Code Using " << NUM << endl;
            break;
        }
        else
        {
            cout << "Enter a Valid Number!" << endl;
        }
        cout<<"______________________________________________________________________________"<<endl;
        cout<<"______________________________________________________________________________"<<endl;
    }

    return 0;
}