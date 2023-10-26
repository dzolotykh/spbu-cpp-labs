#ifndef LAB2_ALCHEMIST_H
#define LAB2_ALCHEMIST_H

#include "Hero.h"

class Alchemist : public Hero {
 private:
  const int base_strength = 23;
  const int base_agility = 22;
  const int base_intelligence = 25;
  const int base_damage = 56;
  const int base_max_health = 626;
  const int base_max_mana = 375;

 public:
  Alchemist();
};

#endif  // LAB2_ALCHEMIST_H
