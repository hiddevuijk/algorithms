#ifndef GUARD_MERGESORT_H
#define GUARD_MERGESORT_H

/*
	works for vectors only 
	need .size()
*/

#include <assert.h>

template<class Array>
bool isSorted(const Array& a, int lo, int hi)
{
	while(lo < hi) {
		if( a[lo] > a[lo+1] ) return false;
		++lo;
	}
	return true;
}

template<class Array>
void merge(Array& a, Array& aux, int lo, int mid, int hi)
{
	// check if both sides are sorted
	assert( isSorted(a, lo, mid) );
	assert( isSorted(a, mid+1, hi) );

	for( int k = lo; k<= hi; ++k)
		aux[k] = a[k];

	int i = lo;
	int j = mid+1;

	for(int k=lo; k<=hi; ++k) {
		if( i > mid ) {
			a[k] = aux[j++];
		} else if( j > hi ) {
			a[k] = aux[i++];
		} else if( aux[j] < aux[i] ) {
			a[k] = aux[j++];
		} else {
			a[k] = aux[i];
		}


	}

	// check if it worked
	assert( isSorted(a,lo,hi) );
}

template<class Array>
void sort(Array& a, Array& aux, int lo, int hi)
{

	if(hi<=lo) return;
	int mid = lo + (hi-lo)/2;
	sort(a, aux, lo, mid);
	sort(a, aux, mid+1, hi);
	merge(a, aux, lo, mid, hi);
}

template<class Array>
void sort(Array& a)
{
	Array aux(a.size() );
	sort(a, aux, 0, a.size() -1);
}


#endif
