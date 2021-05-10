#ifndef GUARD_GRAPH_H
#define GUARD_GRAPH_H

#include <iostream>
#include <fstream>
#include <vector>

class Graph {
public:
	Graph(): Ne(0) {}
	Graph(int Nv): adj(Nv), Ne(0) {}
	Graph( std::ifstream& in);

	std::vector<std::vector<int> >::size_type getNv() const { return adj.size(); }
	int getNe() const { return Ne; }

	typedef std::vector<int>::const_iterator vertex_iterator;

	vertex_iterator getBeginVertexIterator(int v) const { return adj[v].begin(); }
	vertex_iterator getEndVertexIterator(int v) const { return adj[v].end(); }
	
	void addEdge(int i, int j);	

	void showAdj() const;
private:

	int Ne;
	std::vector<std::vector<int> > adj;

};


Graph::Graph( std::ifstream& in ) 
{

	int Nv = 0;
	in >> Nv;
	adj = std::vector<std::vector<int> >(Nv);
	int i,j;
	while(  in >> i and in >> j ) {
		addEdge(i,j);
	}
}



void Graph::addEdge(int i, int j)
{
	adj[i].push_back(j);
	adj[j].push_back(i);
	++Ne;
}

void Graph::showAdj() const
{
	for(int vi = 0; vi < adj.size(); ++vi) {
		std::cout << vi << " : ";
		for(int ai=0; ai < adj[vi].size(); ++ai ) {
			std::cout << adj[vi][ai] << " ";
		}
		std::cout << "\n";

	}
}


#endif
