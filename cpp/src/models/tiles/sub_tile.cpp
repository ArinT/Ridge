#include <string>

#include "sub_tile.h"
#include "base_tile.h"
#include "constants.h"

const std::string ConcreteTile::IMG_PATH = "data/pixel_art/cr.png";
const int ConcreteTile::DEFENSE = 1;
const bool ConcreteTile::ACCESSIBLE = true;

ConcreteTile::ConcreteTile(int x, int y) :
    Tile(
        ConcreteTile::DEFENSE,
        ConcreteTile::IMG_PATH,
        ConcreteTile::ACCESSIBLE,
        x,
        y)
{ }

const std::string GrassTile::IMG_PATH = "data/pixel_art/gs.png";
const int GrassTile::DEFENSE = 2;
const bool GrassTile::ACCESSIBLE = true;

GrassTile::GrassTile(int x, int y) :
    Tile(
        GrassTile::DEFENSE,
        GrassTile::IMG_PATH,
        GrassTile::ACCESSIBLE,
        x,
        y)
{ }

const std::string RoadTile::IMG_PATHS[2] = {
    "data/pixel_art/rd.png",
    "data/pixel_art/rdm.png"
};
const int RoadTile::DEFENSE = 0;
const bool RoadTile::ACCESSIBLE = true;

RoadTile::RoadTile(int x, int y, int type) :
    Tile(
        RoadTile::DEFENSE,
        RoadTile::IMG_PATHS[type],
        RoadTile::ACCESSIBLE,
        x,
        y)
{ }

const std::string WallTile::IMG_PATHS[8] = {
    "data/pixel_art/wall.png",
    "data/pixel_art/walll.png",
    "data/pixel_art/wallu.png",
    "data/pixel_art/wallr.png",
    "data/pixel_art/walld.png",
    "data/pixel_art/wallv.png",
    "data/pixel_art/wallf.png",
    "data/pixel_art/wallg.png"
};
const int WallTile::DEFENSE = 0;
const bool WallTile::ACCESSIBLE = false;

WallTile::WallTile(int x, int y, int type) :
    Tile(
        WallTile::DEFENSE,
        WallTile::IMG_PATHS[type],
        WallTile::ACCESSIBLE,
        x,
        y)
{ }

const std::string SpecialTile::IMG_PATHS[8] = {
    "data/pixel_art/rtr.png",
    "data/pixel_art/rtl.png",
    "data/pixel_art/rtd.png",
    "data/pixel_art/rtu.png",
    "data/pixel_art/rte1.png",
    "data/pixel_art/rte2.png",
    "data/pixel_art/rte3.png",
    "data/pixel_art/rte4.png"
};
const int SpecialTile::DEFENSE = 0;
const bool SpecialTile::ACCESSIBLE = false;

SpecialTile::SpecialTile(int x, int y, int type) : 
    Tile(
        SpecialTile::DEFENSE,
        SpecialTile::IMG_PATHS[type],
        SpecialTile::ACCESSIBLE,
        x,
        y)
{ }

const std::string SceneryTile::IMG_PATH = "data/pixel_art/tcr.png";
const int SceneryTile::DEFENSE = 0;
const bool SceneryTile::ACCESSIBLE = false;

SceneryTile::SceneryTile(int x, int y) :
    Tile(
        SceneryTile::DEFENSE,
        SceneryTile::IMG_PATH,
        SceneryTile::ACCESSIBLE,
        x,
        y)
{ }


