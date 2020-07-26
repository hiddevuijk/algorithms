#include <iostream>
#include <string>

#include "stack_ll.h"


using namespace std;



int main()
{

	Stack<int> stack(2);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	Stack<int> s2;

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << s2.pop() << endl;
	return 0;
}
