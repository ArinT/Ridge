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
