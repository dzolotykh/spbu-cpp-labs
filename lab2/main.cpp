#include <iostream>
#include <vector>
#include <cassert>
#include "thread"
#include "entity/hero/Hero.h"
#include "entity/hero/Axe.h"
#include "entity/hero/Alchemist.h"
#include "entity/hero/Dazzle.h"
#include "items/FaerieFire.h"
#include "items/Tango.h"
#include "game/Game.h"


// проверяем, убьет ли акс при здоровье меньше 20%
void test1() {
    Hero *h1 = new Axe();
    Hero *h2 = new Axe();
    h2->set_health(h2->get_max_health() / 100 * 15);
    h1->ability(h2);
    assert(h2->get_health() == 0);
    std::cout << "Тест #1 пройден" << std::endl;
}

// проверяем, убьет ли акс при здоровье больше 20%
void test2() {
    Hero *h1 = new Axe();
    Hero *h2 = new Axe();
    h2->set_health(h2->get_max_health());
    h1->ability(h2);
    assert(h2->get_health() != 0);
    std::cout << "Тест #2 пройден" << std::endl;
}

// проверяем способность алхимика добавлять себе здоровье параллельно
void test3(bool show_logs) {
    Hero *h1 = new Alchemist();
    h1->set_health(20);
    h1->ability(nullptr);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if (show_logs) std::cout << h1->get_health() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if (show_logs) std::cout << h1->get_health() << std::endl;
    assert(h1->get_health() != 20);
    std::cout << "Тест #3 пройден" << std::endl;
}

// проверяем хил дазла
void test4() {
    Hero *h = new Dazzle();
    h->set_health(28);
    h->ability(h);
    assert(h->get_health() == 228);
    std::cout << "Тест #4 пройден" << std::endl;
}

// проверям первый предмет, добавляет +150 к хп
void test5() {
    Hero *h = new Axe();
    h->add_item(new FaerieFire());
    h->set_health(20);
    h->use_item(0);
    assert(h->get_health() == 170);
    std::cout << "Тест #5 пройден" << std::endl;
}

// проверям второй предмет, добавляет +150 к хп за 2 секунды
void test6() {
    Hero *h = new Axe();
    h->add_item(new Tango());
    h->set_health(20);
    h->use_item(0);
    std::this_thread::sleep_for(std::chrono::milliseconds (1500));
    assert(h->get_health() != 20);
    std::cout << "Тест #6 пройден" << std::endl;
}

void test7() {
    Game *g = new Game();
    g->start(123);
    delete g;
}

void test8() {
    Game *g = new Game();
    HeroesIds ids(0, 1, 2, 1);
    g->start(ids, 228);
    delete g;
}


int main() {
    test1();
    test2();
    test3(false);
    test4();
    test5();
    test6();
    test7();
    test8();
}
