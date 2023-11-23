#include "Team.h"

Team::Team(bool _is_dire) {
    heroes[0] = nullptr;
    heroes[1] = nullptr;

    is_dire = _is_dire;
    heroes_cnt = 0;
}

void Team::print_team() {
    std::cout << "Team " << (this->is_dire ? "dire." : "radiant.") << std::endl;
    for (int i = 0; i < 2; i++) {
        auto h = this->heroes[i];
        std::cout << "Hero " << i + 1 << ": " << h->get_name();
        std::cout << " (hp = " << h->get_health()
                  << ", damage = " << h->get_damage() << ")" << std::endl;
    }
}

void Team::push_hero(Hero *h) {
    heroes[heroes_cnt] = h;
    heroes_cnt++;
}

Team::~Team() {
    delete heroes[0];
    delete heroes[1];
}
