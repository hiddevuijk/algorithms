

#include "undirected_graph.h"
#include "paths.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    ifstream in("graph.txt");
    Graph g(in);
    g.showAdj();
    cout << endl;


    int v = 4;
    cout << "All nodes not connected to " << v << " are:\n";
    Paths paths(g,v);
    for( int vi=0; vi<g.V(); ++vi) {
        if( !paths.hasPathTo(vi) ) cout << vi << endl;
    }
    return 0;
}
