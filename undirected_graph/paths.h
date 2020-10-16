#ifndef GUARD_PATHS_H
#define GUARD_PATHS_H

#include "undirected_graph.h"

class Paths
{
  public:
    Paths( Graph &g, int s);

    bool hasPathTo(int v) const {
        return marked[v];
    }

  private:
    int s;
    Graph& graph;

    std::vector<bool> marked;
    std::vector<int> edgeTo;
    void mark_neighbours( int vi);
};


Paths::Paths( Graph& g, int s)
: s(s), graph(g), marked(g.V()), edgeTo(g.V())
{ mark_neighbours(s); }

void Paths::mark_neighbours( int vi)
{
    marked[vi] = true;
    int Nneighbours = graph.Nneighbours(vi);
    int nIndex;
    for(int ni =0; ni<Nneighbours; ++ni ) {
        nIndex = graph.neighbourIndex(vi,ni);
        if( marked[ nIndex ] == false ) {
            edgeTo[ nIndex ] = vi;
            mark_neighbours( nIndex );
        }
    }

}

#endif
