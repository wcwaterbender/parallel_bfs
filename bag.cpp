#include "Bag.h"
Bag::Bag(){
  backbone = new (Pennant*)[32];
  size = 32;
}

Bag::~Bag(){
  delete [] backbone;
}

void Bag::insert(int key){
  //create Pennant
  Pennant x;

  //insert x key into Pennant
  x.insert(key);
  int k = 0;
  //loop thru backbone
  while(backbone[k]!=NULL){
    x = unify(*backbone[k],x);
    backbone[k++] = NULL;
  }
*backbone[k] = x;
}

vector<Pennant> Bag::fullAdd(Pennant x, Pennant y, Pennant z) {
  //implement assignment operator
  vector<Pennant> output;
  Pennant s;
  Pennant c;

  if(x.is_empty()&&y.is_empty()&&z.is_empty()){
    //do nothing
  }

  else if(!(x.is_empty())&&y.is_empty()&&z.is_empty()){
    s = x;
  }

  else if(x.is_empty()&&!(y.is_empty())&&z.is_empty()){
    s = y;
  }

  else if(x.is_empty()&&y.is_empty()&&!(z.is_empty())){
    s = z;
  }

  else if(!(x.is_empty())&&!(y.is_empty())&&z.is_empty()){
    c = unify(x,y);
  }

  else if(!(x.is_empty())&&y.is_empty()&&!(z.is_empty())){
    c = unify(x,z);
  }

  else if(x.is_empty()&&!(y.is_empty())&&!(z.is_empty())){
    c = unify(y,z);
  }

  else if(!(x.is_empty())&&!(y.is_empty())&&!(z.is_empty())){
    s = x;
    c = unify(y,z);
  }
  output.push_back(s);
  output.push_back(c);
  return output;

}

void Bag::unite(Bag s1){
  Pennant y; //the carry bit
  vector<Pennant> vars;
  for(int k = 0; k<size; ++k){
    vars = fullAdd(*(backbone)[k], *(s1.backbone)[k], y);
    *(backbone)[k] = vars[0];
    y = vars[1];
  }
}

Bag Bag::split(Bag s1){
  Bag s2;
  Pennant y = *(s1.backbone[0]);
  *(s1.backbone[0]) = NULL;
  for(int k = 1; k < s1.size; k++) {
    if (*(sl.backbone[0]) != NULL) {
      *(s2.backbone[k-1]) = Pennant::split(*(s1.backbone[k]));
      *(s1.backbone[k-1]) = *(s1.backbone[k]);
      *(s1.backbone[k]) = NULL;
    }
  }
  if (y != NULL)
    insert(s1, y);
  return s2;
}

int Bag::getSize(){
  return this->size;
}
