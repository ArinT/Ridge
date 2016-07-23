#include "constants.h"
#include "gtest/gtest.h"

TEST(ConstantsTest, Basic) {
    EXPECT_EQ(Constants::BruiserUnit::movement_range        , 4); 
    EXPECT_EQ(Constants::GreaserUnit::movement_range        , 6); 
    EXPECT_EQ(Constants::SquabblerUnit::movement_range      , 5); 
    EXPECT_EQ(Constants::BruiserUnit::max_hp          , 15);
    EXPECT_EQ(Constants::BruiserUnit::min_hp          , 12);
    EXPECT_EQ(Constants::BruiserUnit::max_strength    , 12);
    EXPECT_EQ(Constants::BruiserUnit::min_strength    , 9);
    EXPECT_EQ(Constants::BruiserUnit::max_finesse     , 9);
    EXPECT_EQ(Constants::BruiserUnit::min_finesse     , 6);
    EXPECT_EQ(Constants::BruiserUnit::max_style       , 6);
    EXPECT_EQ(Constants::BruiserUnit::min_style       , 3);
    EXPECT_EQ(Constants::BruiserUnit::max_wit         , 3);
    EXPECT_EQ(Constants::BruiserUnit::min_wit         , 1);
    EXPECT_EQ(Constants::GreaserUnit::max_hp          , 12);
    EXPECT_EQ(Constants::GreaserUnit::min_hp          , 9);
    EXPECT_EQ(Constants::GreaserUnit::max_strength    , 3);
    EXPECT_EQ(Constants::GreaserUnit::min_strength    , 1);
    EXPECT_EQ(Constants::GreaserUnit::max_finesse     , 15);
    EXPECT_EQ(Constants::GreaserUnit::min_finesse     , 12);
    EXPECT_EQ(Constants::GreaserUnit::max_style       , 6);
    EXPECT_EQ(Constants::GreaserUnit::min_style       , 3);
    EXPECT_EQ(Constants::GreaserUnit::max_wit         , 9);
    EXPECT_EQ(Constants::GreaserUnit::min_wit         , 3);
    EXPECT_EQ(Constants::SquabblerUnit::max_hp        , 9);
    EXPECT_EQ(Constants::SquabblerUnit::min_hp        , 6);
    EXPECT_EQ(Constants::SquabblerUnit::max_strength  , 6);
    EXPECT_EQ(Constants::SquabblerUnit::min_strength  , 3);
    EXPECT_EQ(Constants::SquabblerUnit::max_finesse   , 3);
    EXPECT_EQ(Constants::SquabblerUnit::min_finesse   , 1);
    EXPECT_EQ(Constants::SquabblerUnit::max_style     , 12);
    EXPECT_EQ(Constants::SquabblerUnit::min_style     , 9);
    EXPECT_EQ(Constants::SquabblerUnit::max_wit       , 15);
    EXPECT_EQ(Constants::SquabblerUnit::min_wit       , 12);

    EXPECT_EQ(Constants::SquabblerUnit::jets_img        , "data/pixel_art/j_sq.png");
    EXPECT_EQ(Constants::SquabblerUnit::sharks_img      , "data/pixel_art/s_sq.png");
    EXPECT_EQ(Constants::SquabblerUnit::jets_img_bkg    , "data/pixel_art/j_sq_bkg.png");
    EXPECT_EQ(Constants::SquabblerUnit::sharks_img_bkg  , "data/pixel_art/s_sq_bkg.png");

    EXPECT_EQ(Constants::GreaserUnit::jets_img          , "data/pixel_art/j_gr.png");
    EXPECT_EQ(Constants::GreaserUnit::sharks_img        , "data/pixel_art/s_gr.png");
    EXPECT_EQ(Constants::GreaserUnit::jets_img_bkg      , "data/pixel_art/j_gr_bkg.png");
    EXPECT_EQ(Constants::GreaserUnit::sharks_img_bkg    , "data/pixel_art/s_gr_bkg.png");

    EXPECT_EQ(Constants::BruiserUnit::jets_img          , "data/pixel_art/j_br.png");
    EXPECT_EQ(Constants::BruiserUnit::sharks_img        , "data/pixel_art/s_br.png");
    EXPECT_EQ(Constants::BruiserUnit::jets_img_bkg      , "data/pixel_art/j_br_bkg.png");
    EXPECT_EQ(Constants::BruiserUnit::sharks_img_bkg     , "data/pixel_art/s_br_bkg.png");

//    EXPECT_EQ(Constants::RoadTile::img_path             , "data/pixel_art/rd.png");
//    EXPECT_EQ(Constants::GrassTile::img_path            , "data/pixel_art/gr.png");
//    EXPECT_EQ(Constants::ConcreteTile::img_path         , "data/pixel_art/cr.png");
//    EXPECT_EQ(Constants::SpecialTile::img_path          , "data/pixel_art/rt.png");
//    EXPECT_EQ(Constants::SceneryTile::img_path          , "data/pixel_art/tcr.png");
//    EXPECT_EQ(Constants::WallTile::img_path             , "data/pixel_art/wall.png");
//    EXPECT_EQ(Constants::TileImagePaths::empty          , "data/pixel_art/empty.png");
//    EXPECT_EQ(Constants::UnitSFXPaths::bruiser_attack   , "sfx/woosh.wav");
//    EXPECT_EQ(Constants::UnitSFXPaths::greaser_attack   , "sfx/switchblade.wav");
//    EXPECT_EQ(Constants::UnitSFXPaths::squabbler_attack , "sfx/hey.wav");

}

