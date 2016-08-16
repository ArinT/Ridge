#ifndef RIDGE_MODELS_INFOPANE_H
#define RIDGE_MODELS_INFOPANE_H
#include "texture_manager.h"

class GameState;

class InfoPane{
    public:
        InfoPane(GameState*& game_state);
        void draw(TextureManager* texture_manager);
    private:
        GameState* game_state;
};

#endif
