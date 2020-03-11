#ifndef GUARD_PERCOLATION_H
#define GUARD_PERCOLATION_H

#include "union_find.h"

#include <assert.h>
#include <vector>

template<class UF>
class Percolation{
public:
    Percolation(int NN){
        N = NN;
        sites = std::vector<std::vector<int> >(N,std::vector<int>(N,0));

        // +2 because of end sites
        union_find = UF(N*N+2);
    }

    bool remove(int i, int j);

    bool path() { return union_find.connected(N,N+1); }
    double open_sites()
    {
        double n = 0;
        for(int i=0;i<N;++i) {
        for(int j=0;j<N;++j) {
            n += sites[i][j];
        }}
        return n;
    }
private:

    int N;
    UF union_find;
    std::vector<std::vector<int> > sites;
    int ij2n(int i, int j) { return i*N+j; } 
};

template<class UF>
bool Percolation<UF>::remove(int i, int j)
{
    // check i,j < N
    assert(i<N && j<N);
    if( sites[i][j] == 1) return false;
    sites[i][j] = 1;
    int n = ij2n(i,j); // index in union_find

    if(i>0 && i<N-1 ) {  // bulk row
        if(sites[i-1][j] == 1)   // site above
            union_find.add_union(n, ij2n(i-1,j) );
        if(sites[i+1][j] == 1) // site below
            union_find.add_union(n, ij2n(i+1,j) );
        if(j<N-1) {
            if(sites[i][j+1] == 1) // right site
                union_find.add_union(n, ij2n(i,j+1) );
        }
        if(j>0) {
            if(sites[i][j-1] == 1) // left site
                union_find.add_union(n, ij2n(i,j-1) );
        }
        
    } else if(i == 0 ) { // top row
        // add_union to extra top site
        union_find.add_union(n,N);
        if(sites[i+1][j] == 1) // site below
            union_find.add_union(n, ij2n(i+1,j) );
        if(j<N-1) {
            if(sites[i][j+1] == 1) // right site
                union_find.add_union(n, ij2n(i,j+1) );
        }
        if(j>0) {
            if(sites[i][j-1] == 1) // left site
                union_find.add_union(n, ij2n(i,j-1) );
        }

    } else if(i==N-1) {
        // last row 
        // add_union to extra bottom site
        union_find.add_union(n,N+1);

        if(sites[i-1][j] == 1)   // site above
            union_find.add_union(n, ij2n(i-1,j) );
        if(j<N-1) {
            if(sites[i][j+1] == 1) // right site
                union_find.add_union(n, ij2n(i,j+1) );
        }
        if(j>0) {
            if(sites[i][j-1] == 1) // left site
                union_find.add_union(n, ij2n(i,j-1) );
        }
    }
    return true;
}

#endif
