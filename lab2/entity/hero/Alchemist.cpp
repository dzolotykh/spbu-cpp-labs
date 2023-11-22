#include <thread>
#include "Alchemist.h"

Alchemist::Alchemist() {
  this->health = this->max_health = this->base_max_health;
  this->mana = this->max_mana = this->base_max_mana;
  this->damage = this->base_damage;
  this->agility = this->base_agility;
  this->intelligence = this->base_intelligence;
  this->strength = this->base_strength;
  this->name = "Alchemist";
}

void Alchemist::ability(Entity *e) {
    auto *t = new std::thread([this]() {
        for (int i = 0; i < 5; i++) {
            if (!this->is_alive())
                break;
            this->add_health(25);
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    });
    ability_threads.push_back(t);
}

Alchemist::~Alchemist() {
    this->set_health(0);
    for (auto &i : ability_threads) {
        i->join();
        delete i;
    }
}

