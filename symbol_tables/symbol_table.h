#ifndef GUARD_SYMBOL_TABLE_H
#define GUARD_SYMBOL_TABLE_H

#include <fstream>

template< class Key, class Val>
struct Item
{
  public:
    Item(): n(true), Nsub(0) {}
    Item( Key k, Val v): k(k), v(v), n(false) {}
    Key key() { return k; }
    Val val() { return v; }
    void set_val(Val new_v) { v = new_v;}
    bool null() { return n; }
    void make_null() { n = true; }
    
  private:
    Key k;
    Val v;
    bool n; // true if not initialized
    int Nsub; // number of nodes in the subtree
    
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

        if( x.key() < (*h)->item.key() ) {
             insertR( &(*h)->l, x);
        } else if( x.key() > (*h)->item.key() ) {
             insertR( &(*h)->r, x);
        } else {
             (*h)->item.set_val(x.val() );
        }
        //else      insertR( &(*h)->r, x);
    }


    void showR( Node *h, std::ostream& os)
    {
        if ( h == nullptr) return;
        showR(h->l, os);
        os << h->item.key() << '\t' << h->item.val() << std::endl;
        showR( h->r, os);
    }

    Node * ceilR( Node *h, Key key)
    {
        if( h == nullptr ) return h;
        if( h->item.key() == key ) return h;
        if( h->item.key() < key ) return ceilR( h->r, key);

        Node *t = ceilR(h->l, key);
        if( t == nullptr) return h;
        return t;
    }

    Node * floorR( Node *h, Key key)
    {

        if( h == nullptr ) return h;
        if( h->item.key() == key ) return h;
        if( h->item.key() > key ) return floorR( h->l, key);

        Node *t = floorR(h->r, key);
        if( t == nullptr ) return h;
        return t;
    }

  public:
    ST(): head(nullptr) {}
    ST(int maxN): head(nullptr) {}
    Item<Key, Val> search(Key v) { return searchR( head, v); }
    void insert(Item<Key, Val> x) { insertR( &head, x); }
    void insert(Key k, Val v){ insertR( &head, Item<Key, Val>(k,v) ); }
    void show(std::ostream& os) { showR(head, os); }
     

    Item<Key, Val> min()
    {
        if( head == nullptr ) return nullItem;
        Node *h = head; 
        while( h->l ) h = h->l;
        return h->item;
    }

    Item<Key, Val> max()
    {
        if( head == nullptr ) return nullItem;
        Node *h = head;
        while( h->r ) h = h->r;
        return h->item;
    }
    // return item with smallest key larger that key
    Item<Key, Val> ceil(Key key)
    {
        Node *h = ceilR(head, key);
        if( h == nullptr ) return nullItem;
        return h->item;
    }

    // return item with largest key smaller that key
    Item<Key, Val> floor(Key key)
    {
        Node *h = floorR(head, key);
        if( h == nullptr ) return nullItem;
        return h->item;
    }

    // change to recursive 
    // such that is can be used with
    // Hibbard deletion
    void deleteMin()
    {
        if( head == nullptr ) return;
        Node *h = head;
        if( head->l == nullptr) {
           head = h->r; 
           delete h;
           return; 
        }
        while( h->l->l != nullptr) h = h->l;
        Node *temp = h->l;
        h->l = temp->r;
        delete temp;
    }

    // change to recursive 
    void deleteMax()
    {
        if( head == nullptr ) return;
        Node *h = head;
        if( head->r == nullptr ) {
            head = h->l; 
            delete h; 
            return;
        }
        while( h->r->r != nullptr ) h = h->r;
        Node *temp = h->r;
        h->r = temp->l;
        delete temp;
    }
};


#endif
