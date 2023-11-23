#include "FaerieFire.h"
#include "../entity/hero/Hero.h"

void FaerieFire::apply(std::shared_ptr<Hero> &h) {
    h->add_health(150);
}
