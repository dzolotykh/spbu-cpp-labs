#include "Game.h"

#include "../entity/hero/Alchemist.h"
#include "../entity/hero/Axe.h"
#include "../entity/hero/Dazzle.h"
#include "random"

void Game::start(int random_seed) {
    srand(random_seed);
    t1 = new Team(true);
    t1->push_hero(generate_hero());
    t1->push_hero(generate_hero());
    t2 = new Team(false);
    t2->push_hero(generate_hero());
    t2->push_hero(generate_hero());

    t1->print_team();
    t2->print_team();
    std::cout << "*********************" << std::endl;
    std::cout << (rand() % 2 ? "dire" : "radiant") << " wins" << std::endl;
}

void Game::start(HeroesIds &ids, int random_seed) {
    srand(random_seed);
    t1 = new Team(true);
    t1->push_hero(generate_hero(ids.dire_first));
    t1->push_hero(generate_hero(ids.dire_second));

    t2 = new Team(false);
    t2->push_hero(generate_hero(ids.radiant_first));
    t2->push_hero(generate_hero(ids.radiant_second));

    t1->print_team();
    t2->print_team();

    std::cout << "*********************" << std::endl;
    std::cout << (rand() % 2 ? "dire" : "radiant") << " wins" << std::endl;
}

Hero *Game::generate_hero() {
    int hero_id = rand() % 3;
    switch (hero_id) {
        case 0:
            return new Axe();
            break;
        case 1:
            return new Alchemist();
            break;
        case 2:
            return new Dazzle();
            break;
    }
}

Hero *Game::generate_hero(int hero_id) {
    switch (hero_id) {
        case 0:
            return new Axe();
        case 1:
            return new Alchemist();
        case 2:
            return new Dazzle();
    }
}

Game::~Game() {
    delete this->t1;
    delete this->t2;
}
