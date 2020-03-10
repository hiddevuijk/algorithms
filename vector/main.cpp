
#include "vector.h"
#include "list.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{


	Vector v{1.,2.};

	Vector v2(10);
	cout << v2.size() << endl;
	v2 = v;

	v2[0] = 2.;
	v2[1] = 2.;
	cout << v2[0] << v2[1] << endl;
	//Link* norse_gods = new Link{"Thor"};
	//norse_gods = norse_gods->insert(new Link{"Freia"});
	//norse_gods = norse_gods->insert(new Link{"Odan"});
	////norse_gods = erase(norse_gods);

	//while( norse_gods ) {
	//	cout << norse_gods->value << endl;
	//	norse_gods = norse_gods->succ;
	//}

	return 0;

}
