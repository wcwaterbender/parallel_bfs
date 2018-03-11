#ifndef PENNANT_H
#define PENNANT_H

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
    Pennant unify(Pennant x, Pennant y);
    Pennant split(Pennant x);

  private:
    node *root
    //size must always be 2^k
    int size;
    
};

#endif
