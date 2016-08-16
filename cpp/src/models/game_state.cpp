#include "game_state.h"
#include "map.h"

#include "greaser_unit.h"
#include "bruiser_unit.h"
#include "squabbler_unit.h"
#include "base_unit.h"
#include "cursor.h"
#include "info_pane.h"

#include "texture_manager.h"

GameState::GameState() {
    cursor = new Cursor(0, 0, 32, 18);
    GameState* game_state = (GameState*)this;
    info_pane = new InfoPane(game_state); 
    set_up_default();
}

bool GameState::confirm() {
    Unit* unit = map->unit_at(12, 6);
    if (unit != NULL) {
        map->move(unit, 14, 6);
    }
    return true;
}

bool GameState::cancel() {
    return true;
}

bool GameState::cursor_up() {
    return cursor->move_up();
}

bool GameState::cursor_down() {
    return cursor->move_down();
}

bool GameState::cursor_left() {
    return cursor->move_left();
}

bool GameState::cursor_right() {
    return cursor->move_right();
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
    info_pane->draw(texture_manager);
}
