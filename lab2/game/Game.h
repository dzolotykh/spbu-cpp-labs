#ifndef LAB2_GAME_H
#define LAB2_GAME_H

#include "../team/Team.h"

class Game {
 private:
  Team* t1;
  Team* t2;
  Hero* generate_hero();

 public:
  void start(int random_seed);
  ~Game();
};

#endif
