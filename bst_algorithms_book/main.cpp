
#include "bst.h"

#include <iostream>
#include <string>
#include <map>

using namespace std;


int main()
{
    
    while(true) {
        BST<int, char> bst;
        bst.insert(4,'d');
        bst.insert(2,'b');
        bst.insert(3,'c');
        bst.insert(7,'g');
        bst.insert(8,'h');
        bst.insert(6,'f');
        bst.insert(5,'e');
    }
    

    return 0;
}
