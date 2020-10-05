#ifndef GUARD_ITEM_H
#define GUARD_ITEM_H

#include <stdlib.h>
#include <iostream>


static int maxKey = 1000;
typedef int Key;

class Item
{
  private:
    Key keyval;
    float info;

  public:
    Item() { keyval = maxKey; }
    Key key() { return keyval; }
    int null() { return keyval==maxKey; }
    void rand()
    {
        keyval = 1000.*::rand()/RAND_MAX;
        info = 1.0*::rand()/RAND_MAX;
    }
    void scan( std::istream& is = std::cin)
        { std::cin >> keyval >> info;}
        //{ return (is>>keyval >> info) != 0;}
    void show(std::ostream& os = std::cout)
        { os << keyval << " " << info << std::endl; }

};

std::ostream& operator<<(std::ostream& os, Item& x)
    { x.show(os); return os; }

#endif
