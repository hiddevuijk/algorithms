#ifndef GUARD_UNDIRECTED_GRAPH
#define GUARD_UNDIRECTED_GRAPH

#include <fstream>

class Graph {
public:
	// create graph with V vertices
	Graph(int V);
	// read graph from input
	Graph(std::ifstream in);

	void addEdge(int v, int w);
	int get_vertices() const;
	int get_edges() const;

//private:


};


//Graph::Graph

#endif
