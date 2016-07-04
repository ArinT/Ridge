#include <string>

#include "constants.h"
#include "base_unit.h"

class GreaserUnit : public Unit {
    public:
        GreaserUnit(int x, int y, Constants::Team team);
};
