#include <vector>
#include <list>
#include <string>
#include <fstream>

#include "constants.h"
#include "map.h"
#include "base_tile.h"
#include "base_unit.h"
#include "sub_tile.h"

using std::vector;
using std::list;
using std::string;

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
        vector<Tile*> i_column = tile_matrix[i];
        for ( int j = 0; j < int(i_column.size()); j++ ) {
            delete i_column[j];
        }
    }
}

void Map::initialize_tile_matrix() {
    for (int i = 0; i < columns; i++) {
        vector<Tile*> new_column = {};
        for (int j = 0; j < rows; j++) {
            Tile* t = NULL;
            new_column.push_back(t);    
        }
        tile_matrix.push_back(new_column); 
    }
}

bool Map::is_occupied(int x, int y) {
    return tile_matrix[x][y] != NULL && tile_matrix[x][y]->is_occupied();
}

bool Map::is_enemy_occupied(int x, int y, Constants::Team team) {
    return is_occupied(x, y) && unit_at(x, y)->get_team() != team;
}

bool Map::is_accessible(int x, int y) {
    return tile_matrix[x][y]->is_accessible();
}

bool Map::can_go_to(int x, int y) {
    return (
        !out_of_bounds(x, y) &&
        is_accessible(x, y) &&
        !is_occupied(x, y)
    );
}

Unit* Map::unit_at(int x, int y) {
    return tile_matrix[x][y]->get_unit();
}

bool Map::out_of_bounds(int x, int y) {
    return x < 0 || x >= columns || y < 0 || y >= rows; 
}

bool Map::can_go_through(int x, int y, Constants::Team team) {
    return ( 
        !out_of_bounds(x, y) && 
        is_accessible(x, y) &&
        !is_enemy_occupied(x, y, team));
}

void Map::generate_from_ascii(string filename) {
    string line;
    std::ifstream infile(filename);
    for (int i = 0; i < rows; i++) {
        std::getline(infile, line);
        for (int j = 0; j < columns; j++) {
            lay_tile(line[j], j, i);
        }
    }
    infile.close();
}

Tile* Map::get_tile(int x, int y) {
    return tile_matrix[x][y];
}

void Map::lay_tile(char c, int x, int y) {
    switch (c) {
        case 'R':
            tile_matrix[x][y] = new RoadTile(x, y, 0); break;
        case 'T':
            tile_matrix[x][y] = new RoadTile(x, y, 1); break;
        case 'C':
            tile_matrix[x][y] = new ConcreteTile(x, y); break;
        case 'G':
            tile_matrix[x][y] = new GrassTile(x, y); break;
        case 'W':
            tile_matrix[x][y] = new WallTile(x, y, 0); break;
        case 'S':
            tile_matrix[x][y] = new SceneryTile(x, y); break;
        case '1':
            tile_matrix[x][y] = new WallTile(x ,y, 1); break;
        case '2':
            tile_matrix[x][y] = new WallTile(x, y, 2); break;
        case '3':
            tile_matrix[x][y] = new WallTile(x, y, 3); break;
        case '4':
            tile_matrix[x][y] = new WallTile(x, y, 4); break;
        case 'V':
            tile_matrix[x][y] = new WallTile(x, y, 5); break;
        case 'D':
            tile_matrix[x][y] = new WallTile(x, y, 6); break;
        case 'F':
            tile_matrix[x][y] = new WallTile(x, y, 7); break;
        case 'A':
            tile_matrix[x][y] = new SpecialTile(x, y, 0); break;
        case 'Y':
            tile_matrix[x][y] = new SpecialTile(x, y, 1); break;
        case 'U':
            tile_matrix[x][y] = new SpecialTile(x, y, 2); break;
        case 'I':
            tile_matrix[x][y] = new SpecialTile(x, y, 3); break;
        case 'O':
            tile_matrix[x][y] = new SpecialTile(x, y, 4); break;
        case 'P':
            tile_matrix[x][y] = new SpecialTile(x, y, 5); break;
        case 'L':
            tile_matrix[x][y] = new SpecialTile(x, y, 6); break;
        case 'K':
            tile_matrix[x][y] = new SpecialTile(x, y, 7); break;
        case 'J':
            tile_matrix[x][y] = new SpecialTile(x, y, 8); break;
        default:
            tile_matrix[x][y] = new WallTile(x, y, 0); break;
    }
}
