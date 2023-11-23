#ifndef LAB2_ITEM_H
#define LAB2_ITEM_H

#include <memory>


class Hero;

class Item {
 public:
  virtual void apply(std::shared_ptr<Hero> &h) = 0;
};

#endif
