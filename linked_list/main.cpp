
#include "linked_list.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	
	List<int> list = {0,1,2,3};


	List<int> list2 = {10,11,12,13,14};
	list2 = list;
	

	cout << endl;
	while( list.begin() != list.end() ) {
		cout << list.pop_front() << endl;
	}

	while( list2.begin() != list2.end() ) {
		cout << list2.pop_front() << endl;
	}

		
	return 0;

}

