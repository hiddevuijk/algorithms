#include "symbol_table.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>



using namespace std;

int main( int argc, char *argv[])
{

    ST<char, char> st;


    st.insert( 's', 's'); 
    st.insert( 'x', 'x'); 
    st.insert( 'e', 'e'); 
    st.insert( 'a', 'a'); 
    st.insert( 'r', 'r'); 
    st.insert( 'c', 'c'); 
    st.insert( 'h', 'h'); 
    st.insert( 'm', 'm'); 
    
    
    st.show(cout);
    st.deleteMax();
    st.deleteMax();
    cout << endl;
    st.show(cout);
    return 0;
}
