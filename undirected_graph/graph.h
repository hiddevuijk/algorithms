#ifndef GUARD_UNDIRECTED_GRAPH
#define GUARD_UNDIRECTED_GRAPH


#include <algorithm>
#include <iostream>
#include <fstream>

class Graph {
  public:
    // create a graph with V vertices
    Graph(int V);
    // create a graph from input stream
    Graph( std::ifstream& in);

    // add edge between v and w
    void addEdge(int v, int w);
    void deleteEdge(int v, int w);
    //void deleteVertex(int v);

    // return # vertices
    int V() const { return NV; }
    // return # edges
    int E() const { return NE; }

    void showAdj() const;

	typedef std::vector<int>::const_iterator const_vertex_iterator;
    const_vertex_iterator get_iterator(int v)
            const { return adj[v].begin(); }
	const_vertex_iterator end( int v)
			const { return adj[v].end(); }

    //const std::vector<int>::const_iterator get_iterator(int v)
    //        const { return adj[v].begin(); }
	//const std::vector<int>::const_iterator end( int v)
	//		const { return adj[v].end(); }
    int Nneighbours(int vi) const { return adj[vi].size(); }

    int neighbourIndex(int vi, int ni) const { return adj[vi][ni]; }
  private:
    int NV; 
    int NE;

    std::vector<std::vector<int> > adj;


};

Graph::Graph(int Nv)
: adj( std::vector<std::vector<int> >(NV) ) {}

Graph::Graph( std::ifstream& in)
{
	NE = 0;
	in >> NV;
	adj = std::vector<std::vector<int> >(NV);
	int v,w;
	while( (in >> v ) and ( in >> w ) ){
		addEdge(v,w);
	}

}

void Graph::addEdge(int v, int w)
{
	++NE;
	adj[v].push_back(w);
	adj[w].push_back(v);
}

void Graph::deleteEdge(int v, int w)
{
	std::vector<int>::iterator it = std::find(adj[v].begin(), adj[v].end(), w);
	if( it != adj[v].end() ) {
		adj[v].erase(it);
		it = std::find(adj[w].begin(), adj[w].end(), v);
		adj[w].erase(it);
	}
}

void Graph::showAdj() const
{
	for(int iv=0; iv < NV; ++iv) {
		std::cout << iv << " : ";
		for( std::vector<int>::size_type ie = 0; ie < adj[iv].size(); ++ie) {
			std::cout << adj[iv][ie] << " ";
		}
		std::cout << std::endl;
	}
}

#endif
