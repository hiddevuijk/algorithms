#ifndef GUARD_UNION_FIND_H
#define GUARD_UNION_FIND_H

#include <vector>
#include <iostream>


class QuickFindUF {
public:
	QuickFindUF(int N)
	: N(N), id(N)
	{
		for( int i=0; i<N; ++i)
			id[i] = i;	
	}


	void add_union(int p, int q)
	{
		int pid = id[p];
		int qid = id[q];
		for( int i=0; i<N; ++i)
			if(id[i] == pid) id[i] = qid;
	}

	bool connected(int p, int q)
	{
		return id[p] == id[q];
	}

	int find(int p);
	int count();

	std::vector<int> get_id(){ return id;}

	

private:
	unsigned int N;
	std::vector<int> id;	

};





#endif
