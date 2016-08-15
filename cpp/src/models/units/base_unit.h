#ifndef RIDGE_UNITS_BASE_H
#define RIDGE_UNITS_BASE_H

#include <string>
#include "constants.h"
#include "base_texture.h"
#include "texture_manager.h"

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
            int y,
            Constants::Team team,
            std::string img_path 
        );
        ~Unit();
        int get_movement_range() { return movement_range; };
        int get_max_hp() { return max_hp; };
        int get_hp() { return hp; };
        int get_strength() { return strength; };
        int get_finesse() { return finesse; };
        int get_wit() { return wit; };
        int get_style() { return style; };
        int get_x() { return x; };
        int get_y() { return y; };
        bool move(int dest_x, int dest_y);
        Constants::Team get_team() { return team; };
        void draw(TextureManager* texture_manager);
    protected:
        int movement_range;
        BaseTexture* texture;
        int max_hp;
        int strength;
        int finesse;
        int wit;
        int style;
        int x;
        int y;
        int hp;
        Constants::Team team;
        std::string img_path;
};

#endif
