#ifndef LAB2_PUDGE_H
#define LAB2_PUDGE_H

#include "Hero.h"

class Pudge : public Hero {
 private:
  const int base_strength = 25;
  const int base_agility = 14;
  const int base_intelligence = 16;
  const int base_damage = 70;
  const int base_max_health = 700;
  const int base_max_mana = 228;

 public:
  Pudge();
};

#endif
