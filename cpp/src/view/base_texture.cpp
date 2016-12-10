#include <string>
#include <sstream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "base_texture.h"
#include "init_error.h"

BaseTexture::BaseTexture(SDL_Renderer* renderer) :
    renderer(renderer) {
	texture = NULL;
	texture_width = 0;
	texture_height = 0;
	pixels = NULL;
	texture_pitch = 0;
}

BaseTexture::BaseTexture(SDL_Renderer* renderer, std::string path) :
    renderer(renderer) {
	texture = NULL;
	texture_width = 0;
	texture_height = 0;
	pixels = NULL;
    texture_pitch = 0;
    load(path);
}

bool BaseTexture::load_text(TTF_Font* font, std::string text, SDL_Color text_color) {
	free();
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), text_color );
	if( surface == NULL ) {
		printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
	} else {
        texture = SDL_CreateTextureFromSurface( renderer, surface );
		if( texture == NULL ) {
			printf( "Unable to create texture from rendered text! SDL Error: %s\n", SDL_GetError() );
		} else {
			texture_width = surface->w;
			texture_height = surface->h;
		}
		SDL_FreeSurface( surface );
	}
	return texture != NULL;
}

void BaseTexture::free() {
	//Free texture if it exists
	if( texture != NULL ) {
		SDL_DestroyTexture(texture);
		texture = NULL;
		texture_width = 0;
		texture_height = 0;
		pixels = NULL;
		texture_pitch = 0;
	}
}

BaseTexture::~BaseTexture() {
	//Deallocate
	free();
}

bool BaseTexture::load(std::string path) throw(InitError){
	//Get rid of preexisting texture
	free();
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL ) {
        std::stringstream msg;
        msg << "Unable to load image " << path << "! SDL_image Error: " << IMG_GetError() <<"\n"; 
		throw InitError(msg.str());
    }
    SDL_Surface* formattedSurface = SDL_ConvertSurfaceFormat(loadedSurface, SDL_PIXELFORMAT_RGBA8888, 0);
    if ( formattedSurface == NULL) {
        std::stringstream  msg;
        msg << "Unable to convert loaded surface to display format! " << SDL_GetError()  << "\n";
		throw InitError(msg.str());
    }
    newTexture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING, 
        formattedSurface->w, 
        formattedSurface->h 
    );
    if ( newTexture == NULL) {
        std::stringstream  msg;
        msg << "Unable to create blank texture! SDL Error: " <<  SDL_GetError() << "\n";
        throw InitError(msg.str());
    }
    SDL_SetTextureBlendMode( newTexture, SDL_BLENDMODE_BLEND );
    SDL_LockTexture( newTexture, &formattedSurface->clip_rect, &pixels, &texture_pitch );
    memcpy(pixels, formattedSurface->pixels, formattedSurface->pitch * formattedSurface->h);
    //Get image dimensions
    texture_width = formattedSurface->w;
    texture_height = formattedSurface->h;

    //Get pixel data in editable format
    Uint32* new_pixels = (Uint32*)pixels;
    int pixelCount = ( texture_pitch / 4 ) * texture_height;

    //Map colors				
    Uint32 colorKey = SDL_MapRGB( formattedSurface->format, 0, 0xFF, 0xFF );
    Uint32 transparent = SDL_MapRGBA( formattedSurface->format, 0x00, 0xFF, 0xFF, 0x00 );

    //Color key pixels
    for( int i = 0; i < pixelCount; ++i )
    {
        if( new_pixels[ i ] == colorKey )
        {
            new_pixels[ i ] = transparent;
        }
    }

    //Unlock texture to update
    SDL_UnlockTexture( newTexture );
    pixels = NULL;
    //Get rid of old formatted surface
    SDL_FreeSurface( formattedSurface );
    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

	//Return success
	texture = newTexture;
	return texture != NULL;
}

bool BaseTexture::create_blank( int width, int height, SDL_TextureAccess access )
{
	texture = SDL_CreateTexture( renderer, SDL_PIXELFORMAT_RGBA8888, access, width, height );
    texture_width = width;
    texture_height = height;

	return texture != NULL;
}

void BaseTexture::set_color(Uint8 red, Uint8 green, Uint8 blue) {
	SDL_SetTextureColorMod(texture, red, green, blue);
}

void BaseTexture::set_blend_mode(SDL_BlendMode blending) {
	SDL_SetTextureBlendMode(texture, blending);
}
		
void BaseTexture::set_alpha(Uint8 alpha) {
	SDL_SetTextureAlphaMod(texture, alpha);
}

void BaseTexture::render(
    int x,
    int y, 
    SDL_Rect* clip, 
    double angle, 
    SDL_Point* center, 
    SDL_RendererFlip flip
) {
	SDL_Rect renderQuad = { x, y, texture_width, texture_height };
	if( clip != NULL ) {
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}
	SDL_RenderCopyEx(
        renderer,
        texture, 
        clip, 
        &renderQuad, 
        angle, 
        center,
        flip 
    );
}

void BaseTexture::set_as_render_target() {
	SDL_SetRenderTarget(renderer, texture);
}

bool BaseTexture::lock_texture() {
	if(pixels != NULL) {
		printf( "Texture is already locked!\n" );
		return false;
	} else if( SDL_LockTexture( texture, NULL, &pixels, &texture_pitch ) != 0 ) {
        printf( "Unable to lock texture! %s\n", SDL_GetError() );
        return false;
    }
    return true;
}

bool BaseTexture::unlock_texture() {
	if( pixels == NULL ) {
		printf( "Texture is not locked!\n" );
		return false;
	}
    SDL_UnlockTexture( texture );
    pixels = NULL;
    texture_pitch = 0;
    return true;
}

void* BaseTexture::get_pixels()
{
	return pixels;
}

void BaseTexture::copy_pixels( void* new_pixels ) {
	if( pixels != NULL ) {
		memcpy( pixels, new_pixels, texture_pitch * texture_height );
	}
}

Uint32 BaseTexture::get_pixel32( unsigned int x, unsigned int y ) {
    //Convert the pixels to 32 bit
    Uint32 *ret_pixels = (Uint32*)pixels;

    //Get the pixel requested
    return ret_pixels[ ( y * ( texture_pitch / 4 ) ) + x ];
}


