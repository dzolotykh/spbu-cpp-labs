#include "Inventory.h"

Inventory::Inventory() {
    this->items_count = 0;
    this->contains = new Item*[6];
    for (int i = 0; i < 6; ++i) {
        this->contains[i] = nullptr;
    }
}

Inventory::~Inventory() {
    delete[] this->contains;
}

void Inventory::add_item(Item* item) {
    if (this->items_count == 6) {
        throw std::overflow_error("The maximum value of items in inventory is 6.");
    }
    this->contains[this->items_count] = item;
    this->items_count++;
}

Item* Inventory::operator[](int index) {
    if (index >= this->items_count) {
        throw std::overflow_error("There isn't element with index " + std::to_string(index));
    }
    return this->contains[index];
}
