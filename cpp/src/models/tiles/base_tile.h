#ifndef RIDGE_TILES_BASE_H
#define RIDGE_TILES_BASE_H
#include <string>

#include "base_unit.h"

class Tile {
    public:
        Tile();
        Tile(
            int defense, 
            std::string img_path, 
            bool is_accessible, 
            int x, 
            int y
        );
        ~Tile();
        bool remove_unit();
        bool add_unit(Unit *unit);
    protected:
        int defense;
        std::string img_path;
        bool is_accessible;
        int x;
        int y;
        Unit *unit;
        bool marked;
        bool attack_marked;
        bool is_occupied;
};
#endif
