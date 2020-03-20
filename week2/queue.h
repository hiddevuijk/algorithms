#ifndef GUARD_QUEUE_H
#define GUARD_QUEUE_H
/* 
	no copy etc.
*/

namespace queue_ll {

template<class C>
class Queue{
public:
	Queue() : first(nullptr), last(nullptr) {}

	void enqueue(C item);
	C dequeue();
	bool isEmpty() const { return first == nullptr; }

	class iterator;
	iterator begin();
	iterator end();

private:


	class Node {
		public:
		C item;
		Node* next;
	};

	Node* first;
	Node* last;
};

// iterator
template<typename C>
class Queue<C>::iterator {
friend class Queue;
private:
	Queue<C>::Node* curr;
public:
	iterator(Queue<C>::Node* p) : curr(p) {}

	iterator& operator++() { curr=curr->next; return *this;}
	C& operator*() const { return curr->item; }
	bool hasNext() const { return curr != nullptr; }

	bool operator==(const iterator& b) const { return curr == b.curr;}	
	bool operator!=(const iterator& b) const { return curr != b.curr;}	
};

template<class C>
typename Queue<C>::iterator Queue<C>::begin()
{ return iterator(first);}

template<class C>
typename Queue<C>::iterator Queue<C>::end()
{ return iterator(last);}


template<class C>
void Queue<C>::enqueue( C item)
{
	Node* new_node = new Node;
	new_node->item = item;
	if(last) {
		last->next = new_node;		
		last = new_node;
	} else {

		first = new_node;
		last = new_node;
		new_node->next = nullptr;
	}
}

template<class C>
C Queue<C>::dequeue()
{
	if(first != last ) {
		C item = first->item;
		Node* old_node = first;
		first = first->next;
		delete old_node;

		return  item;
	} else {
		C item = first->item;

		delete first;
		first = nullptr;
		last = nullptr;

		return item;
	}

}

};




#endif
