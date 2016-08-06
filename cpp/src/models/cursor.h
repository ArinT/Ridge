#ifndef RIDGE_MODELS_CURSOR_H
#define RIDGE_MODELS_CURSOR_H
#include <tuple>
#include <string>

#include "texture_manager.h"
#include "base_texture.h"
#include "constants.h"

class Cursor {
    public:
        Cursor();
        ~Cursor();
        std::tuple<int, int> get_position();
        void draw(TextureManager* texture_manager);
    private:
        int x;
        int y;
        BaseTexture* texture;
        std::string img_path = Constants::GameStateImg::cursor;
};
#endif
