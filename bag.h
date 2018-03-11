#ifndef BAG_H
#define BAG_H

#include "Pennant.cpp"

class Bag{
  public:
    Bag();
    Bag(int size);
    ~Bag();
    void insert(int key);
    Bag unite(Bag s1, Bag s2);
    Bag divide(Bag s);
    int getSize();


  private:
    Pennant** backbone;
    int size;
};

#endif
