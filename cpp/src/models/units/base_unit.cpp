#include <string>

#include "base_unit.h"
#include "constants.h"
#include "texture_manager.h"

Unit::Unit(
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
) : movement_range(movement_range),
    max_hp(max_hp),
    strength(strength),
    finesse(finesse),
    wit(wit),
    style(style),
    x(x),
    y(y),
    team(team),
    img_path(img_path)
{ 
    hp = max_hp;
    texture = NULL;
}

Unit::~Unit() {
    texture = NULL;
}

void Unit::draw(TextureManager* texture_manager, int xloc, int yloc) {
    if (texture != NULL) {
        texture->render(xloc*60, yloc*60);
    } else {
        texture = texture_manager->fetch_texture(img_path);
        texture->render(xloc*60, yloc*60);
    }
}

void Unit::draw(TextureManager* texture_manager) {
    draw(texture_manager, x, y);
}

bool Unit::move(int dest_x, int dest_y) {
    x = dest_x;
    y = dest_y;
}
