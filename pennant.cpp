#include "Pennant.h"
Pennant::Pennant(){
  root=NULL;
  size=1;
}
Pennant::Pennant unify(Pennant x, Pennant y){
  y->root->right = x->root->left;
  x->root->left = y->root;
  return x;
}

Pennant::Pennant split(Pennant x){
  Pennant y;
  y->root = x->root->left;
  x->root->left=y->root->right;
  y->root->right = NULL;
  return y;
}
