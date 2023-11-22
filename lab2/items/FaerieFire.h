#ifndef LAB2_FAERIEFIRE_H
#define LAB2_FAERIEFIRE_H

#include "Item.h"
#include <thread>
#include <vector>

class FaerieFire : public Item {
public:
  void apply(Hero *h) override;
};

#endif
