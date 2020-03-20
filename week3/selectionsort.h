#ifndef GUARD_SELECTIONSORT_H
#define GUARD_SELECTIONSORT_H


template<class Array>
void selection_sort(Array& a, int lo, int hi)
{


	int smallest_i;
	for(int i=lo; i<=hi; ++i) {
		//smallest_val = a[i];	
		smallest_i = i;
		for(int j = i+1; j<=hi; ++j) {
			if( a[j] < a[smallest_i] ) {
				smallest_i = j;
			}

		}
		// swap a[i] and a[smallest_i]
		auto temp = a[i];
		a[i] = a[smallest_i];
		a[smallest_i] = temp;
	}


}


#endif
