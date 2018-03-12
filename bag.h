#ifndef BAG_H
#define BAG_H

#include "Pennant.cpp"
#include <vector>
using namespace std;

class Bag{
  public:
    Bag();
    ~Bag();
    void insert(int key);
    Bag unite(Bag s1, Bag s2);
    Bag split(Bag s);
    int getSize();
    vector<Pennant> fullAdd(vector<Pennant> input);

  private:
    Pennant** backbone;
    int size;
};

#endif
