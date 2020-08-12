

#include "heapsort.h"

#include <iostream>
#include <fstream>
#include <string>


using namespace std;

template< class Item>
bool sorted(Item a[], int N) {
    for(int i=1;i<N; ++i)
        if( a[i-1] > a[i] ) return false;
    return true;
}

int compare( const void * a, const void * b)
{
    if( *(int*)a <  *(int*)b ) return -1;
    if( *(int*)a >  *(int*)b ) return 1;
    else return 0; 
}

int main()
{

    int N = 100;
    int *a = new int[N];

    for(int i=0;i<N; ++i) a[i] = i - ( i % 100 ) + (i%3) - (i%5) + (i%8) - (i%11) - (i%30) + (i%41) - (i%53) - (i%63);
    cout << a[0] << endl;
    heapsort(a,0,N-1);

    cout << a[0] << endl;


    cout << endl << sorted(a, N-1) << endl;

    return 0;
}


