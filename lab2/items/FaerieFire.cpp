#include "FaerieFire.h"
#include "../entity/hero/Hero.h"

void FaerieFire::apply(Hero *h) {
    h->add_health(150);
}
