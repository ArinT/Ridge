#include <SDL2/SDL.h>
#include <stdio.h>
#include <sstream>

#include "window.h"

Window::Window(int width, int height)
    : width(width), height(height) {
	window = NULL;
    renderer = NULL;
	mouse_focus = false;
	keyboard_focus = false;
	fullscreen = false;
	minimized = false;
}

Window::~Window() {
    if( renderer != NULL) {
        SDL_DestroyRenderer(renderer);
    }
	if( window != NULL ) {
		SDL_DestroyWindow(window);
	}
	mouse_focus = false;
	keyboard_focus = false;
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
	if( window != NULL ) {
		mouse_focus = true;
		keyboard_focus = true;
	}
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
    bool update = false;
	if( event->type == SDL_WINDOWEVENT ) {
		switch( event->window.event ) {
			case SDL_WINDOWEVENT_SIZE_CHANGED:
			width = event->window.data1;
			height = event->window.data2;
			SDL_RenderPresent(renderer);
            update = true;
			break;

			case SDL_WINDOWEVENT_EXPOSED:
			SDL_RenderPresent(renderer);
			break;

			case SDL_WINDOWEVENT_ENTER:
			mouse_focus = true;
			break;
			
			case SDL_WINDOWEVENT_LEAVE:
            mouse_focus = false;
			break;

			case SDL_WINDOWEVENT_FOCUS_GAINED:
            keyboard_focus = true;
			break;

			case SDL_WINDOWEVENT_FOCUS_LOST:
            keyboard_focus = false;
			break;

			case SDL_WINDOWEVENT_MINIMIZED:
            minimized = true;
            break;

			case SDL_WINDOWEVENT_MAXIMIZED:
			minimized = false;
            break;
			
			case SDL_WINDOWEVENT_RESTORED:
			minimized = false;
            break;
		}
	} else if(
        event->type == SDL_KEYDOWN && 
        (event->key.keysym.mod & KMOD_ALT) && 
        event->key.keysym.sym == SDLK_RETURN ) {
		if(fullscreen) {
			SDL_SetWindowFullscreen(window, SDL_FALSE);
			fullscreen = false;
		} else {
			SDL_SetWindowFullscreen(window, SDL_TRUE);
			fullscreen = true;
			minimized = false;
		}
	}
    if (update) {
        std::stringstream caption;
        caption << "Ridge " << width << "x" << height;
        SDL_SetWindowTitle( window, caption.str().c_str() );
    }
}

