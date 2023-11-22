#include "Entity.h"

#include <iostream>

void Entity::set_health(int _health) {
  this->health = std::max(0, std::min(_health, this->max_health));
}

void Entity::add_health(int _health) {
  this->health =
      std::max(0, std::min(this->health + _health, this->max_health));
}

void Entity::set_mana(int _mana) {
  this->mana = std::max(0, std::min(_mana, this->mana));
}

void Entity::add_mana(int _mana) {
  this->mana = std::max(0, std::min(this->mana + _mana, this->max_mana));
}

Entity::Entity(int _max_health, int _max_mana, int _damage)
    : max_health(_max_health),
      max_mana(_max_mana),
      damage(_damage),
      health(_max_health),
      mana(_max_mana) {}

Entity::Entity() = default;

void Entity::attack(Entity *other) const { other->add_health(-this->damage); }

bool Entity::is_alive() const { return this->health != 0; }

int Entity::get_health() const { return health; }

int Entity::get_mana() const { return mana; }

int Entity::get_damage() const { return damage; }

int Entity::get_max_health() const {
    return max_health;
}

int Entity::get_max_mana() const {
    return max_mana;
}
