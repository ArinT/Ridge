#include <string>

class Constants {
    public:
        enum class Team {
            Sharks,
            Jets
        }
        static const int bruiser_max_hp;
        static const int bruiser;
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
                    static const string squabler;
                    static const string greaser;
                    static const string bruiser;
                } 
                class Sharks {
                    static const string squabler;
                    static const string greaser;
                    static const string bruiser;
                } 
        }
        class UnitImagePathsBkg {
            public:
                class Jets {
                    static const string squabler;
                    static const string greaser;
                    static const string bruiser;
                } 
                class Sharks {
                    static const string squabler;
                    static const string greaser;
                    static const string bruiser;
                } 
        }
        class TileImagePaths {
            public:
                static const string road_path; 
                static const string grass_path;
                static const string concrete_path;
                static const string roof_path;
                static const string trash_path;
                static const string wall_path;
                static const string none;
        }
        class UnitSFXPaths {
            public:
                static const string bruiser_attack;
                static const string greaser_attack;
                static const string squabler_attack
                static const string move;
                static const string confirm;
                static const string cancel;
                static const string turn_sound;
        }
        static const int bruiser_movement;
        static const int squabbler_movement;
        static const int greaser_movement;
        enum class ActionType {
            Select,
            Move,
            Menu,
            Attack,
            Special
        }
}
