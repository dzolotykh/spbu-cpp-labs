#ifndef LAB2_AXE_H
#define LAB2_AXE_H

#include "Hero.h"

class Axe : public Hero {
 private:
  const int base_strength = 50;
  const int base_agility = 20;
  const int base_intelligence = 11;
  const int base_damage = 78;
  const int base_max_health = 900;
  const int base_max_mana = 200;

 public:
  Axe();
  void ability(Entity *e) override;
};

#endif // LAB2_AXE_H
