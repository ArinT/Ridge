#include <string>

#include "constants.h"
#include "base_unit.h"
#include "bruiser_unit.h"
#include "utils.h"

using utils::randint;

BruiserUnit::BruiserUnit(int x, int y, Constants::Team team) :
    Unit(
        Constants::BruiserUnit::movement_range,
        randint(Constants::BruiserUnit::min_hp, Constants::BruiserUnit::max_hp),
        randint(Constants::BruiserUnit::min_strength, Constants::BruiserUnit::max_strength),
        randint(Constants::BruiserUnit::min_finesse, Constants::BruiserUnit::max_finesse),
        randint(Constants::BruiserUnit::min_wit, Constants::BruiserUnit::max_wit),
        randint(Constants::BruiserUnit::min_style, Constants::BruiserUnit::max_style),
        x,
        y,
        team,
        team == Constants::Team::Jets ? Constants::BruiserUnit::sharks_img : Constants::BruiserUnit::jets_img
    ) { }
