#ifndef GUARD_DFS_H
#define GUARD_DFS_H

#include "graph.h"

class Paths {
public:

	Paths(const Graph& g, int s);

	bool hasPathTo(int v) const {return marked[v]; }
	std::vector<int> pathTo(int v) const;

private:

	void dfs( const Graph&,int v);	

	int s;
	std::vector<bool> marked;
	std::vector<int> edgeTo;
};


Paths::Paths(const Graph& g, int s)
: s(s), marked(g.getNv(), false ), edgeTo( g.getNv() )
{
	 dfs( g, s);
}

void Paths::dfs( const Graph& g, int v)
{

	marked[v] = true;
	Graph::vertex_iterator v_iter = g.getBeginVertexIterator(v);
	while( v_iter != g.getEndVertexIterator(v) ) {
		if( marked[*v_iter] == false ) {
			dfs( g, *v_iter);
			edgeTo[ *v_iter ] = v;
		}
		++v_iter;
	}
	


}

std::vector<int> Paths::pathTo(int v) const
{
	std::vector<int> path;
	if( hasPathTo(v) == false ) return path; 
	path.push_back(v);
	while( v != s ){
		v = edgeTo[v];
		path.push_back(v);
	}	

	return path;
}
	



#endif
