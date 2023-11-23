#ifndef LAB2_GAME_H
#define LAB2_GAME_H

#include "../team/Team.h"

struct HeroesIds {
    int radiant_first;
    int radiant_second;
    int dire_first;
    int dire_second;

    HeroesIds(int _radiant_first, int _radiant_second, int _dire_first, int _dire_second) {
        radiant_first = _radiant_first;
        radiant_second = _radiant_second;
        dire_first = _dire_first;
        dire_second = _dire_second;
    }
};

class Game {
private:
    Team* t1;
    Team* t2;
    Hero* generate_hero();
    Hero* generate_hero(int hero_id);

public:
    void start(int random_seed);
    void start(HeroesIds &ids, int random_seed);
    ~Game();
};

#endif // LAB2_GAME_H