#ifndef LAB2_TANGO_H
#define LAB2_TANGO_H

#include "Item.h"
#include <vector>
#include <thread>

class Tango : public Item {
private:
    std::vector<std::thread*> available_threads;
 public:
  void apply(Hero *h) override;
  ~Tango();
};

#endif
