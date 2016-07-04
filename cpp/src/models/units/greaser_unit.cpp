#include <string>

#include "constants.h"
#include "base_unit.h"
#include "greaser_unit.h"
#include "utils.h"

using utils::randint;

GreaserUnit::GreaserUnit(int x, int y, Constants::Team team) :
    Unit(
        Constants::greaser_movement,
        randint(Constants::greaser_min_hp, Constants::greaser_max_hp),
        randint(Constants::greaser_min_strength, Constants::greaser_max_strength),
        randint(Constants::greaser_min_finesse, Constants::greaser_max_finesse),
        randint(Constants::greaser_min_wit, Constants::greaser_max_wit),
        randint(Constants::greaser_min_style, Constants::greaser_max_style),
        x,
        y,
        team
    ) { }
