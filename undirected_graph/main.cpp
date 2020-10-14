

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
    return 0;
}
