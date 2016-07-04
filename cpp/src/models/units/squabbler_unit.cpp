#include <string>

#include "constants.h"
#include "base_unit.h"
#include "squabbler_unit.h"
#include "utils.h"

using utils::randint;

SquabblerUnit::SquabblerUnit(int x, int y, Constants::Team team) :
    Unit(
        Constants::squabbler_movement,
        randint(Constants::squabbler_min_hp, Constants::squabbler_max_hp),
        randint(Constants::squabbler_min_strength, Constants::squabbler_max_strength),
        randint(Constants::squabbler_min_finesse, Constants::squabbler_max_finesse),
        randint(Constants::squabbler_min_wit, Constants::squabbler_max_wit),
        randint(Constants::squabbler_min_style, Constants::squabbler_max_style),
        x,
        y,
        team
    ) { }
