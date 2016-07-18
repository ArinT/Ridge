#ifndef RIDGE_SRC_GAME_MODEL_VIEW_H
#define RIDGE_SRC_GAME_MODEL_VIEW_H
#include "game_state.h"
#include "texture_manager.h"
class GameModelView {
    public:
        GameModelView();
        ~GameModelView();
        GameState* get_state() { return game_state; };
    private:
        GameState* game_state;
        TextureManager* texture_manager;
};
#endif
