#ifndef RIDGE_MODELS_CURSOR_H
#define RIDGE_MODELS_CURSOR_H
#include <tuple>
#include <string>

#include "texture_manager.h"
#include "base_texture.h"
#include "constants.h"

class Cursor {
    public:
        Cursor(int start_x, int start_y, int width, int height);
        ~Cursor();
        std::tuple<int, int> get_position();
        void draw(TextureManager* texture_manager);
        bool move_up();
        bool move_down();
        bool move_left();
        bool move_right();
    private:
        int x;
        int y;
        int width;
        int height;
        BaseTexture* texture;
        std::string img_path = Constants::GameStateImg::cursor;
};
#endif
