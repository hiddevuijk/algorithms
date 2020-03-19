#ifndef GUARD_LINKED_LIST_H
#define GUARD_LINKED_LIST_H

/*
	test: - move consructor
		  - move assignment
*/

#include <initializer_list>

// single link in a list
template<typename Elem>
class Link {
public:
	Link* prev;
	Link* succ;
	Elem val;
};


template<typename Elem>
class List {
public:
	// constructor
	List();
	// constructor with initializer list
	List( std::initializer_list<Elem> lst);
	// copy constructor
	List(const  List& );
	// copy assignment
	List& operator=( const List& );
	// move constructor
	List( List&& );
	// move assignment
	List& operator=( List&& );
	// destructor
	~List();

	class iterator;		// member type: iterator
	class const_iterator;// member type: const_iterator

	iterator begin();	// iterator to first link
	const_iterator begin() const ;// const_iterator to first link
	iterator end();		// iterator to one beyond last link
	const_iterator end() const;		// iterator to one beyond last link

	// insert v into list after p
	iterator insert(iterator p, const Elem& v);
	// remove p from list
	iterator erase(iterator p);

	void push_back(const Elem& v); // insert at end
	void push_front(const Elem& v); // insert at start
	Elem pop_front();	// remove the first element
	Elem pop_back();	// remove the last element
	
private:
	Link<Elem>* first;
	Link<Elem>* last;	// one beyond the last link
						// is fixed to the "zeroth_link"
						// added in the Constructor

};

// Iterator
template<typename Elem>
class List<Elem>::iterator {
friend class List;
private:
	Link<Elem>* curr;  // current link
public:
	iterator(Link<Elem>* p) : curr(p) {}

	iterator& operator++(){ curr=curr->succ; return *this;}
	iterator& operator--(){ curr=curr->prev; return *this;}
	Elem& operator*() const { return curr->val; }

	bool operator==(const iterator& b) const { return curr==b.curr;}
	bool operator!=(const iterator& b) const { return curr!=b.curr;}
	bool operator==(const const_iterator& b) const { return curr==b.curr;}
	bool operator!=(const const_iterator& b) const { return curr!=b.curr;}
};

template<typename Elem>
typename List<Elem>::iterator List<Elem>::begin()
{ return iterator(first); }

template<typename Elem>
typename List<Elem>::iterator List<Elem>::end()
{ return iterator(last); }



// const_Iterator
template<typename Elem>
class List<Elem>::const_iterator {
friend class List;
private:
	Link<Elem>* curr;  // current link
public:
	const_iterator(Link<Elem>* p) : curr(p) {}
	const_iterator(List<Elem>::iterator i) : curr(i.curr) {}

	const_iterator& operator++(){ curr=curr->succ; return *this;}
	const_iterator& operator--(){ curr=curr->prev; return *this;}
	const Elem& operator*() const  { return curr->val; }

	bool operator==(const iterator& b) const { return curr==b.curr;}
	bool operator!=(const iterator& b) const { return curr!=b.curr;}
	bool operator==(const const_iterator& b) const { return curr==b.curr;}
	bool operator!=(const const_iterator& b) const { return curr!=b.curr;}
};

template<typename Elem>
typename List<Elem>::const_iterator List<Elem>::begin()
const { return  const_iterator(first); }

template<typename Elem>
typename List<Elem>::const_iterator List<Elem>::end()
const { return const_iterator(last); }
	
// List
template<typename Elem>
List<Elem>::List()
{
	Link<Elem>* last_link = new Link<Elem>();
	last_link->prev = nullptr;
	last_link->succ = nullptr;

	first = last_link;
	last = last_link;
}

template<typename Elem>
List<Elem>::List( std::initializer_list<Elem> lst)
{

	Link<Elem>* last_link = new Link<Elem>();
	last_link->prev = nullptr;
	last_link->succ = nullptr;

	first = last_link;
	last = last_link;

	auto iter = lst.begin();
	while( iter != lst.end() ) {
		push_back(*iter);
		++iter;
	}
}

template<typename Elem>
List<Elem>::List(const List<Elem>& rhs_list )
{

	Link<Elem>* last_link = new Link<Elem>();
	last_link->prev = nullptr;
	last_link->succ = nullptr;

	first = last_link;
	last = last_link;

	typename List<Elem>::const_iterator iter = rhs_list.begin();
	while( iter != rhs_list.end() ) {
		push_back(*iter);
		++iter;
	}

}


