#ifndef GUARD_LIST_H
#define GUARD_LIST_H

#include <string>

struct Link {
public:
	std::string value;

	Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
		: value(v), prev{p}, succ{s} {}	

	
	// insert n before p, return n
	Link* add(Link* n);
	//insert n after p, return n
	Link* insert(Link* n);
	// remove  *p from list, return p's successor
	Link* erase();

	// find s in list, return nullptr if not found
	Link* find(const std::string& s);

//private:
	Link* prev;
	Link* succ;

};


Link* Link::add(Link* n)
{

	if( n==nullptr ) return this;
	if( this==nullptr ) return n;

	n->prev = this;
	if( succ ) succ->prev = n;
	n->succ = succ;
	succ = n;

	return n;
}


Link* Link::insert( Link* n)
{
	if( n==nullptr ) return this;
	if( this==nullptr ) return n;
	n->succ = this;
	if(prev) prev->succ = n;
	n->prev = prev;
	prev = n;

	return n;
}

Link* Link::erase()
{

	if( this==nullptr ) return nullptr;
	if( succ ) succ->prev = prev;
	if( prev ) prev->succ = succ;
	return succ;
}

Link* find(Link* p, const std::string& s)
{
	while(p) {
		if(p->value == s ) return p;
		p = p->succ;
	}
	return nullptr;
}

// move n positions in list,
// return nullptr for not found
Link* advance(Link* p, int n)
{
	if( p==nullptr ) return nullptr;
	if( 0<n ) {
		while( n-- ) {
			if( p->succ == nullptr ) return nullptr;
			p = p->succ;
		}
	}
	else if( n<0 ) {
		while( n++ ) {
			if( p->prev == nullptr ) return nullptr;
			p = p->prev;
		}
	}

	return p;
}

#endif
