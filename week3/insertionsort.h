#ifndef GUARD_INSERTIONSORT_H
#define GUARD_INSERTIONSORT_H

template<class Array>
void insertion_sort(Array& a, int lo, int hi)
{

	for(int i=lo; i<=hi; ++i ){
		for(int j=i; j>lo; --j ) {
			if( a[j] < a[j-1] ) {
				auto temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			} else {
				break;
			}
		}

	}
}


#endif