template<typename Elem>
List<Elem>& List<Elem>::operator=(
			const List<Elem>& rhs_list )
{
	// check for self-assignment
	//if( this == &rhs_list) return *this;

	
	typename List<Elem>::const_iterator rhs_iter = rhs_list.begin();
	typename List<Elem>::iterator iter = begin();

	while( rhs_iter != rhs_list.end() ) {
		if( iter != end() ) {
			*iter = *rhs_iter;
			++iter;
		} else {
			iter = insert(iter, *rhs_iter );
		}	
		++rhs_iter;
	}

	// erase rest of old list
	while( iter.curr != last ) iter = erase(iter);

	return *this;

}


template<typename Elem>
void List<Elem>::push_back(const Elem& v)
{
	// new link with elem = v
	Link<Elem>* link_ptr = new Link<Elem>;
	link_ptr->val = v;
	
	// if last_node has a previous
	if( last->prev ) {
		last->prev->succ = link_ptr;		
		link_ptr->prev = last->prev;
		last->prev = link_ptr;
		link_ptr->succ = last;
	} else { // first added link
		link_ptr->prev = nullptr;
		link_ptr->succ = last;
		last->prev = link_ptr;
		first = link_ptr;
	}
}

template<typename Elem>
void List<Elem>::push_front(const Elem& v)
{
	// new link with elem = v
	Link<Elem>* link_ptr = new Link<Elem>;
	link_ptr->val = v;
	
	// first link does not exist
	if( first == last ) {
		link_ptr->prev = nullptr;
		link_ptr->succ = last;
		last->prev = link_ptr;
		first = link_ptr;
	} else { // add before first link
		link_ptr->prev = nullptr;
		first->prev = link_ptr;
		link_ptr->succ = first;
		first = link_ptr;
	}
}

template<typename Elem>
Elem List<Elem>::pop_back()
{
	// check for empty list ??
	Elem val = last->prev->val;

	// remove most right Link
	Link<Elem>* link_ptr = last->prev;
	if(last->prev->prev ) { // one or more links left
		last->prev->prev->succ = last;
		last->prev = last->prev->prev;
	} else { // after this the list is empty
		last->prev = nullptr;	
		first = last;
	}

	delete link_ptr;
	return val;
}

template<typename Elem>
Elem List<Elem>::pop_front()
{
	// check for empty list ??
	Elem val = first->val;

	// remove first Link
	Link<Elem>* link_ptr = first;

	first = link_ptr->succ;	
	first->prev = nullptr;

	delete link_ptr;
	return val;

}

template<typename Elem>
typename List<Elem>::iterator 
	List<Elem>::insert(List<Elem>::iterator p, const Elem& v)
{

	// insert new link after p
	// if p != last
	if( p.curr != last ) {
		// new link
		Link<Elem>* new_link = new Link<Elem>;
		new_link->val = v;
		new_link->prev = p.curr;
		new_link->succ = p.curr->succ;
		p.curr->succ->prev = new_link;
		p.curr->succ = new_link;	

		return iterator(new_link);

	} else { // insert before last
		push_back(v);
		return iterator(last->prev);
	}
}

template<typename Elem>
typename List<Elem>::iterator 
	List<Elem>::erase(List<Elem>::iterator p)
{
	// ??
	if(p.curr == last ) return p;
	if( p.curr == first) {
		first = p.curr->succ;
		delete first->prev;
		first->prev = nullptr;
		return iterator(first);
	} else {
		p.curr->prev->succ = p.curr->succ;
		p.curr->succ->prev = p.curr->prev;
		List<Elem>::iterator iter( p.curr->succ );
		delete p.curr;
		return iter;

	}
}

template<typename Elem>
List<Elem>::List( List<Elem>&& a)
: first(a.first), last(a.last)
{
	a.first = nullptr;
	a.last = nullptr;
}

template<typename Elem>
List<Elem>& List<Elem>::operator=( List<Elem>&& a)
{

	List<Elem>::iterator iter(first);
	while( iter.curr != last ) iter = erase(iter);
	// delete last dummy Link
	delete last;

	first = a.first;
	last = a.last;

	a.first = nullptr;
	a.last = nullptr;
	
	return *this;
}

template<typename Elem>
List<Elem>::~List()
{
	List<Elem>::iterator iter(first);
	while( iter.curr != last ) iter = erase(iter);
	// delete last dummy Link
	delete last;
}


#endif
