
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

template< class Item>
bool sorted(Item a[], int N) {
    for(int i=1;i<N; ++i)
        if( a[i-1] > a[i] ) return false;
    return true;
}

int main()
{
    int N = 10000000;
    int *a = new int[N];

    for(int i=0;i<N; ++i) 
        a[i] =  (1- (int) (i%6) )*i ;

    for(int i=0;i<10; ++i) cout << a[i] << endl;
    merge_sort(a,0,N);
    cout << endl;
    for(int i=0;i<10; ++i) cout << a[i] << endl;

    cout << endl;
    cout << sorted(a, N) << endl;

    return 0;
}


