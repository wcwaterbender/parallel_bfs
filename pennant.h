#ifndef PENNANT_H
#define PENNANT_H
using namespace std;
struct node{
  int data;
  node *right,*left;
}


class Pennant{
  public:
    Pennant();
    ~Pennant();
    void insert(int key);
    bool is_complete(int cur_level);
    bool is_empty();
    Pennant unify(Pennant x, Pennant y);
    Pennant split(Pennant x);
    node *root;
  private:

    //size must always be 2^k
    int size;

};

#endif
