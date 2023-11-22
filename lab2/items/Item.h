#ifndef LAB2_ITEM_H
#define LAB2_ITEM_H

class Hero;

class Item {
 public:
  virtual void apply(Hero *h) = 0;
};

#endif
