#ifndef INVENTORY_H
#define INVENTORY_H

#include "../items/Item.h"
#include <iostream>

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
