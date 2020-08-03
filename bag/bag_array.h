#ifndef GUARD_STACK_H
#define GUARD_STACK_H

#include <exception>



template< class T>
class Bag
{
  public:
	Bag();
	Bag(int);
	~Bag();

	// copy constructor
	Bag(const Bag<T>& );

	// copy assignment
	Bag<T>& operator=( const Bag<T>&);
	// move assignment
	Bag<T>& operator=( Bag<T>&&);
	

	void push(T d);

	bool empty() const { return N > 0; }

    int size() const { return N;}
    int capacity() const { return Nmax;}


    class Iterator;
    Iterator begin();


  private:
	T *data;
	int N;		// index of last item
	int Nmax;   // container size

	void resize(int);
};

// move assignment
template< class T>
Bag<T>& Bag<T>::operator=( Bag<T>&& rhs)
{

	if( &rhs == this ) return *this;

	delete data;

	N = rhs.N;
	Nmax = rhs.Nmax;
	data = rhs.data;
	rhs.data = nullptr;

	return *this;
}

// copy assignment
template< class T>
Bag<T>& Bag<T>::operator=( const Bag<T>& rhs )
{
	if( &rhs == this ) return *this;

	delete[] data;	
	data = new T[rhs.Nmax];
	N = rhs.N;
	for( int i=0; i<N ; ++i )
		data[i] = rhs.data[i];

	return *this;
}

// copy constructor
template< class T>
Bag<T>::Bag( const Bag<T>& s)
{

	Nmax = s.Nmax;
	N = s.N;

	data = new T[Nmax];
	for(int i=0; i< N; ++i) {
		data[i] = s.data[i];
	}

}
	

template< class T>
Bag<T>::Bag()
: N(0), Nmax(2)
{
	data = new T[Nmax];

}

template< class T>
Bag<T>::Bag(int Nmax)
: N(0), Nmax(Nmax) 
{
	data = new T[Nmax];

}

template< class T>
Bag<T>::~Bag() {
	delete[] data;	
}


template< class T>
void Bag<T>::push( T d) {

    // double the size of the arry if it becomes to short
    if( N == Nmax ) resize( Nmax*2 );
    data[N++] = d;
}

template< class T>
void Bag<T>::resize(int Nmax_new) {


	T* temp = new T[Nmax_new];
	int i_max  = Nmax_new < N ? Nmax_new : N;
	for( int i = 0; i< i_max; ++i ) {
		temp[i] = data[i];
	}

	delete[] data;
	Nmax = Nmax_new;
	data = temp;
}

template<class T>
typename Bag<T>::Iterator Bag<T>::begin()
{
    Iterator it(N-1, data );
    return it;
}

//------------------------------
// Iterator
//------------------------------

template<class T>
class Bag<T>::Iterator {
public:
    Iterator(int n, T* data_ptr ) : i(0),n(n), data_ptr(data_ptr) {};

    bool hasNext() const { return i >=0; }

    Iterator& operator++() { ++i; return *this; }
    T& operator*() const { return data_ptr[n-i]; }

private:
    int i;
    int n;
    T* data_ptr;

};



#endif
