#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "init_error.h"

#ifndef RIDGE_VIEW_TEXTURE_H
#define RIDGE_VIEW_TEXTURE_H
class BaseTexture {
    public:
        BaseTexture(SDL_Renderer* renderer);
        BaseTexture(SDL_Renderer* renderer, std::string);
        ~BaseTexture();
        bool load(std::string path) throw(InitError);
        bool load_text(TTF_Font* font, std::string text, SDL_Color text_color);
        void free();
        bool create_blank(int width, int height, SDL_TextureAccess access);
        void set_color(Uint8 red, Uint8 green, Uint8 blue);
        void set_blend_mode(SDL_BlendMode blending);
        void set_alpha(Uint8 alpha);
        //Renders texture at given point
        void render(
            int x,
            int y,
            SDL_Rect* clip = NULL,
            double angle = 0.0,
            SDL_Point* center = NULL,
            SDL_RendererFlip flip = SDL_FLIP_NONE
        );
	    //Set self as render target
	    void set_as_render_target();
        //Gets image dimensions
        int get_width() { return texture_width; };
        int get_height() { return texture_height; };
        //Pixel manipulators
        bool lock_texture();
        bool unlock_texture();
        void* get_pixels();
        void copy_pixels( void* new_pixels );
        int get_pitch() { return texture_pitch; };
        Uint32 get_pixel32( unsigned int x, unsigned int y );

	private:
		//The actual hardware texture
		SDL_Texture* texture;
		void* pixels;
		int texture_pitch;
        SDL_Renderer* renderer;

		//Image dimensions
		int texture_width;
		int texture_height;
};
#endif
