#ifndef RIDGE_TILES_SUBTILE_H
#define RIDGE_TILES_SUBTILE_H

#include <string>

#include "base_tile.h"

class ConcreteTile : public Tile {
    public:
        ConcreteTile(int x, int y); 
};

class GrassTile : public Tile {
    public:
        GrassTile(int x, int y); 
};

class RoadTile : public Tile {
    public:
        RoadTile(int x, int y, int type); 
};

class WallTile : public Tile {
    public:
        WallTile(int x, int y, int type); 
};

class SpecialTile : public Tile {
    public:
        SpecialTile(int x, int y, int type); 
};

class SceneryTile : public Tile {
    public:
        SceneryTile(int x, int y); 
};

#endif
