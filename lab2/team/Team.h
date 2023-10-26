#ifndef LAB2_TEAM_H
#define LAB2_TEAM_H


#include "../entity/hero/Hero.h"
#include "../entity/creep/FractionCreep.h"

class Team {
    Hero** heroes;
    FractionCreep** creeps;
    bool is_dire;
    int num_creeps;

    ~Team();

public:
    Team(bool _is_dire, Hero* h1, Hero* h2, Hero* h3, int num_creeps);
    void print_team();
};


#endif
