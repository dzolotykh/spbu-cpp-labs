#include "Sniper.h"

Sniper::Sniper() {
  this->health = this->max_health = this->base_max_health;
  this->mana = this->max_mana = this->base_max_mana;
  this->damage = this->base_damage;
  this->agility = this->base_agility;
  this->intelligence = this->base_intelligence;
  this->strength = this->base_strength;
  this->name = "Sniper";
}
