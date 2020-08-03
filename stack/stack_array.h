#ifndef GUARD_STACK_H
#define GUARD_STACK_H

#include <exception>



template< class T>
class Stack
{
  public:
	Stack();
	Stack(int);
	~Stack();

	// copy constructor
	Stack(const Stack<T>& );

	// copy assignment
	Stack<T>& operator=( const Stack<T>&);
	// move assignment
	Stack<T>& operator=( Stack<T>&&);
	

	void push(T d);
	T pop();

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
Stack<T>& Stack<T>::operator=( Stack<T>&& rhs)
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
Stack<T>& Stack<T>::operator=( const Stack<T>& rhs )
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
Stack<T>::Stack( const Stack<T>& s)
{

	Nmax = s.Nmax;
	N = s.N;

	data = new T[Nmax];
	for(int i=0; i< N; ++i) {
		data[i] = s.data[i];
	}

}
	

template< class T>
Stack<T>::Stack()
: N(0), Nmax(2)
{
	data = new T[Nmax];

}

template< class T>
Stack<T>::Stack(int Nmax)
: N(0), Nmax(Nmax) 
{
	data = new T[Nmax];

}

template< class T>
Stack<T>::~Stack() {
	delete[] data;	
}


template< class T>
void Stack<T>::push( T d) {

    // double the size of the arry if it becomes to short
    if( N == Nmax ) resize( Nmax*2 );
    data[N++] = d;
}

template< class T>
T Stack<T>::pop() {

	//if( N > 0 ) {
	//	return data[--N];
	//} else {
    //    throw std::range_error( "pop from emtpy stack");
	//}

    T datum = data[--N];

    if( N > 0 && N == Nmax/4 ) resize( Nmax/2 );

    return datum;
    
}

template< class T>
void Stack<T>::resize(int Nmax_new) {


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
typename Stack<T>::Iterator Stack<T>::begin()
{
    Iterator it(N-1, data );
    return it;
}

//------------------------------
// Iterator
//------------------------------

template<class T>
class Stack<T>::Iterator {
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
