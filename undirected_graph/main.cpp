#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "graph.h"

using namespace std;

int main()
{

	fstream in("graph.txt");
	Graph g(in);	
	in.close;

	return 0;
}
