#include <SDL2/SDL.h>
#include <stdio.h>
#include <sstream>

#include "window.h"

Window::Window(int width, int height)
    : width(width), height(height) {
	window = NULL;
    renderer = NULL;
	fullscreen = false;
}

Window::~Window() {
    if( renderer != NULL) {
        SDL_DestroyRenderer(renderer);
    }
	if( window != NULL ) {
		SDL_DestroyWindow(window);
	}
	width = 0;
	height = 0;
}

bool Window::init_window() {
	window = SDL_CreateWindow(
        "Ridge",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
    );
	return window != NULL;
}

bool Window::init_renderer() {
    renderer = SDL_CreateRenderer(
        window,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );
    return renderer != NULL;
}

void Window::handle_event(SDL_Event* event){
    if(event->type == SDL_KEYDOWN && (event->key.keysym.mod & KMOD_ALT) && event->key.keysym.sym == SDLK_RETURN ) {
	    if(fullscreen) {
			SDL_SetWindowFullscreen(window, SDL_FALSE);
			fullscreen = false;
		} else {
			SDL_SetWindowFullscreen(window, SDL_TRUE);
			fullscreen = true;
		}
	}
}

