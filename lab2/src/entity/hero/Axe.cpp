#include "Axe.h"

Axe::Axe() {
  this->health = this->max_health = this->base_max_health;
  this->mana = this->max_mana = this->base_max_mana;
  this->damage = this->base_damage;
  this->agility = this->base_agility;
  this->intelligence = this->base_intelligence;
  this->strength = this->base_strength;
  this->name = "Axe";
}

void Axe::ability(Entity *e) {
    if ((double)e->get_health() < (double)e->get_max_health() * 0.2) {
        e->set_health(0);
    } else {
        e->add_health(-10);
    }
}