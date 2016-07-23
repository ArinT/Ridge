#ifndef RIDGE_MODELS_GAME_STATE_H
#define RIDGE_MODELS_GAME_STATE_H
#include "map.h"
#include "texture_manager.h"

class GameState {
    public:
        GameState();
        ~GameState();
        Map* get_map() { return map; };
        bool draw(TextureManager* texture_manager);
        void set_up_default(); 
    private:
        Map* map; 
};
#endif
