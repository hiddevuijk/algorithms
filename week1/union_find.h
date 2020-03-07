#ifndef GUARD_UNION_FIND_H
#define GUARD_UNION_FIND_H

class QF_UF {
public:
	QF_UF(int N);

	void add_union(int p, int q);
	bool connected(int p, int q);
	int find(int p);
	int count();



};



#endif
