#ifndef GUARD_UNION_FIND_H
#define GUARD_UNION_FIND_H

#include <vector>
#include <iostream>


class QuickUnionUF {
public:
	QuickUnionUF(int N)
	: N(N), id(N)
	{
		for( int i=0; i<N; ++i)
			id[i] = i;	
	}




	std::vector<int> get_id(){ return id;}

private:
	unsigned int N;
	std::vector<int> id;	

};




class QuickFindUF {
public:
	QuickFindUF(int N)
	: N(N), id(N), sz(N)
	{
		for( int i=0; i<N; ++i) {
			id[i] = i;	
			sz[i] = 1;	
		}
	}


	void add_union(int p, int q)
	{
		int i = root(p);
		int j = root(q);
		//id[i] = j;

		if(i == j) return;

		if( sz[i] < sz[j] ) {
			id[i] = j;
			sz[j] += sz[i];
		} else {
			id[j] = i;
			sz[i] += sz[j];
		}
	}

	bool connected(int p, int q)
	{
		return root(p) == root(q);
	}

	int find(int p);
	int count();

	std::vector<int> get_id(){ return id;}

	

private:
	unsigned int N;
	std::vector<int> id;	
	std::vector<int> sz;

	int root(int i)
	{
		//while( i != id[i] ) i = id[i];

		// flatten
		while( i != id[i] ) {
			id[i] = id[id[i]];
			i = id[i];
		}
		return i;
	}
};





#endif
