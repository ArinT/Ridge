#ifndef RIDGE_MODELS_INFOPANE_H
#define RIDGE_MODELS_INFOPANE_H
#include "texture_manager.h"
#include "base_unit.h"
#include "base_tile.h"

class GameState;

class InfoPane{
    public:
        InfoPane(GameState*& game_state);
        void draw(TextureManager* texture_manager);
        void draw_rect(TextureManager* texture_manager, int x, int y);
        void draw_unit_details(TextureManager* texture_manager, Unit* unit, int x, int y);
        void draw_tile_details(TextureManager* texture_manager, Tile* tile, int x, int y);
    private:
        GameState* game_state;
};

#endif
