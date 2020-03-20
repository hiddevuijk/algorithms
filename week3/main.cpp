
#include "selectionsort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "shuffle.h"

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int main()
{

	int N = 10;
	srand(1020);
	vector<int> v(N);
	
	
	for(int i=0;i<N;++i) {
		v[i] = i;
	}
	v[0] = 9;
	shuffle(v, N -1);
	
	cout << "is sorted : ";
	cout << isSorted(v, 0, N-1) << endl;
	cout << endl;


	insertion_sort(v, 0, N-1);
	//selection_sort(v, 0, N-1);

	
	for(int i=0;i<N;++i) {
		cout << v[i] << endl;
	}


	cout << "is sorted : ";
	cout << isSorted(v, 0, N-1) << endl;
	cout << endl;
	return 0;
}



