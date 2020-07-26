#ifndef GUARD_QUEUE_H
#define GUARD_QUEUE_H

// single link in a list
template<typename Elem>
class Link {
public:
	Link* prev;
	Link* succ;
	Elem val;
};




#endif
