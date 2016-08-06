#ifndef RIDGE_MODELS_CONSTANTS_H
#define RIDGE_MODELS_CONSTANTS_H
#include <string>

struct Constants {
    enum struct Team {
        Sharks,
        Jets
    };
    struct SFX {
        static const std::string move;
        static const std::string confirm;
        static const std::string cancel;
        static const std::string turn_sound;
    };
    struct Unit {
        static const int max_movement;
    };
    struct GameStateImg {
        static const std::string cursor;
    };
    struct BruiserUnit {
        struct SFX {
            static const std::string attack;
        };
        static const std::string jets_img;
        static const std::string sharks_img;
        static const std::string jets_img_bkg;
        static const std::string sharks_img_bkg;
        static const int max_hp;
        static const int min_hp;
        static const int max_strength;
        static const int min_strength;
        static const int max_finesse;
        static const int min_finesse;
        static const int max_style;
        static const int min_style;
        static const int max_wit;
        static const int min_wit;
        static const int movement_range;
    };
    struct GreaserUnit {
        struct SFX {
            static const std::string attack;
        };
        static const std::string jets_img;
        static const std::string sharks_img;
        static const std::string jets_img_bkg;
        static const std::string sharks_img_bkg;
        static const int max_hp;
        static const int min_hp;
        static const int max_strength;
        static const int min_strength;
        static const int max_finesse;
        static const int min_finesse;
        static const int max_style;
        static const int min_style;
        static const int max_wit;
        static const int min_wit;
        static const int movement_range;
    };
    struct SquabblerUnit {
        struct SFX {
            static const std::string attack;
        };
        static const std::string jets_img;
        static const std::string sharks_img;
        static const std::string jets_img_bkg;
        static const std::string sharks_img_bkg;
        static const int max_hp;
        static const int min_hp;
        static const int max_strength;
        static const int min_strength;
        static const int max_finesse;
        static const int min_finesse;
        static const int max_style;
        static const int min_style;
        static const int max_wit;
        static const int min_wit;
        static const int movement_range;
    };
    struct ConcreteTile {
        static const int defense;
        static const bool accessible; 
        static const std::string img_path;
    };
    struct GrassTile {
        static const int defense;
        static const bool accessible; 
        static const std::string img_path;
    };
    struct RoadTile {
        static const int defense;
        static const bool accessible; 
        static const std::string img_paths[2];
    };
    struct WallTile {
        static const int defense;
        static const bool accessible; 
        static const std::string img_paths[8];
    };
    struct SpecialTile {
        static const int defense;
        static const bool accessible; 
        static const std::string img_paths[9];
    };
    struct SceneryTile {
        static const int defense;
        static const bool accessible; 
        static const std::string img_path;
    };
    enum struct ActionType {
        Select,
        Move,
        Menu,
        Attack,
        Special
    };
};

#endif
