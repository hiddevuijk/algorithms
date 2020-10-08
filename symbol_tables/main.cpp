#include "symbol_table.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>



using namespace std;

int main( int argc, char *argv[])
{

    ST<char, char> st;

    Item<char, char> item('s', 'S');
    st.insert(item);
    item = Item<char, char>('b', 'B');
    st.insert(item);
    
    item = Item<char, char>('z', 'Z');
    st.insert(item);
    item = Item<char, char>('r', 'R');
    st.insert(item);
    item = Item<char, char>('f', 'F');
    st.insert(item);
    item = Item<char, char>('i', 'I');
    st.insert(item);

    st.show(cout);
    cout << st.head->item.key() << endl;
    return 0;
    Item<char, char> ret = st.search('f');
    if( ret.null() ) cout << "fuck" << endl;
    else             cout << ret.val() << endl; 
    return 0;
}
