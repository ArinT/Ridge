#include <tuple>

#include "cursor.h"

Cursor::Cursor() {
    x = 0;
    y = 0;
    texture = NULL;
}

Cursor::~Cursor() {
    texture = NULL;
}

std::tuple<int, int> Cursor::get_position() {
    return std::tuple<int,int>(x,y);
}

void Cursor::draw(TextureManager* texture_manager) {
    if (texture != NULL) {
        texture->render(x*60, y*60);
    } else {
        texture = texture_manager->fetch_texture(img_path);
        texture->render(x*60, y*60);
    }
} 
