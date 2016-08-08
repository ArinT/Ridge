#ifndef RIDGE_MODELS_GAME_STATE_H
#define RIDGE_MODELS_GAME_STATE_H
#include "map.h"
#include "cursor.h"
#include "texture_manager.h"

class GameState {
    public:
        GameState();
        ~GameState();
        void draw(TextureManager* texture_manager);
        void set_up_default();
        Map* get_map() { return map; };
        Cursor* get_cursor() { return cursor; };
    private:
        Map* map;
        Cursor* cursor; 
};
#endif
