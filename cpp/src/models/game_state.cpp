#include "game_state.h"
#include "map.h"

#include "greaser_unit.h"
#include "bruiser_unit.h"
#include "squabbler_unit.h"
#include "base_unit.h"
#include "cursor.h"

#include "texture_manager.h"

GameState::GameState() {
    cursor = new Cursor(0, 0, 32, 18); 
    set_up_default();
}

void GameState::set_up_default() {
    map = new Map(32, 18);
    map->generate_from_ascii("data/maps/TheBlock.txt");
    GreaserUnit* unit4 = new GreaserUnit(12, 6, Constants::Team::Jets);
    SquabblerUnit* unit5 = new SquabblerUnit(14, 4, Constants::Team::Jets);
    GreaserUnit* unit6 = new GreaserUnit(13, 5, Constants::Team::Jets);
    SquabblerUnit* unit7 = new SquabblerUnit(17,6, Constants::Team::Jets);
    BruiserUnit* unit8 = new BruiserUnit(18,6,Constants::Team::Jets);
    GreaserUnit* unit1 = new GreaserUnit(12, 15, Constants::Team::Sharks);
    BruiserUnit* unit2 = new BruiserUnit(13, 16, Constants::Team::Sharks);
    SquabblerUnit* unit3 = new SquabblerUnit(16, 16, Constants::Team::Sharks);
    BruiserUnit* unit9 = new BruiserUnit(17, 14, Constants::Team::Sharks);
    GreaserUnit* unit10 = new GreaserUnit(14, 14, Constants::Team::Sharks);

    map->add_unit(unit1);
    map->add_unit(unit2);
    map->add_unit(unit3);
    map->add_unit(unit4);
    map->add_unit(unit5);
    map->add_unit(unit6);
    map->add_unit(unit7);
    map->add_unit(unit8);
    map->add_unit(unit9);
    map->add_unit(unit10);
}

GameState::~GameState() {
    delete map;
    delete cursor;
}

void GameState::draw(TextureManager* texture_manager) {
    map->draw(texture_manager);
    cursor->draw(texture_manager);
}
