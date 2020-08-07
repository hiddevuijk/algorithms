#ifndef GUARD_INSERTION_SORT_H
#define GUARD_INSERTION_SORT_H

template<class Item>
void insertion(Item a[], int l, int r)
{
    Item temp;
    for( int i=l; i<=r; ++i) {
       for( int j=i; j>l && ( a[j] <  a[j-1] ); --j) {
            temp = a[j];
            a[j] = a[j-1];
            a[j-1] = temp;
        }

    }


}


#endif
