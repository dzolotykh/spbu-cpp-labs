#include "Hero.h"
#include <iostream>

void Hero::add_item(Item *i) {
    this->inventory->add_item(i);
}

void Hero::use_item(int item_id) {
    Item* item = this->inventory->operator[](item_id);
    this->add_health(item->get_add_health());
    this->add_agility(item->get_add_agility());
    this->add_strength(item->get_add_strength());
    this->add_intelligence(item->get_add_intelligence());
    this->add_mana(item->get_add_mana());
}

void Hero::add_strength(int _add) {
    this->strength = std::max(0, this->strength + _add);
}

void Hero::add_intelligence(int _add) {
    this->strength = std::max(0, this->intelligence + _add);
}

void Hero::add_agility(int _add) {
    this->strength = std::max(0, this->agility + _add);
}

Hero::Hero() {
    this->inventory = new Inventory();
}

Hero::Hero(int _max_health, int _max_mana, int _damage) : Entity(_max_health, _max_mana, _damage) {}

Hero::~Hero() {
    delete this->inventory;
}

std::string Hero::get_name() const {
    return this->name;
}

std::string Hero::get_stats() const {
    return "(hp = " + std::to_string(get_health()) + ", damage = " + std::to_string(get_damage()) + ")";
}
