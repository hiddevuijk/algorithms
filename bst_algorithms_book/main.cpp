
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
        bst.insert(5,'e');
        bst.empty();
    }
    

    return 0;
}
