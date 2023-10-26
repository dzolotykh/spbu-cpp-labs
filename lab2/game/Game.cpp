#include "Game.h"
#include "random"
#include "../entity/hero/Pudge.h"
#include "../entity/hero/Sniper.h"
#include "../entity/hero/Axe.h"
#include "../entity/hero/Dazzle.h"
#include "../entity/hero/Puck.h"
#include "../entity/hero/Alchemist.h"

void Game::start(int random_seed) {
    srand(random_seed);
    this->t1 = new Team(true, generate_hero(), generate_hero(), generate_hero(), 5);
    this->t2 = new Team(false, generate_hero(), generate_hero(), generate_hero(), 5);
    this->t1->print_team();
    this->t2->print_team();
    std::cout << "*********************" << std::endl;
    std::cout << (rand() % 2 ? "dire" : "radiant") << " wins" << std::endl;
}

Hero *Game::generate_hero() {
    int hero_id = rand() % 6;
    switch (hero_id) {
        case 0:
            return new Pudge();
            break;
        case 1:
            return new Sniper();
            break;
        case 2:
            return new Axe();
            break;
        case 3:
            return new Dazzle();
            break;
        case 4:
            return new Puck();
            break;
        default:
            return new Alchemist();
            break;
    }
}
