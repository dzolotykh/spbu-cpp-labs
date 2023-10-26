#ifndef LAB2_CREEP_H
#define LAB2_CREEP_H

#include "../Entity.h"


class Creep: public Entity {
public:
    Creep(int _max_health, int _max_mana, int _damage);
    Creep();
};


#endif //LAB2_CREEP_H
