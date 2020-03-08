#ifndef GUARD_LIST_H
#define GUARD_LIST_H

#include <string>

struct Link {
public:
	std::string value;
	Link* prev;
	Link* succ;
	Link(const std::string& v, Link* p = nullptr, Link* s = nullptr)
		: value(v), prev{p}, succ{s} {}	


};


// insert n before p, return n
Link* add(Link* p, Link* n)
{

	if( n==nullptr ) return p;
	if( p==nullptr ) return n;

	n->prev = p;
	if(p->succ) p->succ->prev = n;
	n->succ = p->succ;
	p->succ = n;

	return n;
}


	//insert n after p, return n
Link* insert(Link* p, Link* n)
{
	if( n==nullptr ) return p;
	if( p==nullptr ) return n;
	n->succ = p;
	if(p->prev) p->prev->succ = n;
	n->prev = p->prev;
	p->prev = n;
	return n;
}

// remove  *p from list, return p's successor
Link* erase(Link* p)
{

	if( p==nullptr ) return nullptr;
	if( p->succ ) p->succ->prev = p->prev;
	if( p->prev ) p->prev->succ = p->succ;
	return p->succ;
}

Link* find(Link* p, const std::string& s)
{
	while(p) {
		if(p->value == s ) return p;
		p = p->succ;
	}
	return nullptr;
}

#endif
