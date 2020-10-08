#ifndef GUARD_SYMBOL_TABLE_H
#define GUARD_SYMBOL_TABLE_H

#include <fstream>

template< class Key, class Val>
struct Item
{
  public:
    Item(): n(true) {}
    Item( Key k, Val v): k(k), v(v), n(false) {}
    Key key() { return k; }
    Val val() { return v; }
    bool null() { return n; }
    void make_null() { n = true; }
  private:
    Key k;
    Val v;
    bool n; // true if not initialized
};
    

template< class Key, class Val>
class ST
{
  //private:
  public:
    struct Node
    {
        Node(Item<Key,Val> x) { item = x; l = nullptr; r = nullptr; }
        Item<Key, Val> item;
        Node *l, *r;
    };

    Node *head;
    Item<Key, Val> nullItem;

    Item<Key, Val> searchR( Node *h, Key v)
    {
        if( h == nullptr ) return nullItem;
        Key t = h->item.key();
        if( v == t ) return h->item;
        if( v < t )  return searchR(h->l, v);
        else         return searchR(h->r, v);
    }

    void insertR(Node **h, Item<Key, Val> x)
    {
        if( (*h) == nullptr ) {
            *h = new Node(x);
            return;
        }

        if( x.key() < (*h)->item.key() ) insertR( &(*h)->l, x);
        else      insertR( &(*h)->r, x);
    }

    void showR( Node *h, std::ostream& os)
    {
        if ( h == nullptr) return;
        showR(h->l, os);
        os << h->item.val() << std::endl;
        showR( h->r, os);
    }

  public:
    ST(): head(nullptr) {}
    ST(int maxN): head(nullptr) {}
    Item<Key, Val> search(Key v) { return searchR( head, v); }
    void insert(Item<Key, Val> x) { insertR( &head, x); }
    void show(std::ostream& os) { showR(head, os); }
    
};


#endif
