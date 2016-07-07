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
    attack_marked = false;
    marked = false; 
}

Tile::~Tile() {
    unit = NULL;
}

bool Tile::remove_unit() {
    unit = NULL;
    return true;
}

bool Tile::add_unit(Unit *unit) {
    this->unit = unit;
    return true;
}

bool Tile::is_occupied() {
    return unit != NULL;
}

int Tile::manhattan_distance(Tile* dest) {
    return abs(this->get_x() - dest->get_x()) + abs(this->get_y() - dest->get_y());
}
