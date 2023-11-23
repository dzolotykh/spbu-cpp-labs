#ifndef LAB2_TEAM_H
#define LAB2_TEAM_H

#include "../entity/hero/Hero.h"
#include <array>

class Team {
private:
    std::array<Hero*, 2> heroes;
    bool is_dire;
    size_t heroes_cnt;

public:
    Team(bool _is_dire);
    ~Team();
    void print_team();
    void push_hero(Hero *h);
};

#endif // LAB2_TEAM_H