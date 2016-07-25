#include <string>

#include "constants.h"
#include "base_unit.h"
#include "squabbler_unit.h"
#include "utils.h"

using utils::randint;

SquabblerUnit::SquabblerUnit(int x, int y, Constants::Team team) :
    Unit(
        Constants::SquabblerUnit::movement_range,
        randint(Constants::SquabblerUnit::min_hp, Constants::SquabblerUnit::max_hp),
        randint(Constants::SquabblerUnit::min_strength, Constants::SquabblerUnit::max_strength),
        randint(Constants::SquabblerUnit::min_finesse, Constants::SquabblerUnit::max_finesse),
        randint(Constants::SquabblerUnit::min_wit, Constants::SquabblerUnit::max_wit),
        randint(Constants::SquabblerUnit::min_style, Constants::SquabblerUnit::max_style),
        x,
        y,
        team,
        team == Constants::Team::Jets ? Constants::SquabblerUnit::sharks_img : Constants::SquabblerUnit::jets_img
    ) { }
