#include "game_state.h"
#include "texture_manager.h"
#include "info_pane.h"
#include "base_unit.h"
#include "base_tile.h"
#include <SDL2/SDL.h>

InfoPane::InfoPane(GameState*& game_state) :
    game_state(game_state) { }

void InfoPane::draw(TextureManager* texture_manager) {
    Cursor* cursor = game_state->get_cursor();
    int cursor_x = cursor->get_x();
    int cursor_y = cursor->get_y();
    Map* map = game_state->get_map();
    int cols = map->get_columns();
    int rows = map->get_rows();
    int x = cursor_x > cols/2 ? 0 : cols - 3;
    int y = cursor_y > rows/2 ? 0 : rows - 3;
    draw_rect(texture_manager, x, y);
    draw_unit_details(texture_manager, map->unit_at(cursor_x, cursor_y), x, y);
    draw_tile_details(texture_manager, map->get_tile(cursor_x, cursor_y), x, y);
}

void InfoPane::draw_unit_details(TextureManager* texture_manager, Unit* unit, int x, int y) {
    if (unit) { 
        unit->draw(texture_manager, x, y);
    }
}

void InfoPane::draw_tile_details(TextureManager* texture_manager, Tile* tile, int x, int y) {
    if (tile) { 
        tile->draw(texture_manager, x, y+2);
    }
}

void InfoPane::draw_rect(TextureManager* texture_manager, int x, int y) {
    SDL_Renderer* renderer = texture_manager->get_renderer();
    SDL_Rect fillRect = { x*60, y*60, 3*60, 3*60 };
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0x9B, 0xFF );    
    SDL_RenderFillRect(renderer, &fillRect);
}
