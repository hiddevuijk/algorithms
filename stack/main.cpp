#include <iostream>
#include <string>

#include "stack_array.h"


using namespace std;



int main()
{

	Stack<int> stack(2);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);

	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	cout << stack.pop() << endl;
	return 0;
}
