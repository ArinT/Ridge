#include <string>

#include "constants.h"
#include "base_unit.h"
#include "greaser_unit.h"
#include "utils.h"

using utils::randint;

GreaserUnit::GreaserUnit(int x, int y, Constants::Team team) :
    Unit(
        Constants::GreaserUnit::movement_range,
        randint(Constants::GreaserUnit::min_hp, Constants::GreaserUnit::max_hp),
        randint(Constants::GreaserUnit::min_strength, Constants::GreaserUnit::max_strength),
        randint(Constants::GreaserUnit::min_finesse, Constants::GreaserUnit::max_finesse),
        randint(Constants::GreaserUnit::min_wit, Constants::GreaserUnit::max_wit),
        randint(Constants::GreaserUnit::min_style, Constants::GreaserUnit::max_style),
        x,
        y,
        team
    ) { }
