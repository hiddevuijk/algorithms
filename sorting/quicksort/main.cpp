
#include "insertion_sort.h"
#include "quick_sort.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <math.h>

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

    for(int i=0;i<N; ++i) a[i] = i;


    shuffle(a,0,N-1);
    quick_sort(a,0,N-1);

    cout << endl;
    cout << sorted(a, N) << endl;

    return 0;
}


