#ifndef GAURD_VECTOR_H
#define GAURD_VECTOR_H


class Vector{
public:
	Vector(int s)
		: sz(s)
		{
			elem = new double[s];
		}
	~Vector()
		{ delete[] elem; }	

	int size() const { return sz; }

	double get(int n) { return elem[n]; }
	void set(int n, double v) { elem[n] = v; }

private:
	int sz;
	double* elem;
};


#endif
