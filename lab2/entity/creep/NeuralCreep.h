#ifndef LAB2_NEURALCREEP_H
#define LAB2_NEURALCREEP_H

#include "../../inventory/Inventory.h"
#include "Creep.h"

class NeuralCreep : public Creep {
 private:
  Inventory* inventory;

 public:
  NeuralCreep(Item* _item);
  ~NeuralCreep();
};

#endif
