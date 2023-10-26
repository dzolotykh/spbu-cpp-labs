#ifndef LAB2_DAZZLE_H
#define LAB2_DAZZLE_H

#include "Hero.h"


class Dazzle: public Hero {
private:
    const int base_strength = 30;
    const int base_agility = 30;
    const int base_intelligence = 30;
    const int base_damage = 57;
    const int base_max_health = 531;
    const int base_max_mana = 612;
public:
    Dazzle();
};


#endif
