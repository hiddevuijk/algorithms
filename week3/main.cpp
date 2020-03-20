
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

	for(int i=0;i<N;++i) {
		cout << v[i] << endl;
	}
	cout << endl;
	shuffle(v, N -1);

	for(int i=0;i<N;++i) {
		cout << v[i] << endl;
	}
	cout << endl;
	return 0;

	//sort(v);
	//cout << isSorted(v, 0, N-1) << endl;

	
	for(int i=0;i<N;++i) {
		cout << v[i] << endl;
	}


	return 0;
}



