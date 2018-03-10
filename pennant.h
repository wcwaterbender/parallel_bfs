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
    node *search(int key);
    void destroy_tree();
    bool is_balanced();
    Pennant unify(Pennant x, Pennant y);
    Pennant split(Pennant x);

  private:
    node *root
    //size must always be 2^k
    int size;
};

#endif
