#ifndef LAB2_FRACTIONCREEP_H
#define LAB2_FRACTIONCREEP_H

#include "Creep.h"


class FractionCreep: public Creep {
private:
    bool is_dire;

public:
    FractionCreep(bool _is_dire, int creep_type);
};


#endif
