#include <string>

#include "base_tile.h"
#include "base_unit.h"

#include "texture_manager.h"
#include "base_texture.h"

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
    texture = NULL;
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

void Tile::draw(TextureManager* texture_manager) {
    if (texture != NULL) {
        texture->render(x*60, y*60);
    } else {
        texture = texture_manager->fetch_texture(img_path);
        texture->render(x*60, y*60);
    }
}
