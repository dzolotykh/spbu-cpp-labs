#ifndef LAB2_ALCHEMIST_H
#define LAB2_ALCHEMIST_H

#include "Hero.h"
#include <vector>
#include <thread>

class Alchemist : public Hero {
 private:
  const int base_strength = 23;
  const int base_agility = 22;
  const int base_intelligence = 25;
  const int base_damage = 56;
  const int base_max_health = 626;
  const int base_max_mana = 375;
  std::vector<std::thread*> ability_threads;


 public:
  Alchemist();
  void ability(Entity *e) override;
  ~Alchemist();
};

#endif  // LAB2_ALCHEMIST_H
