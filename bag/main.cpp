#include <iostream>
#include <string>

#include "stack_array.h"


using namespace std;



int main()
{

    int N = 20;

	Stack<int> stack;
    for( int i=0; i< N; ++i ) stack.push(i+1);

    Stack<int>::Iterator it = stack.begin();
    for( int i=0; i<N; ++i) {
        cout << *it << endl;
        ++it;
    }

	return 0;
}
