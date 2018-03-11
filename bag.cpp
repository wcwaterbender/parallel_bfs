#include "Bag.h"
Bag::Bag(){
  backbone = new (Pennant*)[100];
  thiis->size = 100;
}

Bag::Bag(int size){
  backbone = new (Pennant*)[size];
  this->size = size;
}

Bag::~Bag(){
  delete [] backbone;
}

void Bag::insert(int key){

}

Bag Bag::unite(Bag s1, Bag s2){

}

Bag Bag::divide(Bag s){

}

int Bag::getSize(){
  return this->size;
}
