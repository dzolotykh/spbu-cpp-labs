#include <iostream>
#include <vector>

#include "entity/creep/FractionCreep.h"
#include "entity/hero/Pudge.h"
#include "game/Game.h"
#include "items/FaerieFire.h"
#include "items/Tango.h"
#include "team/Team.h"

void test1(bool happy_end) {
  std::cout << "test 1" << std::endl;
  Hero* hero = new Pudge();
  std::vector<FractionCreep*> creeps = {
      new FractionCreep(false, 1),
      new FractionCreep(false, (happy_end ? 1 : 2)),
      new FractionCreep(false, (happy_end ? 1 : 3)),
  };

  while (hero->is_alive() && !creeps.empty()) {
    int old_creep_hp = creeps[0]->get_health();
    hero->attack(creeps[0]);
    std::cout << "Pudge has attacked creep. Creep hp " << old_creep_hp
              << " ---> " << creeps[0]->get_health() << std::endl;
    if (!creeps[0]->is_alive()) {
      std::cout << "Creep died." << std::endl;
      creeps.erase(creeps.begin());
    }
    for (auto& i : creeps) {
      int old_pudge_hp = hero->get_health();
      i->attack(hero);
      std::cout << "Creep has attacked Pudge. Pudge hp " << old_pudge_hp
                << " ---> " << hero->get_health() << std::endl;
      if (!hero->is_alive()) {
        break;
      }
    }
  }

  if (!hero->is_alive()) {
    std::cout << "Pudge died :((" << std::endl;
  } else {
    std::cout << "Pudge has killed all creeps. Pudge's health: "
              << hero->get_health() << std::endl;
  }
}

void test2() {
  std::cout << "test 2" << std::endl;
  Hero* hero = new Pudge();
  std::cout << "Pudge's health: " << hero->get_health() << std::endl;

  Item* item = new Tango();
  Item* item2 = new FaerieFire();
  hero->add_item(item);
  hero->add_item(item2);
  Creep* creep = new FractionCreep(false, 1);
  creep->attack(hero);
  std::cout << "Creep has attacked Pudge. Pudge's hp: " << hero->get_health()
            << std::endl;
  std::cout << "Used item with index = 0 (tango, + 20hp)" << std::endl;
  hero->use_item(0);
  std::cout << "Pudge's health: " << hero->get_health() << std::endl;
}

void test3() {
  std::cout << "test 3" << std::endl;
  Game* g = new Game();
  g->start(123);
}

int main() {
  test1(true);
  std::cout << "--------------------------" << std::endl;
  test2();
  std::cout << "--------------------------" << std::endl;
  test3();
}
