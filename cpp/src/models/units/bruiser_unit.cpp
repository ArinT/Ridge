#include <string>

#include "constants.h"
#include "base_unit.h"
#include "bruiser_unit.h"
#include "utils.h"

using utils::randint;

BruiserUnit::BruiserUnit(int x, int y, Constants::Team team) :
    Unit(
        Constants::bruiser_movement,
        randint(Constants::bruiser_min_hp, Constants::bruiser_max_hp),
        randint(Constants::bruiser_min_strength, Constants::bruiser_max_strength),
        randint(Constants::bruiser_min_finesse, Constants::bruiser_max_finesse),
        randint(Constants::bruiser_min_wit, Constants::bruiser_max_wit),
        randint(Constants::bruiser_min_style, Constants::bruiser_max_style),
        x,
        y,
        team
    ) { }
