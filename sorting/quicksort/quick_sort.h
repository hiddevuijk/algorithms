#ifndef GUARD_QUICK_SORT_H
#define GUARD_QUICK_SORT_H

#include "insertion_sort.h"

#include <time.h>
#include <stdlib.h>

template<class Item>
int medianof3(Item a[], int i, int j, int k)
{
    return ((a[i]-a[j])*(a[j]-a[k]) > -1 ? j : ((a[i]-a[j])*(a[i]-a[k]) < 1 ? i : k));
}

template<class Item>
void exch(Item a[], int i, int j)
{
    Item temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


template<class Item>
void compexch(Item a[], int i, int j)
{
    if( a[i] > a[j]) {
        Item temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

template<class Item>
void shuffle(Item a[], int l, int r)
{
    srand(time(NULL));
    for(int i=l; i<=r; ++i) {
        int j = i + rand() % ( r-i+1 );
        exch(a,i,j);
    }

}

template<class Item>
int partition(Item a[], int l, int r)
{
    int i = l-1;
    int j = r;
    Item v = a[r];
    for(;;) {
        while( a[++i] < v );
        while( v < a[--j] );// if( j == l ) break;
        if( i >= j ) break;
        exch(a,i,j);
    }
    exch(a,i,r);
    
    return i;
}


template<class Item>
void quick_sort(Item a[], int l, int r)
{

    if(r <=  15) insertion(a,l,r); return;

    exch(a, (l+r)/2, r-1);
    compexch(a,l,r-1);
    compexch(a, l, r-1);
    compexch(a, r-1, r);

    int i = partition(a, l+1, r-1);
    quick_sort(a,l,i-1);
    quick_sort(a,i-1, r);
    
}

#endif
