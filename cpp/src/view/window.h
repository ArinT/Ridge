#ifndef RIDGE_VIEW_WINDOW_H
#define RIDGE_VIEW_WINDOW_H
#include <SDL2/SDL.h>
class Window {
    public:
        Window(int width, int height);
        ~Window();
        bool init_window();
        bool init_renderer();
        void handle_event(SDL_Event* event);
        int get_width() { return width; };
        int get_height() { return height; };
        bool has_mouse_focus() { return mouse_focus; };
        bool has_keyboard_focus() { return keyboard_focus; };
        bool is_minimized() { return minimized; };
        bool is_fullscreen() { return fullscreen; };
        SDL_Window* window;
        SDL_Renderer* renderer;
    private:
        int width;
        int height;
        bool mouse_focus;
        bool keyboard_focus;
        bool fullscreen;
        bool minimized;
};
#endif
