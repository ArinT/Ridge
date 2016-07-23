#ifndef RIDGE_TILES_SUBTILE_H
#define RIDGE_TILES_SUBTILE_H

#include <string>

#include "base_tile.h"

class ConcreteTile : public Tile {
    private:
        static const int DEFENSE;
        static const bool ACCESSIBLE;
        static const std::string IMG_PATH;
    public:
        ConcreteTile(int x, int y); 
};

class GrassTile : public Tile {
    private:
        static const int DEFENSE;
        static const bool ACCESSIBLE;
        static const std::string IMG_PATH;
    public:
        GrassTile(int x, int y); 
};

class RoadTile : public Tile {
    private:
        static const int DEFENSE;
        static const bool ACCESSIBLE;
        static const std::string IMG_PATHS[2];
    public:
        RoadTile(int x, int y, int type); 
};

class WallTile : public Tile {
    private:
        static const int DEFENSE;
        static const bool ACCESSIBLE;
        static const std::string IMG_PATHS[8];
    public:
        WallTile(int x, int y, int type); 
};

class SpecialTile : public Tile {
    private:
        static const int DEFENSE;
        static const bool ACCESSIBLE;
        static const std::string IMG_PATHS[9];
    public:
        SpecialTile(int x, int y, int type); 
};

class SceneryTile : public Tile {
    private:
        static const int DEFENSE;
        static const bool ACCESSIBLE;
        static const std::string IMG_PATH;
    public:
        SceneryTile(int x, int y); 
};

#endif
