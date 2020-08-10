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

    int i = l;
    int j = r+1;
    Item v = a[l]; // pivoting element
    for(;;) {
        while( a[++i] < v ) if( i == r ) break;
        while( v < a[--j] );
        if( i >= j) break;
        // exchange a[i] and a[j]
        exch(a, i,j);
    }
    // exchange v = a[l] and a[j]
    a[l] = a[j];
    a[j] = v;

    return j;
}


template<class Item>
void quick_sort(Item a[], int l, int r)
{
    if(r <= l + 15) { insertion(a,l,r); return; }
    
    // a[l] is pivot
    if( r-l < 500 ) {
        // put middle positin l+1
        // make a[l+1] <= a[l] <= a[r]
        exch(a,l+1, (l+r)/2);
        compexch(a, l+1, r);
        compexch(a, l+1, l);
        compexch(a, l+1, r);
    } else{
        int i11 = l+1;
        int i12 = l + (r-l)/9;
        int i13 = l + (r-l)*2/9;
        int i21 = l + (r-l)/3;
        int i22 = l + (r-l)*4/9;
        int i23 = l + (r-l)*5/9;
        int i31 = l + (r-l)*6/9;
        int i32 = l + (r-l)*7/9;
        int i33 = l + (r-l)*8/9;


        compexch(a, i11, i12);
        compexch(a, i12, i13);
        compexch(a, i11, i12);

        compexch(a, i21, i22);
        compexch(a, i22, i23);
        compexch(a, i21, i22);

        compexch(a, i31, i32);
        compexch(a, i32, i33);
        compexch(a, i31, i32);

        compexch(a, i11, i21);
        compexch(a, i21, i31);
        compexch(a, i11, i21);

        compexch(a, i12, i22);
        compexch(a, i22, i32);
        compexch(a, i12, i22);

        compexch(a, i13, i23);
        compexch(a, i23, i33);
        compexch(a, i13, i23);

        exch(a, l, i22);

    }

    int j = partition(a,l,r);
    quick_sort(a,l,j-1);
    quick_sort(a,j+1,r);

}
template<class Item>
void quick_sort2(Item a[], int l, int r)
{
    if(r <= l + 15) { insertion(a,l,r); return; }
   
     
    if( r-l < 5000) { 
        int m = medianof3(a,l, (l+r)/2, r);
        exch(a,l,m);
    } else {
        int drl = r-l;
        int n = medianof3(a, l+1, l+ drl/9, l + drl*2/9);
        int o = medianof3(a, l+ drl/3, l + drl*4/9, l + drl*5/9);
        int p = medianof3(a, l+ drl*6/9, l + drl*7/9, l + drl*8/9);
        exch( a, l, medianof3(a, n,o,p) );

    }


    int j = partition(a,l,r);
    quick_sort2(a,l,j-1);
    quick_sort2(a,j+1,r);

}

#endif
