#include <string>

#include "sub_tile.h"
#include "base_tile.h"
#include "constants.h"

ConcreteTile::ConcreteTile(int x, int y) :
    Tile(
        Constants::ConcreteTile::defense,
        Constants::ConcreteTile::img_path,
        Constants::ConcreteTile::accessible,
        x,
        y)
{ }

GrassTile::GrassTile(int x, int y) :
    Tile(
        Constants::GrassTile::defense,
        Constants::GrassTile::img_path,
        Constants::GrassTile::accessible,
        x,
        y)
{ }

RoadTile::RoadTile(int x, int y, int type) :
    Tile(
        Constants::RoadTile::defense,
        Constants::RoadTile::img_paths[type],
        Constants::RoadTile::accessible,
        x,
        y)
{ }

WallTile::WallTile(int x, int y, int type) :
    Tile(
        Constants::WallTile::defense,
        Constants::WallTile::img_paths[type],
        Constants::WallTile::accessible,
        x,
        y)
{ }

SpecialTile::SpecialTile(int x, int y, int type) : 
    Tile(
        Constants::SpecialTile::defense,
        Constants::SpecialTile::img_paths[type],
        Constants::SpecialTile::accessible,
        x,
        y)
{ }

SceneryTile::SceneryTile(int x, int y) :
    Tile(
        Constants::SceneryTile::defense,
        Constants::SceneryTile::img_path,
        Constants::SceneryTile::accessible,
        x,
        y)
{ }


