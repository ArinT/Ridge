#include <string>

#include "constants.h"

const int         Constants::BruiserUnit::movement_range   = 4; 
const int         Constants::GreaserUnit::movement_range   = 6; 
const int         Constants::SquabblerUnit::movement_range = 5;
const int         Constants::Unit::max_movement            = 6;
const int         Constants::BruiserUnit::max_hp           = 15;
const int         Constants::BruiserUnit::min_hp           = 12;
const int         Constants::BruiserUnit::max_strength     = 12;
const int         Constants::BruiserUnit::min_strength     = 9;
const int         Constants::BruiserUnit::max_finesse      = 9;
const int         Constants::BruiserUnit::min_finesse      = 6;
const int         Constants::BruiserUnit::max_style        = 6;
const int         Constants::BruiserUnit::min_style        = 3;
const int         Constants::BruiserUnit::max_wit          = 3;
const int         Constants::BruiserUnit::min_wit          = 1;
const int         Constants::GreaserUnit::max_hp           = 12;
const int         Constants::GreaserUnit::min_hp           = 9;
const int         Constants::GreaserUnit::max_strength     = 3;
const int         Constants::GreaserUnit::min_strength     = 1;
const int         Constants::GreaserUnit::max_finesse      = 15;
const int         Constants::GreaserUnit::min_finesse      = 12;
const int         Constants::GreaserUnit::max_style        = 6;
const int         Constants::GreaserUnit::min_style        = 3;
const int         Constants::GreaserUnit::max_wit          = 9;
const int         Constants::GreaserUnit::min_wit          = 3;
const int         Constants::SquabblerUnit::max_hp         = 9;
const int         Constants::SquabblerUnit::min_hp         = 6;
const int         Constants::SquabblerUnit::max_strength   = 6;
const int         Constants::SquabblerUnit::min_strength   = 3;
const int         Constants::SquabblerUnit::max_finesse    = 3;
const int         Constants::SquabblerUnit::min_finesse    = 1;
const int         Constants::SquabblerUnit::max_style      = 12;
const int         Constants::SquabblerUnit::min_style      = 9;
const int         Constants::SquabblerUnit::max_wit        = 15;
const int         Constants::SquabblerUnit::min_wit        = 12;

const std::string Constants::SquabblerUnit::jets_img       = "data/pixel_art/j_sq.png";
const std::string Constants::SquabblerUnit::sharks_img     = "data/pixel_art/s_sq.png";
const std::string Constants::SquabblerUnit::jets_img_bkg   = "data/pixel_art/j_sq_bkg.png";
const std::string Constants::SquabblerUnit::sharks_img_bkg = "data/pixel_art/s_sq_bkg.png";

const std::string Constants::GreaserUnit::jets_img         = "data/pixel_art/j_gr.png";
const std::string Constants::GreaserUnit::sharks_img       = "data/pixel_art/s_gr.png";
const std::string Constants::GreaserUnit::jets_img_bkg     = "data/pixel_art/j_gr_bkg.png";
const std::string Constants::GreaserUnit::sharks_img_bkg   = "data/pixel_art/s_gr_bkg.png";

const std::string Constants::BruiserUnit::jets_img         = "data/pixel_art/j_br.png";
const std::string Constants::BruiserUnit::sharks_img        = "data/pixel_art/s_br.png";
const std::string Constants::BruiserUnit::jets_img_bkg     = "data/pixel_art/j_br_bkg.png";
const std::string Constants::BruiserUnit::sharks_img_bkg    = "data/pixel_art/s_br_bkg.png";

const std::string Constants::BruiserUnit::SFX::attack      = "sfx/woosh.wav";
const std::string Constants::GreaserUnit::SFX::attack      = "sfx/switchblade.wav";
const std::string Constants::SquabblerUnit::SFX::attack    = "sfx/hey.wav";


const std::string Constants::ConcreteTile::img_path        = "data/pixel_art/cr.png";
const int         Constants::ConcreteTile::defense         = 1;
const bool        Constants::ConcreteTile::accessible      = true;

const std::string Constants::GrassTile::img_path           = "data/pixel_art/gs.png";
const int         Constants::GrassTile::defense            = 2;
const bool        Constants::GrassTile::accessible         = true;

const std::string Constants::RoadTile::img_paths[2]        = {
    "data/pixel_art/rd.png",
    "data/pixel_art/rdm.png"
};
const int         Constants::RoadTile::defense             = 0;
const bool        Constants::RoadTile::accessible          = true;

const std::string Constants::WallTile::img_paths[8]        = {
    "data/pixel_art/wall.png",
    "data/pixel_art/walll.png",
    "data/pixel_art/wallu.png",
    "data/pixel_art/wallr.png",
    "data/pixel_art/walld.png",
    "data/pixel_art/wallv.png",
    "data/pixel_art/wallf.png",
    "data/pixel_art/wallg.png"
};
const int         Constants::WallTile::defense             = 0;
const bool        Constants::WallTile::accessible          = false;

const std::string Constants::SpecialTile::img_paths[9]     = {
    "data/pixel_art/rt.png",
    "data/pixel_art/rtr.png",
    "data/pixel_art/rtl.png",
    "data/pixel_art/rtd.png",
    "data/pixel_art/rtu.png",
    "data/pixel_art/rte1.png",
    "data/pixel_art/rte2.png",
    "data/pixel_art/rte3.png",
    "data/pixel_art/rte4.png"
};
const int         Constants::SpecialTile::defense          = 0;
const bool        Constants::SpecialTile::accessible       = false;

const std::string Constants::SceneryTile::img_path         = "data/pixel_art/tcr.png";
const int         Constants::SceneryTile::defense          = 0;
const bool        Constants::SceneryTile::accessible       = false;

