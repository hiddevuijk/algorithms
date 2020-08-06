#ifndef GUARD_MERGE_SORT_H
#define GUARD_MERGE_SORT_H

#include "insertion_sort.h"

#include <math.h>

// the array a[l...m] is sorted
// the array a[m+1...r] is sorted
// aux is an auxilary array ( at least size of a)
template< class Item >
void merge( Item a[], Item aux[], int l, int m, int r)
{
    int i = l, j = m+1; 

    // copy a to aux
    for(int k=l; k<=r; ++k) aux[k] = a[k]; 
    for(int k=l; k<=r; ++k) {
        if( i>m ){ 
             a[k] = aux[j++];
        } else if( j>r ){ 
            a[k] = aux[i++];
        } else if( aux[j] < aux[i] ) {
            a[k] = aux[j++];
        } else {
            a[k] = aux[i++]; 
        }
    }

}

template<class Item>
void merge_sort(Item a[], Item aux[] , int l, int r)
{
    if(r-l <= 10 ) {
        insertion(a,l,r);
        return;
    }
    int m = (r+l)/2;
    merge_sort(a, aux, l,  m);
    merge_sort(a, aux, m+1,r);
    merge(a,aux, l,m,r);

}

template<class Item>
void merge_sort(Item a[], int l, int r)
{
    Item *aux = new Item[r+1];
    merge_sort(a, aux, l, r);
    delete[] aux;
}



template<class Item>
void merge_sortBU(Item a[], int l, int r)
{
    Item *aux = new Item[r+1];
    for( int m=1; m<= r-l; m *= 2)
        for( int i=l; i<= r-m; i+= m+m)
            merge(a,aux, i,i+m-1, ( (i+m+m-1 < r) ? i+m+m-1 : r ) );


    delete[] aux;
}

/*
template< class Item>
void merge( Item c[], Item a[], int Na,
                      Item b[], int Nb)
{

    int N = Na + Nb;
    for(int ia=0, ib=0, ic=0; ic<N; ++ic ) {
        if( ia==Na ) { c[ic] = b[ib++]; continue; }
        if( ib==Nb ) { c[ic] = a[ia++]; continue; }
        c[ic] = ( a[ia] < b[ib] ) ? a[ia++] : b[ib++];
    }

}
*/

#endif
