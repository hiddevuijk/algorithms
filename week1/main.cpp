
#include "union_find.h"

#include <iostream>
#include <vector>
#include <string>

#include <fstream>

using namespace std;

void read_from_file(string iname)
{
	ifstream ist(iname);
	if( !ist ) cerr << "File does not exist \n";
	int N;
	ist >> N;

}


int main()
{

	ifstream ist("infile.txt");
	if( !ist ) cerr << "File does not exit! \n";

	int N;
	ist >> N;
	QuickFindUF qf_uf(N);

	int p,q;
	while( ist >> p >> q)
		qf_uf.add_union(p,q);

	vector<int> id = qf_uf.get_id();
	for(int i=0; i<id.size(); i++)
		cout << i <<' ';
	cout << '\n';

	for(int i=0; i<id.size(); i++)
		cout << id[i] << ' ';
	cout << '\n';

	return 0;
}
