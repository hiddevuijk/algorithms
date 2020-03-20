#ifndef GUARD_STACK_H
#define GUARD_STACK_H
/* 
	no copy etc.
*/

namespace stack_ll {

template<class C>
class Stack{
public:
	Stack() : first(nullptr) {}

	void push(C item);
	C pop();
	bool isEmpty() const { return first == nullptr; }

	class iterator;
	iterator begin();

private:


	class Node {
		public:
			C item;
			Node* next;
	};

	Node* first;
};

////iterator
template<class C>
class Stack<C>::iterator {
friend class Stack;
private:
	Stack<C>::Node* curr;
public:
	iterator(Stack<C>::Node* p) : curr(p) {}

	iterator& operator++() { curr=curr->next; return *this;}
	C& operator*() const { return curr->item;}
	bool hasNext() const { return curr != nullptr; }

	bool operator==(const iterator& b) const { return curr == b.curr; }
	bool operator!=(const iterator& b) const { return curr != b.curr; }

};

template<class C>
typename Stack<C>::iterator Stack<C>::begin()
{ return iterator(first); }



template<class C>
void Stack<C>::push( C item)
{
	Node* new_node = new Node;
	new_node->item = item;

	new_node->next = first;		
	first = new_node;
}

template<class C>
C Stack<C>::pop()
{
	C item = first->item;
	Node* old_node = first;
	first = first->next;
	delete old_node;

	return  item;
}
};


namespace stack_array {

template<class C>
class Stack{
public:
	Stack(): sz(-1), space(4), elem(new C[4] ) {}


	bool isEmpty() const { return sz == -1; }
	void push(C val);
	C pop();

	class iterator;
	iterator begin();

private:
	int sz;
	int space;
	C* elem;

	void grow();
	void shrink();
};

////iterator
template<class C>
class Stack<C>::iterator {
friend class Stack;
private:
	int curr;
	C* elem;
public:
	iterator(int sz, C* elem) : curr(sz), elem(elem) {}

	iterator& operator++() { curr -= 1; return *this;}
	C& operator*()  { return elem[curr];}
	bool hasNext() const { return curr >= 0; }

	bool operator==(const iterator& b) const { return curr == b.curr; }
	bool operator!=(const iterator& b) const { return curr != b.curr; }
};

template<class C>
typename Stack<C>::iterator Stack<C>::begin()
{ return iterator(sz, elem); }


template<class C>
C Stack<C>::pop()
{
	if(sz < space/4 and sz > 0) shrink();
	return elem[sz--];
}


template<class C>
void Stack<C>::push(C val)
{
	if( sz+1 == space) grow();
	elem[++sz] = val;
}

template<class C>
void Stack<C>::grow()
{
	C* new_elem = new C[2*space];
	for(int i=0;i<sz+1;++i) new_elem[i] = elem[i];
	delete[] elem;
	elem = new_elem;
	space = 2*space;

}

template<class C>
void Stack<C>::shrink()
{
	C* new_elem = new C[space/2];
	for(int i=0;i<sz+1; ++i) new_elem[i] = elem[i];
	delete[] elem;
	elem = new_elem;
	space = space/2;
}


};


#endif
