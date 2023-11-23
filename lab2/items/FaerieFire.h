#ifndef LAB2_FAERIEFIRE_H
#define LAB2_FAERIEFIRE_H

#include "Item.h"
#include <thread>
#include <vector>
#include <memory>

class FaerieFire : public Item {
public:
  void apply(std::shared_ptr<Hero> &h) override;
};

#endif
