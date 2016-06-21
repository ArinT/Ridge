#ifndef RIDGE_UNITS_BASE_H
#define RIDGE_UNITS_BASE_H

#include <string>

class Unit {
    public:
        Unit(
            int movement_range, 
            int max_hp, 
            int strength,
            int finesse,
            int wit, 
            int style,
            int x,
            int y
        );
        ~Unit();
        int get_movement_range() { return movement_range; }
        int get_max_hp() { return max_hp; }
        int get_hp() { return hp; }
        int get_strength() { return strength; }
        int get_finesse() { return finesse; }
        int get_wit() { return wit; }
        int get_style() { return style; }
        int get_x() { return x; }
        int get_y() { return y; }
    protected:
        int movement_range;
        int max_hp;
        int strength;
        int finesse;
        int wit;
        int style;
        int x;
        int y;
        int hp;
};

#endif
