#ifndef GAURD_VECTOR_H
#define GAURD_VECTOR_H

#include <iostream>

#include <algorithm>
#include <initializer_list>

template<typename T>
class Vector{
public:
	// default constructor
	Vector() : sz(0), elem(nullptr), space(0) {}
	// constructor
	 explicit Vector(int s)
		: sz(s), elem( new T[s] ), space(s)
		{
			for( int i=0; i<sz; ++i) elem[i] = 0.0;
		}

	// initializer list constructor
	Vector( std::initializer_list<T> lst )
		: sz( lst.size() ), elem( new T[sz] )
		{
			std::copy( lst.begin(), lst.end(), elem );
		}

	// copy constructor
	Vector( const Vector&);
	// copy assignment
	Vector& operator=( const Vector& );
	// move constructor
	Vector( Vector&&);
	// move assignment
	Vector& operator=( Vector&& );

	// destructor
	~Vector()
		{ delete[] elem; }	


	int size() const { return sz; }
	int capacity() const { return space; }

	T& operator[](int n){ return elem[n]; }
	T operator[](int n) const { return elem[n]; }
	T get(int n) const { return elem[n]; }
	void set(int n, T v) { elem[n] = v; }

	void reserve(int newalloc);
	void resize(int newsize);
	void push_back(T d);

private:
	int sz;
	T* elem;
	int space;

};

// copy constructor
template<typename T>
Vector<T>::Vector( const Vector<T>& arg)
	: sz( arg.sz ), elem( new T[arg.sz]), space(arg.space)
{
	//std::copy(arg, arg+sz, elem);
	for( int i=0; i<sz; ++i) elem[i] = arg.get(i);
}



//move constructor
template<typename T>
Vector<T>::Vector( Vector<T>&& a )
	: sz(a.sz), elem( a.elem ), space(a.space)
{
	a.sz = 0;
	a.space = 0;
	a.elem = nullptr;
}

// move assignment
template<typename T>
Vector<T>& Vector<T>::operator=( Vector<T>&& a)
{
	delete[] elem;
	elem = a.elem;
	sz = a.sz;
	space = a.space;

	a.elem = nullptr;	
	a.sz = 0;
	a.space = 0;

	return *this;
}

// increse the size of elem,
// don't initialize
template<typename T>
void Vector<T>::reserve(int newalloc)
{
	if( newalloc <= space ) return;
	T* p = new T[newalloc];
	for(int i=0;i<sz; ++i ) p[i] = elem[i];
	delete[] elem;
	elem = p;
	space = newalloc;
}


// make the vector have newsize elements
// initialize each new element with 0.0
template<typename T>
void Vector<T>::resize(int newsize)
{
	reserve(newsize);
	for(int i=sz; i<newsize; ++i ) elem[i] = 0;
	sz = newsize;
}

template<typename T>
void Vector<T>::push_back(T d)
{
	if(space == 0 ) {
		reserve(8); // start with space for 8 elements
	} else if(sz == space) {
		reserve(2*space); // get more space
	}

	elem[sz] = d;
	++sz;

}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& a)
{
	if( this == &a ) return *this; // do nothing if self-assignment


	// enough space
	if( a.sz <= space ) {
		for(int i=0; i<a.sz; ++i) elem[i] = a.elem[i];
		sz = a.sz;
		return *this;
	}


	T* p = new T[a.sz];
	for(int i=0;i<a.sz; ++i ) p[i] = a.elem[i];
	delete[] elem;
	space = sz = a.sz;
	elem = p;
	return *this;
}

#endif
