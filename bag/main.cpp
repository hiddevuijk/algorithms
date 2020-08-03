#include <iostream>
#include <string>

#include "bag_array.h"


using namespace std;



int main()
{

    int N = 20;

	Bag<int> b;
    for( int i=0; i< N; ++i ) b.push(i+1);

    Bag<int>::Iterator it = b.begin();
    for( int i=0; i<N; ++i) {
        cout << *it << endl;
        ++it;
    }

	return 0;
}
