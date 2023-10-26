#ifndef LAB2_PUCK_H
#define LAB2_PUCK_H


#include "Hero.h"

class Puck: public Hero {
private:
    const int base_strength = 15;
    const int base_agility = 23;
    const int base_intelligence = 41;
    const int base_damage = 40;
    const int base_max_health = 600;
    const int base_max_mana = 700;
public:
    Puck();
};

#endif
