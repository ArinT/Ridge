#ifndef RIDGE_MODELS_GAME_STATE_H
#define RIDGE_MODELS_GAME_STATE_H
#include "map.h"
class GameState {
    public:
        Map* get_map() { return map; };
    private:
        Map* map; 
};
#endif
