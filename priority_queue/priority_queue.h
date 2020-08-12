#ifndef GUARD_PRIORITY_QUEUE_H
#define GUARD_PRIORITY_QUEUE_H

template<class Item>
class PQ{
public:
    PQ(int maxN)
        { pq = new Item[maxN+1]; N=0; }

    bool empty() const
        { return N==0; }

    void insert(Item item);    

    Item getmax();



private:
    Item *pq; 
    int N; 

    bool less( int i, int j) const
        { return pq[i] < pq[j]; }

    void exch(int i, int j)
        { Item item = pq[i]; pq[i] = pq[j] ; pq[j] = item; }

    void swim(int k)
        {
            while( k>1 && less(k/2,k) )
            { exch(k/2, k); k /= 2; }
        }


    void sink(int k)
        {
            while( 2*k <= N ){
                
            }

        }

};



#endif
