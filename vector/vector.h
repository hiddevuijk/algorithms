#ifndef GAURD_VECTOR_H
#define GAURD_VECTOR_H

#include <iostream>

#include <algorithm>
#include <initializer_list>

class Vector{
public:
	// constructor
	 explicit Vector(int s)
		: sz(s), elem( new double[s] )
		{
			for( int i=0; i<sz; ++i) elem[i] = 0.0;
		}

	// initializer list constructor
	Vector( std::initializer_list<double> lst )
		: sz( lst.size() ), elem( new double[sz] )
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

	double& operator[](int n){ return elem[n]; }
	double operator[](int n) const { return elem[n]; }
	double get(int n) const { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }

private:
	int sz;
	double* elem;
};

// copy constructor
Vector::Vector( const Vector& arg)
	: sz( arg.sz ), elem( new double[arg.sz])
{
	//std::copy(arg, arg+sz, elem);
	for( int i=0; i<sz; ++i) elem[i] = arg.get(i);
}

// copyt assignment
Vector& Vector::operator=( const Vector& a )
{

	// do nothin if self-assignment,
	// not used for speed
	//if( this == &a) { return *this; }

	double* p = new double[a.sz];
	std::copy(a.elem, a.elem+a.sz, elem);
	delete[] elem;
	elem = p;
	sz = a.sz;

	return *this;
}

//move constructor
Vector::Vector( Vector&& a )
	: sz(a.sz), elem( a.elem )
{
	a.sz = 0;
	a.elem = nullptr;
}

// move assignment
Vector& Vector::operator=( Vector&& a)
{
	delete[] elem;
	elem = a.elem;
	sz = a.sz;

	a.elem = nullptr;	
	a.sz = 0;

	return *this;
}

#endif
