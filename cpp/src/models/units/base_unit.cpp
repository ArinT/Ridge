#include "base_unit.h"
#include "constants.h"

Unit::Unit(
    int movement_range, 
    int max_hp, 
    int strength,
    int finesse,
    int wit, 
    int style,
    int x,
    int y,
    Constants::Team team
) : movement_range(movement_range),
    max_hp(max_hp),
    strength(strength),
    finesse(finesse),
    wit(wit),
    style(style),
    x(x),
    y(y),
    team(team)
{ 
    hp = max_hp;
}
Unit::~Unit() {
}    
