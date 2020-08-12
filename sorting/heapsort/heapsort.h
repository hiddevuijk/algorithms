#ifndef GUARD_HEAP_SORT_H
#define GUARD_HEAP_SORT_H
/*

    sorts a[1...N]
    use: heapsort(a,1,N-1);

*/

template< class Item>
void sink(Item a[], int k, int N)
{
    Item temp;
    while( 2*k <= N ){
        int j = 2*k;
        if( j < N && ( a[j] < a[j+1]) ) ++j;
        if( !( a[k] < a[j]) ) break;
        temp = a[k];
        a[k] = a[j];
        a[j] = temp;
        k = j;
    }
}


template< class Item>
void heapsort(Item a[], int l, int r)
{
    int N = r-l + 1;
    Item *a_slice = a+l-1;

    for(int k=N/2; k>=1; --k)
        { sink(a_slice, k, N); }

    Item temp;
    while(N > 1) {
        temp = a[1];        
        a[1] = a[N];
        a[N] = temp; 
        sink(a_slice,1,--N);
    }

}


#endif
