
#include "insertion_sort.h"
#include "quick_sort.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>

#include <ctime>

using namespace std;

template< class Item>
bool sorted(Item a[], int N) {
    for(int i=1;i<N; ++i)
        if( a[i-1] > a[i] ) return false;
    return true;
}

int main()
{
    int N = 50000000;
    int *a = new int[N];


    for(int i=0;i<N; ++i) a[i] = i - ( i % 100 ) + (i%3) - (i%5) + (i%8) - (i%11) - (i%30) + (i%41) - (i%53) - (i%63);
    //for(int i=0;i<N; ++i) a[i] = i;
    //for(int i=0; i<N; ++i) cout << a[i] << endl;


    //shuffle(a,0,N-1);

    time_t ti, tf;
    time(&ti);

    //sort(a, a+N);
    quick_sort(a,0,N-1);

    time(&tf);


    cout << endl;
    cout << sorted(a, N) << endl;

    cout << endl << difftime(tf,ti) << endl;
    return 0;
}


