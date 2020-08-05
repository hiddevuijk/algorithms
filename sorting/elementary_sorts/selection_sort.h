#ifndef GUARD_SELECTION_SORT_H
#define GUARD_SELECTION_SORT_H

template<class Item>
void selection(Item a[], int l, int r)
{
    
    for( int i=l; i< r; ++i ) {
        int min = i;
        for( int j=i+1; j<=r; ++j) {
            if( a[j] < a[min] ) min = j;
        }
        if( min != i ) {
            Item temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }

    }
}



#endif
