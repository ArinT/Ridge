#ifndef RIDGE_MODELS_GAME_STATE_H
#define RIDGE_MODELS_GAME_STATE_H
#include "map.h"
#include "cursor.h"
#include "texture_manager.h"
#include "info_pane.h"

class GameState {
    public:
        GameState();
        ~GameState();
        void draw(TextureManager* texture_manager);
        void set_up_default();
        bool confirm();
        bool cancel();
        bool cursor_up();
        bool cursor_down();
        bool cursor_left();
        bool cursor_right();
        Map* get_map() { return map; };
        Cursor* get_cursor() { return cursor; };
    private:
        Map* map;
        Cursor* cursor;
        InfoPane* info_pane; 
};
#endif
