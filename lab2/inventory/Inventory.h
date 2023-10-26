#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>

#include "../items/Item.h"

class Inventory {
 private:
  Item** contains;
  size_t items_count;

 public:
  Inventory();
  ~Inventory();

  void add_item(Item* item);
  Item* operator[](int index);
};

#endif
