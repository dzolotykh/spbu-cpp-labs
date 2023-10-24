//
// Created by Dmitriy Zolotykh on 24.10.2023.
//

#include "FractionCreep.h"

FractionCreep::FractionCreep(bool _is_dire, int creep_type) {
    this->is_dire = _is_dire;
    if (creep_type == 1) {
        this->health = this->max_health = 50;
        this->damage = 100;
    } else if (creep_type == 2) {
        this->health = this->max_health = 150;
        this->damage = 50;
    } else {
        this->health = this->max_health = 200;
        this->damage = 100;
    }
}
