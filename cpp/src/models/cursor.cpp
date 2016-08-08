#include <tuple>

#include "cursor.h"

Cursor::Cursor(int start_x, int start_y, int width, int height) :
    x(start_x),
    y(start_y),
    width(width),
    height(height) {
    texture = NULL;
}

Cursor::~Cursor() {
    texture = NULL;
}

std::tuple<int, int> Cursor::get_position() {
    return std::tuple<int,int>(x,y);
}

bool Cursor::move_up() {
    if ( y - 1 >= 0) {
        y--;
        return true;
    };
    return false;
}

bool Cursor::move_down() {
    if ( y + 1 < height) {
        y++;
        return true;
    };
    return false;
}

bool Cursor::move_left() {
    if ( x - 1 >= 0) {
        x--;
        return true;
    };
    return false;
}

bool Cursor::move_right() {
    if ( x + 1 < width) {
        x++;
        return true;
    };
    return false;
}

void Cursor::draw(TextureManager* texture_manager) {
    if (texture != NULL) {
        texture->render(x*60, y*60);
    } else {
        texture = texture_manager->fetch_texture(img_path);
        texture->render(x*60, y*60);
    }
} 
