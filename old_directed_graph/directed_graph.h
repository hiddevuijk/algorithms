#ifndef GUARD_DIRECTED_GRAPH_H
#define GUARD_DIRECTED_GRAPH_H

#include <vector>
#include <fstream>
#include <iostream>

class Digraph
{
  public:
    // create a graph with V vertices
    Digraph(int V);
    // create a graph from input stream
    Digraph( std::ifstream& in);

    // add edge between v and w
    void addEdge(int v, int w);

    // return # vertices
    int V() const { return NV; }
    // return # edges
    int E() const { return NE; }

    void showAdj() const;

    const std::vector<int>::const_iterator get_iterator(int v)
            const { return adj[v].begin(); }
    int Nneighbours(int vi) const { return adj[vi].size(); }

    int neighbourIndex(int vi, int ni) const { return adj[vi][ni]; }
  private:
    int NV; 
    int NE;

    std::vector<std::vector<int> > adj;

};

void Digraph::showAdj() const
{
    
    for(int iv=0; iv < NV; ++iv) {
        std::cout << iv << " : ";
        for(std::vector<int>::size_type ie=0;ie< adj[iv].size(); ++ie) {
            std::cout << adj[iv][ie] << " ";
        }
        std::cout << std::endl;

    }
}

void Digraph::addEdge(int v, int w)
{
    NE += 1;
    adj[v].push_back(w);

}

Digraph::Digraph( std::ifstream& in)
{
    NE = 0;
    in >> NV;
    adj = std::vector<std::vector<int> >(NV);
    int v,w;
    while( ( in >> v ) and ( in >> w) ){
        addEdge(v,w);
    }

}

#endif
