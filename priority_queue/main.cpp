
#include "priority_queue.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{

    PQ<int> pq(100); 

    int i;
    char c;
    for(;;) {

        cout << "Give me an integer: ";
        cin >> i;
        if( i < 0) {
            cout << "The largest int is: ";
            if( !pq.empty() ) {
                cout << pq.getmax() << endl;
            } else {
                cout << "Queue is empty" << endl;
            }
        } else { pq.insert(i); } 

    }

    return 0;
}
