#include "constants.h"
#include "gtest/gtest.h"

TEST(ConstantsTest, Basic) {
    EXPECT_EQ(Constants::bruiser_movement        , 4); 
    EXPECT_EQ(Constants::greaser_movement        , 6); 
    EXPECT_EQ(Constants::squabbler_movement      , 5); 
    EXPECT_EQ(Constants::bruiser_max_hp          , 15);
    EXPECT_EQ(Constants::bruiser_min_hp          , 12);
    EXPECT_EQ(Constants::bruiser_max_strength    , 12);
    EXPECT_EQ(Constants::bruiser_min_strength    , 9);
    EXPECT_EQ(Constants::bruiser_max_finesse     , 9);
    EXPECT_EQ(Constants::bruiser_min_finesse     , 6);
    EXPECT_EQ(Constants::bruiser_max_style       , 6);
    EXPECT_EQ(Constants::bruiser_min_style       , 3);
    EXPECT_EQ(Constants::bruiser_max_wit         , 3);
    EXPECT_EQ(Constants::bruiser_min_wit         , 1);
    EXPECT_EQ(Constants::greaser_max_hp          , 12);
    EXPECT_EQ(Constants::greaser_min_hp          , 9);
    EXPECT_EQ(Constants::greaser_max_strength    , 3);
    EXPECT_EQ(Constants::greaser_min_strength    , 1);
    EXPECT_EQ(Constants::greaser_max_finesse     , 15);
    EXPECT_EQ(Constants::greaser_min_finesse     , 12);
    EXPECT_EQ(Constants::greaser_max_style       , 6);
    EXPECT_EQ(Constants::greaser_min_style       , 3);
    EXPECT_EQ(Constants::greaser_max_wit         , 9);
    EXPECT_EQ(Constants::greaser_min_wit         , 3);
    EXPECT_EQ(Constants::squabbler_max_hp        , 9);
    EXPECT_EQ(Constants::squabbler_min_hp        , 6);
    EXPECT_EQ(Constants::squabbler_max_strength  , 6);
    EXPECT_EQ(Constants::squabbler_min_strength  , 3);
    EXPECT_EQ(Constants::squabbler_max_finesse   , 3);
    EXPECT_EQ(Constants::squabbler_min_finesse   , 1);
    EXPECT_EQ(Constants::squabbler_max_style     , 12);
    EXPECT_EQ(Constants::squabbler_min_style     , 9);
    EXPECT_EQ(Constants::squabbler_max_wit       , 15);
    EXPECT_EQ(Constants::squabbler_min_wit       , 12);

    EXPECT_EQ(Constants::UnitImagePaths::Jets::squabbler , "pixel_art/j_sq.png");
    EXPECT_EQ(Constants::UnitImagePaths::Jets::greaser , "pixel_art/j_gr.png");
    EXPECT_EQ(Constants::UnitImagePaths::Jets::bruiser , "pixel_art/j_br.png");
    EXPECT_EQ(Constants::UnitImagePaths::Sharks::squabbler , "pixel_art/s_sq.png");
    EXPECT_EQ(Constants::UnitImagePaths::Sharks::greaser , "pixel_art/s_gr.png");
    EXPECT_EQ(Constants::UnitImagePaths::Sharks::bruiser , "pixel_art/s_br.png");
    EXPECT_EQ(Constants::UnitImagePathsBkg::Jets::squabbler , "pixel_art/j_sq_bkg.png");
    EXPECT_EQ(Constants::UnitImagePathsBkg::Jets::greaser , "pixel_art/j_gr_bkg.png");
    EXPECT_EQ(Constants::UnitImagePathsBkg::Jets::bruiser , "pixel_art/j_br_bkg.png");
    EXPECT_EQ(Constants::UnitImagePathsBkg::Sharks::squabbler , "pixel_art/s_sq_bkg.png");
    EXPECT_EQ(Constants::UnitImagePathsBkg::Sharks::greaser , "pixel_art/s_gr_bkg.png");
    EXPECT_EQ(Constants::UnitImagePathsBkg::Sharks::bruiser , "pixel_art/s_br_bkg.png");
    EXPECT_EQ(Constants::TileImagePaths::road_path , "pixel_art/rd.png");
    EXPECT_EQ(Constants::TileImagePaths::grass_path , "pixel_art/gr.png");
    EXPECT_EQ(Constants::TileImagePaths::concrete_path , "pixel_art/cr.png");
    EXPECT_EQ(Constants::TileImagePaths::roof_path , "pixel_art/rt.png");
    EXPECT_EQ(Constants::TileImagePaths::trash_path , "pixel_art/tcr.png");
    EXPECT_EQ(Constants::TileImagePaths::wall_path , "pixel_art/wall.png");
    EXPECT_EQ(Constants::TileImagePaths::empty , "pixel_art/empty.png");
    EXPECT_EQ(Constants::UnitSFXPaths::bruiser_attack , "sfx/woosh.wav");
    EXPECT_EQ(Constants::UnitSFXPaths::greaser_attack , "sfx/switchblade.wav");
    EXPECT_EQ(Constants::UnitSFXPaths::squabbler_attack , "sfx/hey.wav");

}

