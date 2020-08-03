#include <string>
#include <iostream>
#include <fstream>

#include "queue_ll.h"

using namespace std;


int main()
{
    Queue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    Queue<int>::Iterator it = q.begin();
    Queue<int>::Iterator end = q.end();
    while( it != end ) {
        cout << *it << endl;
        ++it;
    }

	return 0;
}
