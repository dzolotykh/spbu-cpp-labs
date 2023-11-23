#include "Tango.h"
#include "../entity/hero/Hero.h"
#include <thread>
#include <chrono>

void Tango::apply(std::shared_ptr<Hero> &h) {
        auto t = new std::thread([&h]() {
        h->add_health(50);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (h->is_alive())
            h->add_health(50);
        else return;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (h->is_alive())
            h->add_health(50);
        });
        available_threads.push_back(t);
}

Tango::~Tango() {
    for (auto &i : available_threads) {
        i->join();
        delete i;
    }
}
