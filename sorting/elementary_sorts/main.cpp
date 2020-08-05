
#include "selection_sort.h"
#include "insertion_sort.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int N = 100000;
    int *a = new int[N];
    for(int i=0;i<N; ++i) a[i] = N-i;
    selection(a,0,N-1); 
    //insertion(a,0,N-1); 

    //for(int i=0;i<N;++i) cout << a[i] << endl;
    cout << a[0] << endl;
    return 0;
}


