#include "Pennant.h"
Pennant::Pennant(){
  root=NULL;
  size=0;
  numlevels=0;
}
Pennant::~Pennant()[
  delete [] root;
]
void Pennant::insert(int key){
  node *temp;
  temp->data = key;

  //if first element in bag(0th level)
  if (this->root == NULL){
    this->root = temp;
    this->size++;
  }
  else if(this->root->left ==NULL){//1st level is far as we need to go
    this->root->left=temp;
    this->size++;
  }

}

bool Pennant::is_complete(int cur_level){
  if(2**(cur_level) == this->size){
    return true;
  }
  return false;
}

Pennant Pennant::unify(Pennant x, Pennant y){
  y->root->right = x->root->left;
  x->root->left = y->root;
  x->size+=y->size;
  return x;
}

Pennant Pennant::split(Pennant x){
  Pennant y;
  y->root = x->root->left;
  x->root->left=y->root->right;
  y->root->right = NULL;
  return y;
}
