#ifndef GUARD_UNION_FIND_H
#define GUARD_UNION_FIND_H

#include <vector>


class QuickFindUF {
private:
    std::vector<int> id;
public:
    QuickFindUF() {};
    QuickFindUF(int N) {
        id = std::vector<int>(N);
        for(int i=0;i<N;++i) 
            id[i] = i;
    }

    bool connected(int p, int q)
    { return id[p] == id[q]; }

    void add_union(int p, int q)
    {
        int pid = id[p];
        int qid = id[q];
        for(int i=0; i< id.size(); ++i)
           if(id[i] == pid) id[i] = qid; 
    }
};
    
class QuickUnionUF {
private:
    std::vector<int> id;

    int root(int i)
    {
        while(i != id[i] ) i = id[i];
        return i;
    } 
public:
    QuickUnionUF() {}
    QuickUnionUF(int N)
    {
        id = std::vector<int>(N);
        for(int i=0;i<N;++i)
            id[i] = i;
    }

    bool connected(int p, int q)
    { return root(p) == root(q);} 

    void add_union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }

};

class QuickUnionWUF {
private:
    std::vector<int> id;
    std::vector<int> sz;

    int root(int i)
    {
        while(i != id[i] ){
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    } 
public:
    QuickUnionWUF() {}
    QuickUnionWUF(int N)
    {
        id = std::vector<int>(N);
        sz = std::vector<int>(N,1);
        for(int i=0;i<N;++i) {
            id[i] = i;
        }
    }

    bool connected(int p, int q)
    { return root(p) == root(q);} 

    void add_union(int p, int q)
    {
        int i = root(p);
        int j = root(q);
        if( i == j) return; 
        if( sz[i] < sz[j]) { 
            id[i]=j; sz[j] += sz[i];
        } else {
            id[j]=i; sz[i] += sz[j];
        }
    }

};



#endif
