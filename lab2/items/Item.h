#ifndef LAB2_ITEM_H
#define LAB2_ITEM_H

class Item {
private:
    int add_health;
    int add_mana;
    int add_strength;
    int add_agility;
    int add_intelligence;

public:
    Item(int _add_health = 0, int _add_mana = 0, int _add_strength = 0, int add_agility = 0, int add_intelligenct = 0);

    int get_add_health() const;

    int get_add_mana() const;

    int get_add_strength() const;

    int get_add_agility() const;

    int get_add_intelligence() const;
};


#endif
