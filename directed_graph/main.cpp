

#include "directed_graph.h"
#include "paths.h"
#include "paths_bfs.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{

    ifstream in("graph.txt");
    Digraph g(in);
    g.showAdj();
    cout << endl;


    int v = 2;
    cout << "All nodes not connected to " << v << " are:\n";
    PathsBFS<Digraph> paths(g,v);


    for( int vi=0; vi<g.V(); ++vi) {
        cout <<vi << " : " <<  paths.distance(vi) << endl;
    }
    return 0;

}
