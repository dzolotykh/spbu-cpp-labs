#include "Item.h"


Item::Item(int _add_health, int _add_mana, int _add_strength, int _add_agility, int _add_intelligence)
        : add_health(_add_health), add_mana(_add_mana), add_strength(_add_strength),
          add_agility(_add_agility), add_intelligence(_add_intelligence) {}

int Item::get_add_health() const {
    return add_health;
}

int Item::get_add_mana() const {
    return add_mana;
}

int Item::get_add_strength() const {
    return add_strength;
}

int Item::get_add_agility() const {
    return add_agility;
}

int Item::get_add_intelligence() const {
    return add_intelligence;
}
