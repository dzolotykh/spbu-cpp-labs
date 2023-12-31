#ifndef LAB2_HERO_H
#define LAB2_HERO_H

#include "../../inventory/Inventory.h"
#include "../Entity.h"
#include <memory>

class Hero : public Entity {
 protected:
  std::unique_ptr<Inventory> inventory;
  int strength;
  int agility;
  int intelligence;
  std::string name;

 public:
  Hero();
  virtual ~Hero();

  Hero(int _max_health, int _max_mana, int _damage);

  void add_item(Item* i);
  void use_item(int item_id, std::shared_ptr<Hero> &target);

  void add_strength(int _add);
  void add_agility(int _add);
  void add_intelligence(int _add);

  std::string get_name() const;
  std::string get_stats() const;

  virtual void ability(Entity *e) = 0;
};

#endif // LAB2_HERO_H
