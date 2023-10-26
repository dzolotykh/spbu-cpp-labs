#include "Team.h"

#include "random"

Team::Team(bool _is_dire, Hero *h1, Hero *h2, Hero *h3, int _num_creeps) {
  this->heroes = new Hero *[3];
  this->heroes[0] = h1;
  this->heroes[1] = h2;
  this->heroes[2] = h3;
  this->is_dire = _is_dire;
  this->num_creeps = _num_creeps;
  this->creeps = new FractionCreep *[num_creeps];
  for (int i = 0; i < _num_creeps; i++) {
    this->creeps[i] = new FractionCreep(_is_dire, rand() % 2 + 1);
  }
}

Team::~Team() {
  for (int i = 0; i < 3; i++) {
    delete this->heroes[i];
  }
  for (int i = 0; i < this->num_creeps; i++) {
    delete this->creeps[i];
  }
  delete[] this->heroes;
  delete[] this->creeps;
}

void Team::print_team() {
  std::cout << "Team " << (this->is_dire ? "dire." : "radiant.") << std::endl;
  for (int i = 0; i < 3; i++) {
    auto h = this->heroes[i];
    std::cout << "Hero " << i + 1 << ": " << h->get_name();
    std::cout << " (hp = " << h->get_health()
              << ", damage = " << h->get_damage() << ")" << std::endl;
  }
}
