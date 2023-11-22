#include "Inventory.h"

Inventory::Inventory() {
  items_count = 0;
  for (int i = 0; i < 3; ++i) {
    contains[i] = nullptr;
  }
}

void Inventory::add_item(Item* item) {
  contains[items_count] = item;
}

Item* Inventory::operator[](int index) {
  return this->contains[index];
}
