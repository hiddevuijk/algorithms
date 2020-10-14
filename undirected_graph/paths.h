#ifndef GUARD_PATHS_H
#define GUARD_PATHS_H

#include "undirected_graph.h"

class Paths
{
    Paths( Graph &g, int s);

    bool hasPathTo(int v);

  private:
    int s;
    Graph& graph;

    std::vector<bool> marked;
    std::vector<int> edgeTo;
};


Paths::Paths( Graph& g, int s)
: s(s), graph(g), marked(g.V()), edgeTo(g.V())
{


}

#endif
