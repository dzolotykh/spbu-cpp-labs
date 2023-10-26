#ifndef LAB2_SNIPER_H
#define LAB2_SNIPER_H


#include "Hero.h"

class Sniper: public Hero {
private:
    const int base_strength = 15;
    const int base_agility = 40;
    const int base_intelligence = 21;
    const int base_damage = 90;
    const int base_max_health = 400;
    const int base_max_mana = 300;
public:
    Sniper();
};

#endif