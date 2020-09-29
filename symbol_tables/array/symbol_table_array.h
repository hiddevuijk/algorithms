#ifndef GUARD_SYMBOL_TABLE_ARRAY_U
#define GUARD_SYMBOL_TABLE_ARRAY_U

template< class Key, class Value>
class ST {
public:
    ST();

    void put(Key key, Value val);
    Value get(Key key) const; 
    void del(Key key);
    bool contains(Key key) const;
    bool isEmpty() const { return N == 0; }
    int size() const { return N; }
    // iterable ...

private:
   int N; 


};


#endif
