#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>

#include "../items/Item.h"

class Inventory {
 private:
  std::array<Item*, 3> contains;
  size_t items_count;

 public:
  Inventory();

  void add_item(Item* item);
  Item* operator[](int index);
};

#endif
