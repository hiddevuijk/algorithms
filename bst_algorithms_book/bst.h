#ifndef GUARD_BST_H
#define GUARD_BST_H

#include <fstream>

template<class Key, class Val>
class BST
{
  public:
    class Node
    {
      public:
        Node(): left(nullptr), right(nullptr), p(nullptr) {} 
        Node(Key k, Val v): key(k), val(v),
                            left(nullptr), right(nullptr), p(nullptr) {}

        Key key;
        Val val;
        // pntr to left, right and parent node
        Node *left, *right, *p;
    };

  private:
    Node *root;

    void print_in_order(Node *x,  std::ostream& out, char sep) const;
    Node * find(Node *x, Key k) const;
    Node * find_min( Node *x) const;
    Node * find_max( Node *x) const;
    bool check_order(Node *x) const;

    void transplant(Node *u, Node *v); 
  public:
    BST(): root(nullptr) {}
    //~BST();
    void destroy(Node *x);
    void insert(Key k, Val v);
    void print_in_order( std::ostream& out, char sep = '\n') const;
    Node * find(Key k) const;
    Node * find_min() const;
    Node * find_max() const;

    void remove(Node *z);
    void remove(Key k);
    void remove_min();
    void remove_max();

    bool check_order() const; 


};

template<class Key, class Val>
void BST<Key,Val>::remove_min()
{ remove(find_min()); }

template<class Key, class Val>
void BST<Key,Val>::remove_max()
{ remove(find_max()); }

template<class Key, class Val>
void BST<Key,Val>::remove(Key k)
{
    Node *node = find(k);
    if(node != nullptr) remove(node);
}

template<class Key, class Val>
void BST<Key,Val>::remove(Node *z)
{
    if( z->left == nullptr ) {
        transplant(z, z->right);
    } else if( z->right == nullptr ) {
        transplant(z, z->left);
    } else {
        Node *y = find_min(z->right);
        if( y->p != z ) {
            transplant(y,y->right);
            y->right = z->right; 
            y->right->p = y;
        }
        transplant(z,y);
        y->left = z->left;
        y->left->p = y;
    } 
}

// replace Node u with v
template<class Key, class Val>
void BST<Key,Val>::transplant(Node *u, Node *v)
{
    if( u == root ) root = v; 
    else if( u == u->p->left ) u->p->left = v;
    else u->p->right = v;
    if( v != nullptr ) v->p = u->p;
}

template<class Key, class Val>
bool BST<Key,Val>::check_order( Node *x) const
{
    if( x == nullptr) return true;
    if( x->left  != nullptr and x->left->key  > x->key ) return false;
    if( x->right != nullptr and x->right->key < x->key ) return false;
    return true;
}

template<class Key, class Val>
bool BST<Key,Val>::check_order() const
{
    return check_order(root);
}

template<class Key, class Val>
void BST<Key,Val>::insert(Key k, Val v)
{
    Node *new_node = new Node(k,v);

    // current Node
    Node *x = root;
    // xp = parent of x
    Node *xp = nullptr;

    while( x != nullptr ) {
        xp = x;
        if( k < x->key ) x = x->left;
        else if( k > x->key) x = x->right;
        else break;
        //else             x = x->right;
    }

    new_node->p = xp;
    if ( xp == nullptr ) root = new_node;
    else if ( k < xp->key )  xp->left = new_node;
    else if ( k > xp->key )  xp->right = new_node;
    else x->val = v;

}


template<class Key, class Val>
typename BST<Key,Val>::Node * BST<Key, Val>::find(Key k) const
{
    return find(root, k);
}

template<class Key, class Val>
typename BST<Key,Val>::Node * BST<Key, Val>::find_min() const
{ return find_min(root); }

template<class Key, class Val>
typename BST<Key,Val>::Node * BST<Key, Val>::find_min( Node *x) const
{
    if( x == nullptr ) return x;
    while( x->left != nullptr ) x = x->left;
    return x;
}

template<class Key, class Val>
typename BST<Key,Val>::Node * BST<Key, Val>::find_max() const
{ return find_max(root); }

template<class Key, class Val>
typename BST<Key,Val>::Node * BST<Key, Val>::find_max(Node *x) const
{
    if( x == nullptr ) return x;
    while( x->right != nullptr ) x = x->right;
    return x;
}

template<class Key, class Val>
typename BST<Key,Val>::Node * BST<Key, Val>::find(Node* x, Key k) const
{
    while( x != nullptr and k != x->key ) {
        if( k < x->key) x = x->left;
        else x = x->right;

    }
    return x;
    //if( x == nullptr or k == x->key ) return x;
    //if( k < x->key ) return find(x->left, k);
    //else             return find(x->right, k);
}

template<class Key, class Val>
void BST<Key,Val>::print_in_order( std::ostream& out, char sep) const
{ print_in_order(root, out, sep); }

template<class Key, class Val>
void BST<Key,Val>::print_in_order(Node *x, std::ostream& out, char sep) const
{
    if( x != nullptr ) {
        print_in_order(x->left, out, sep);
        out << x->key << '\t' << x->val <<  sep;
        print_in_order(x->right, out, sep);
    }
}

//template<class Key, class Val>
//BST<Key,Val>::~BST()
//{
//    destroy(root);
//    delete root;
//}


template<class Key, class Val>
void BST<Key,Val>::destroy(Node *x)
{
    if( x == nullptr)  return;
    if( x->left != nullptr) {
        destroy(x->left);
        delete x->left;
    }
    if( x->right != nullptr ) {
        destroy(x->right);
        delete x->right;
    } 

}

#endif
