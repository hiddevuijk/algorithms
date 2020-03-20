
#include "stack.h"
#include "queue.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace stack_ll;
using namespace queue_ll;

int main()
{

	int N = 10;
	
	Queue<int> q;
	for(int i=0;i<N; ++i) q.enqueue(i);
	Queue<int>::iterator q_iter = q.begin();
	
	while( q_iter.hasNext() ) {
		cout << *q_iter << endl;
		++q_iter;
	}
	cout << endl;
	Stack<int> s;
	for(int i=0; i<N; ++i) s.push(i);
	Stack<int>::iterator s_iter = s.begin();
	while( s_iter.hasNext() ) {
		cout << *s_iter << endl;
		++s_iter;
	}

	return 0;
}


