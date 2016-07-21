#ifndef RIDGE_SRC_RIDGEMVC_H
#define RIDGE_SRC_RIDGEMVC_H
#include "game_state.h"
#include "texture_manager.h"
#include "sdl.h"
#include "controller.h"

class RidgeMVC {
    public:
        RidgeMVC(int width, int height);
        ~RidgeMVC();
        GameState* get_state() { return game_state; };
        bool handle_events();
        void update_view();
    private:
        GameState* game_state;
        SDLWrapper* sdl;
        Controller* controller;
        TextureManager* texture_manager;
};
#endif
