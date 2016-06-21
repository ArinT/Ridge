#include <string>

#include "base_tile.h"
#include "base_unit.h"

Tile::Tile(
    int defense, 
    std::string img_path, 
    bool accessible, 
    int x, 
    int y
) : defense(defense),
    img_path(img_path),
    accessible(accessible),
    x(x),
    y(y)
{
    unit = NULL;
    occupied = false;
    attack_marked = false;
    marked = false; 
}
Tile::~Tile() {
    unit = NULL;
}
bool Tile::remove_unit() {
    unit = NULL;
    occupied = false;
    return true;
}

bool Tile::add_unit(Unit *unit) {
    this->unit = unit;
    occupied = true;
    return true;
}
