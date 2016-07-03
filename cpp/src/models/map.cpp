#include <vector>
#include <list>

#include "constants.h"
#include "map.h"
#include "base_tile.h"
#include "base_unit.h"

using std::vector;
using std::list;

Map::Map(int col, int row) {
    columns = col;
    rows = row;
    current_turn = Constants::Team::Sharks;
    initialize_tile_matrix();
}

Map::~Map() {
    destroy_unit_list();
    destroy_tile_matrix();
}

void Map::destroy_unit_list() {
    typedef list<Unit*>::const_iterator iterator;
    for (iterator it = unit_list.begin(), end = unit_list.end(); it != end; ++it) {
        delete *it;
    }
}

bool Map::add_unit(Unit* unit) {
    int x = unit->get_x();
    int y = unit->get_y();
    if (tile_matrix[x][y] == NULL || tile_matrix[x][y]->is_occupied()) {
        delete unit;
        return false;
    }
    else {
        tile_matrix[x][y]->add_unit(unit);
        unit_list.push_back(unit);
        return true;
    }
}

bool Map::remove_unit(Unit* unit) {
    int x = unit->get_x();
    int y = unit->get_y();
    unit_list.remove(unit);
    tile_matrix[x][y]->remove_unit();
    delete unit;
    return true;
}

void Map::destroy_tile_matrix() {
    for (int i = 0; i < int(tile_matrix.size()) ; i++) {
        vector<Tile*> i_row = tile_matrix[i];
        for ( int j = 0; j < int(i_row.size()); j++ ) {
            delete i_row[j];
        }
    }
}

void Map::initialize_tile_matrix() {
    for (int i = 0; i < rows; i++) {
        vector<Tile*> new_row = {};
        for (int j = 0; j < columns; j++) {
            Tile* t = NULL;
            new_row.push_back(t);    
        }
        tile_matrix.push_back(new_row); 
    }
}

bool Map::is_occupied(int x, int y) {
    return tile_matrix[x][y]->is_occupied();
}

bool Map::is_enemy_occupied(int x, int y, Constants::Team team) {
    return is_occupied(x, y) and !(unit_at(x, y)->get_team() == team);
}

bool Map::is_accessible(int x, int y) {
    return tile_matrix[x][y]->is_accessible();
}

Unit* Map::unit_at(int x, int y) {
    return tile_matrix[x][y]->get_unit();
}

bool Map::out_of_bounds(int x, int y) {
    return x < 0 || x >= columns || y < 0 || y >= rows; 
}
bool Map::can_go_to(int x, int y) {
    return ( 
        !out_of_bounds(x, y) && 
        is_accessible(x, y) &&
        !is_occupied(x, y));
}

bool Map::can_go_through(int x, int y, Constants::Team team) {
    return ( 
        !out_of_bounds(x, y) && 
        is_accessible(x, y) &&
        !is_enemy_occupied(x, y, team));
}
