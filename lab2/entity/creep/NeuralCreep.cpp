#include "NeuralCreep.h"

NeuralCreep::NeuralCreep(Item *_item) : Creep(100, 0, 50) {
  this->inventory = new Inventory();
  this->inventory->add_item(_item);
}

NeuralCreep::~NeuralCreep() { delete this->inventory; }
