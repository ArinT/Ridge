#ifndef RIDGE_MODELS_CONSTANTS_H
#define RIDGE_MODELS_CONSTANTS_H
#include <string>

class Constants {
    public:
        enum class Team {
            Sharks,
            Jets
        };
        static const int bruiser_max_hp;
        static const int bruiser_min_hp;
        static const int bruiser_max_strength;
        static const int bruiser_min_strength;
        static const int bruiser_max_finesse;
        static const int bruiser_min_finesse;
        static const int bruiser_max_style;
        static const int bruiser_min_style;
        static const int bruiser_max_wit;
        static const int bruiser_min_wit;
        static const int greaser_max_hp;
        static const int greaser_min_hp;
        static const int greaser_max_strength;
        static const int greaser_min_strength;
        static const int greaser_max_finesse;
        static const int greaser_min_finesse;
        static const int greaser_max_style;
        static const int greaser_min_style;
        static const int greaser_max_wit;
        static const int greaser_min_wit;
        static const int squabbler_max_hp;
        static const int squabbler_min_hp;
        static const int squabbler_max_strength;
        static const int squabbler_min_strength;
        static const int squabbler_max_finesse;
        static const int squabbler_min_finesse;
        static const int squabbler_max_style;
        static const int squabbler_min_style;
        static const int squabbler_max_wit;
        static const int squabbler_min_wit;
        class UnitImagePaths {
            public:
                class Jets {
                    public:
                        static const std::string squabbler;
                        static const std::string greaser;
                        static const std::string bruiser;
                }; 
                class Sharks {
                    public:
                        static const std::string squabbler;
                        static const std::string greaser;
                        static const std::string bruiser;
                };
        };
        class UnitImagePathsBkg {
            public:
                class Jets {
                    public:
                        static const std::string squabbler;
                        static const std::string greaser;
                        static const std::string bruiser;
                };
                class Sharks {
                    public:
                        static const std::string squabbler;
                        static const std::string greaser;
                        static const std::string bruiser;
                };
        };
        class TileImagePaths {
            public:
                static const std::string road_path; 
                static const std::string grass_path;
                static const std::string concrete_path;
                static const std::string roof_path;
                static const std::string trash_path;
                static const std::string wall_path;
                static const std::string empty;
        };
        class UnitSFXPaths {
            public:
                static const std::string bruiser_attack;
                static const std::string greaser_attack;
                static const std::string squabbler_attack;
                static const std::string move;
                static const std::string confirm;
                static const std::string cancel;
                static const std::string turn_sound;
        };
        static const int bruiser_movement;
        static const int squabbler_movement;
        static const int greaser_movement;
        enum class ActionType {
            Select,
            Move,
            Menu,
            Attack,
            Special
        };
};

#endif
