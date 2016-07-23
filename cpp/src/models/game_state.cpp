#include "game_state.h"
#include "map.h"

#include "greaser_unit.h"
#include "bruiser_unit.h"
#include "squabbler_unit.h"

#include "texture_manager.h"

GameState::GameState() {
    set_up_default();
}

void GameState::set_up_default() {
    map = new Map(32, 18);
    map->generate_from_ascii("data/maps/TheBlock.txt");
    GreaserUnit* g1 = new GreaserUnit(3,0, Constants::Team::Jets);
    GreaserUnit* g2 = new GreaserUnit(3,1, Constants::Team::Jets);
    GreaserUnit* g3 = new GreaserUnit(3,2, Constants::Team::Jets);
    GreaserUnit* g4 = new GreaserUnit(2,3, Constants::Team::Jets);
    GreaserUnit* g5 = new GreaserUnit(1,3, Constants::Team::Jets);
    GreaserUnit* g6 = new GreaserUnit(0,3, Constants::Team::Jets);
    map->add_unit(g1);
    map->add_unit(g2);
    map->add_unit(g3);
    map->add_unit(g4);
    map->add_unit(g5);
    map->add_unit(g6);
}

GameState::~GameState() {
    delete map;
}

bool GameState::draw(TextureManager* texture_manager) {
    map->draw(texture_manager);
    return true;
}
