
#include "bst.h"

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main()
{

    BST<int, char> bst;

    bst.insert(4,'d');
    bst.insert(2,'b');
    bst.insert(3,'c');
    bst.insert(7,'g');
    bst.insert(8,'h');
    bst.insert(6,'f');
    bst.insert(5,'e');
    

    bst.print_in_order(cout);
    bst.remove(5);
    cout << endl;
    bst.print_in_order(cout);
    

    return 0;
}
