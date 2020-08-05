#ifndef GUARD_INSERTION_SORT_H
#define GUARD_INSERTION_SORT_H

template<class Item>
void insertion(Item a[], int l, int r)
{
    Item temp;
    for( int i=1; i<=r; ++i) {
       for( int j=i; j>0 && ( a[j] <  a[j-1] ); --j) {
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
        }

    }


}


#endif
