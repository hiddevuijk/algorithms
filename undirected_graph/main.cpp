#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "graph.h"
#include "dfs.h"

using namespace std;

int main()
{

	ifstream in("graph.txt");
	Graph g(in);	
	in.close();


	Paths p(g,0);
	for(int i=0; i < g.V(); ++i) {
		cout << 0 << " to " << i <<": " << p.hasPathTo(i) << endl;
	}

	std::vector<int> path = p.pathTo(7);
	cout << "Path to 0: \n";
	for(int i=0; i< path.size(); ++i) {
		cout << path[i] << "\t";
	}
	cout << endl;

	return 0;
}
