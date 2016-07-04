#include "greaser_unit.h"
#include "squabbler_unit.h"
#include "bruiser_unit.h"
#include "base_unit.h"
#include "gtest/gtest.h"
#include "constants.h"

class SubUnitTest : public testing::Test {
    protected:
        virtual void SetUp() {
            g = new GreaserUnit(1, 1, Constants::Team::Sharks);
            s = new SquabblerUnit(1, 1, Constants::Team::Sharks);
            b = new BruiserUnit(1, 1, Constants::Team::Sharks);
        }
        virtual void TearDown() {
            delete g;
            delete s;
            delete b;
        }
        Unit* g;
        Unit* s;
        Unit* b;
};

TEST_F(SubUnitTest, BasicConstructorGreaser) {
    EXPECT_EQ(6, g->get_movement_range());
    EXPECT_EQ(1, g->get_x());
    EXPECT_EQ(1, g->get_y());
    EXPECT_EQ(Constants::Team::Sharks, g->get_team());

    EXPECT_GT(Constants::greaser_max_hp+1, g->get_hp());
    EXPECT_LT(Constants::greaser_min_hp-1, g->get_hp());
    
    EXPECT_GT(Constants::greaser_max_strength+1, g->get_strength());
    EXPECT_LT(Constants::greaser_min_strength-1, g->get_strength());

    EXPECT_GT(Constants::greaser_max_finesse+1, g->get_finesse());
    EXPECT_LT(Constants::greaser_min_finesse-1, g->get_finesse());

    EXPECT_GT(Constants::greaser_max_wit+1, g->get_wit());
    EXPECT_LT(Constants::greaser_min_wit-1, g->get_wit());

    EXPECT_GT(Constants::greaser_max_style+1, g->get_style());
    EXPECT_LT(Constants::greaser_min_style-1, g->get_style());
}

TEST_F(SubUnitTest, BasicConstructorBruiser) {
    EXPECT_EQ(4, b->get_movement_range());
    EXPECT_EQ(1, b->get_x());
    EXPECT_EQ(1, b->get_y());
    EXPECT_EQ(Constants::Team::Sharks, b->get_team());

    EXPECT_GT(Constants::bruiser_max_hp+1, b->get_hp());
    EXPECT_LT(Constants::bruiser_min_hp-1, b->get_hp());
    
    EXPECT_GT(Constants::bruiser_max_strength+1, b->get_strength());
    EXPECT_LT(Constants::bruiser_min_strength-1, b->get_strength());

    EXPECT_GT(Constants::bruiser_max_finesse+1, b->get_finesse());
    EXPECT_LT(Constants::bruiser_min_finesse-1, b->get_finesse());

    EXPECT_GT(Constants::bruiser_max_wit+1, b->get_wit());
    EXPECT_LT(Constants::bruiser_min_wit-1, b->get_wit());

    EXPECT_GT(Constants::bruiser_max_style+1, b->get_style());
    EXPECT_LT(Constants::bruiser_min_style-1, b->get_style());
}

TEST_F(SubUnitTest, BasicConstructorSquabbler) {
    EXPECT_EQ(5, s->get_movement_range());
    EXPECT_EQ(1, s->get_x());
    EXPECT_EQ(1, s->get_y());
    EXPECT_EQ(Constants::Team::Sharks, s->get_team());

    EXPECT_GT(Constants::squabbler_max_hp+1, s->get_hp());
    EXPECT_LT(Constants::squabbler_min_hp-1, s->get_hp());
    
    EXPECT_GT(Constants::squabbler_max_strength+1, s->get_strength());
    EXPECT_LT(Constants::squabbler_min_strength-1, s->get_strength());

    EXPECT_GT(Constants::squabbler_max_finesse+1, s->get_finesse());
    EXPECT_LT(Constants::squabbler_min_finesse-1, s->get_finesse());

    EXPECT_GT(Constants::squabbler_max_wit+1, s->get_wit());
    EXPECT_LT(Constants::squabbler_min_wit-1, s->get_wit());

    EXPECT_GT(Constants::squabbler_max_style+1, s->get_style());
    EXPECT_LT(Constants::squabbler_min_style-1, s->get_style());
}

