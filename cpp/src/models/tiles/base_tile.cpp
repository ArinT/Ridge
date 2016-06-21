#include <string>

#include "base_tile.h"
#include "base_unit.h"


Tile::Tile() {
    defense = 0;
    img_path = "";
    is_accessible = false;
    x = 0;
    y = 0;
    unit = NULL;
    marked = false;
    attack_marked = false;
    is_occupied = false; 
}

Tile::Tile(
    int defense, 
    std::string img_path, 
    bool is_accessible, 
    int x, 
    int y
) {
    defense = defense;
    img_path = img_path;
    is_accessible = is_accessible;
    x = x;
    y = y;
    unit = NULL;
    is_occupied = false;
    attack_marked = false;
    marked = false;
}
bool Tile::remove_unit() {
    unit = NULL;
    is_occupied = false;
    return true;
}

bool Tile::add_unit(Unit *unit) {
    unit = unit;
    is_occupied = true;
    return true;
}
