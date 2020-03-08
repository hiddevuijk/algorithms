#ifndef GUARD_STACK_H
#define GUARD_STACK_H


namespace LinkedList {

template<class C>
class Stack{
public:

	void push(C item);
	C pop();
	bool isEmpty();

private:


	class Node {
		C item;
		Node nest;
	};

};

}
#endif
