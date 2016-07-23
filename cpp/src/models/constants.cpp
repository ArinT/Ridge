#include <string>

#include "constants.h"

const int Constants::bruiser_movement        = 4; 
const int Constants::greaser_movement        = 6; 
const int Constants::squabbler_movement      = 5;
const int Constants::max_movement            = 6;
const int Constants::bruiser_max_hp          = 15;
const int Constants::bruiser_min_hp          = 12;
const int Constants::bruiser_max_strength    = 12;
const int Constants::bruiser_min_strength    = 9;
const int Constants::bruiser_max_finesse     = 9;
const int Constants::bruiser_min_finesse     = 6;
const int Constants::bruiser_max_style       = 6;
const int Constants::bruiser_min_style       = 3;
const int Constants::bruiser_max_wit         = 3;
const int Constants::bruiser_min_wit         = 1;
const int Constants::greaser_max_hp          = 12;
const int Constants::greaser_min_hp          = 9;
const int Constants::greaser_max_strength    = 3;
const int Constants::greaser_min_strength    = 1;
const int Constants::greaser_max_finesse     = 15;
const int Constants::greaser_min_finesse     = 12;
const int Constants::greaser_max_style       = 6;
const int Constants::greaser_min_style       = 3;
const int Constants::greaser_max_wit         = 9;
const int Constants::greaser_min_wit         = 3;
const int Constants::squabbler_max_hp        = 9;
const int Constants::squabbler_min_hp        = 6;
const int Constants::squabbler_max_strength  = 6;
const int Constants::squabbler_min_strength  = 3;
const int Constants::squabbler_max_finesse   = 3;
const int Constants::squabbler_min_finesse   = 1;
const int Constants::squabbler_max_style     = 12;
const int Constants::squabbler_min_style     = 9;
const int Constants::squabbler_max_wit       = 15;
const int Constants::squabbler_min_wit       = 12;

const std::string Constants::UnitImagePaths::Jets::squabbler = "data/pixel_art/j_sq.png";
const std::string Constants::UnitImagePaths::Jets::greaser = "data/pixel_art/j_gr.png";
const std::string Constants::UnitImagePaths::Jets::bruiser = "data/pixel_art/j_br.png";

const std::string Constants::UnitImagePaths::Sharks::squabbler = "data/pixel_art/s_sq.png";
const std::string Constants::UnitImagePaths::Sharks::greaser = "data/pixel_art/s_gr.png";
const std::string Constants::UnitImagePaths::Sharks::bruiser = "data/pixel_art/s_br.png";

const std::string Constants::UnitImagePathsBkg::Jets::squabbler = "data/pixel_art/j_sq_bkg.png";
const std::string Constants::UnitImagePathsBkg::Jets::greaser = "data/pixel_art/j_gr_bkg.png";
const std::string Constants::UnitImagePathsBkg::Jets::bruiser = "data/pixel_art/j_br_bkg.png";

const std::string Constants::UnitImagePathsBkg::Sharks::squabbler = "data/pixel_art/s_sq_bkg.png";
const std::string Constants::UnitImagePathsBkg::Sharks::greaser = "data/pixel_art/s_gr_bkg.png";
const std::string Constants::UnitImagePathsBkg::Sharks::bruiser = "data/pixel_art/s_br_bkg.png";

const std::string Constants::TileImagePaths::road_path = "data/pixel_art/rd.png";
const std::string Constants::TileImagePaths::grass_path = "data/pixel_art/gr.png";
const std::string Constants::TileImagePaths::concrete_path = "data/pixel_art/cr.png";
const std::string Constants::TileImagePaths::roof_path = "data/pixel_art/rt.png";
const std::string Constants::TileImagePaths::trash_path = "data/pixel_art/tcr.png";
const std::string Constants::TileImagePaths::wall_path = "data/pixel_art/wall.png";
const std::string Constants::TileImagePaths::empty = "data/pixel_art/empty.png";

const std::string Constants::UnitSFXPaths::bruiser_attack = "sfx/woosh.wav";
const std::string Constants::UnitSFXPaths::greaser_attack = "sfx/switchblade.wav";
const std::string Constants::UnitSFXPaths::squabbler_attack = "sfx/hey.wav";

