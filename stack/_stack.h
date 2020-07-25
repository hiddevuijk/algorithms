#ifndef GUARD_STACK_H
#define GUARD_STACK_H

#include <string>
#include <iostream>

template< class T>
struct Node {
	T data;
	Node *next;
};

template< class T>
class Stack
{
  public:
	Stack();
	Stack(int);
	~Stack();

	void push(T d);
	T pop();

	T peek() const { return top->data; }
	bool empty() const { return top == nullptr; }

  private:
	Node<T> *top;
};

	

template< class T>
Stack<T>::Stack() {
	// initialize empty stack
	top = nullptr;

}

template< class T>
Stack<T>::Stack(int N) {
	// initialize empty stack
	top = nullptr;

}

template< class T>
Stack<T>::~Stack() {
	while( top != nullptr) this->pop();
}

template< class T>
void Stack<T>::push( T d) {

	// new node	
	Node<T> *new_node = new Node<T>;
	new_node->data = d;
	new_node->next = top;

	top = new_node;

}

template< class T>
T Stack<T>::pop() {

	if( !empty() ) {
		T temp = top->data;
		Node<T> *oldtop = top;
		top = oldtop->next;
		delete oldtop;
		return  temp;
	} else {
		std::cout<< "fuck" << std::endl;
		exit(1);
		// empty stack
	}
}

#endif
