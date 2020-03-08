
#include "vector.h"
#include "list.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

	Link* norse_gods = new Link{"Thor"};
	norse_gods = norse_gods->insert(new Link{"Freia"});
	norse_gods = norse_gods->insert(new Link{"Odan"});
	//norse_gods = erase(norse_gods);

	while( norse_gods ) {
		cout << norse_gods->value << endl;
		norse_gods = norse_gods->succ;
	}

	return 0;

}
