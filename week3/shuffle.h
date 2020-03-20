#ifndef GUARD_SHUFFLE_H
#define GUARD_SHUFFLE_H

#include <stdlib.h>

template<class Array>
void shuffle( Array& a, int hi )
{
	for(int i=1; i<=hi; ++i ) {
		int r = rand() % i;
		auto temp = a[i];
		a[i] = a[r];
		a[r] = temp;

	}
}


#endif
