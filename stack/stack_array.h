#ifndef GUARD_STACK_H
#define GUARD_STACK_H

#include <iostream>

template< class T>
class Stack
{
  public:
	Stack();
	Stack(int);
	~Stack();

	void push(T d);
	T pop();

	//T peek() const { return top->data; }
	bool empty() const { return N > 0; }

  private:
	T *data;
	int N;		// index of last item
	int Nmax;   // container size

	void resize(int);
};

	

template< class T>
Stack<T>::Stack()
: N(0), Nmax(4)
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
	if( N < Nmax ) {
		data[N++] = d;

	} else {
		// double the size of the array
		resize( Nmax*2 );
		data[N++] = d;
	}

}

template< class T>
T Stack<T>::pop() {

	if( N > 0 ) {
		return data[--N];
	} else {
	}
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




#endif
