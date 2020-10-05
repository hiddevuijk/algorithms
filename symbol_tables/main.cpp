#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "item.h"

using namespace std;

int main()
{


    Item item;


    item.rand();
    cout << "item was " << item << endl;
    
    
    return 0;
}
