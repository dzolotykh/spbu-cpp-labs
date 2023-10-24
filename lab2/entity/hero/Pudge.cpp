#include "Pudge.h"

Pudge::Pudge() {
    this->health = this->max_health = this->base_max_health;
    this->mana = this->max_mana = this->base_max_mana;
    this->damage = this->base_damage;
    this->agility = this->base_agility;
    this->intelligence = this->base_intelligence;
    this->strength = this->base_strength;
}

void Pudge::apply_skill(int skill_num, Entity *h) {
    switch (skill_num) {
        case 1:
            h->add_health(this->hook_damage);
            break;
        case 2:
            this->add_health(100);
        default:
            throw std::runtime_error("Pudge doesn't have skill with number " + std::to_string(skill_num));
    }
}