#ifndef AI_PLAYER
#define AI_PLAYER

#include "Game_handling.h";
#include <limits>

constexpr int PATCH_INDEX_OFFSET = 1;


class AI {
public:
    AI(const int ai_start_int, Game_handling& game_logic_given) : ai_int(ai_start_int),game_logic(game_logic_given), ai_blanket(game_logic_given.get_blanket(ai_start_int)) {
        base_patch_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //base, some patches can have negative value
        incremental_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //same
        patch_value(); //calculate patch value and patch increment value

    };
    //needed because class doesn't have default constructor
    AI& operator=(const AI& other) {
        this->ai_blanket = other.ai_blanket;
        this->game_logic = other.game_logic;
        this->ai_int = other.ai_int;
        base_patch_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //base, some patches can have negative value
        incremental_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //same
        patch_value(); //calculate patch value and patch increment value
        return *this;
    }

    
private:
    std::vector<int> base_patch_value; //storing patch value
    std::vector<int> incremental_value;
    int ai_int; //number of the ai player
    Game_handling& game_logic;
    Blanket& ai_blanket; //ai blanket

    void patch_value() {
        auto patches = game_logic.get_actual_patches();   //get all the patches
        for (auto&& patch : patches) { //go through all the matches
            int num_true = 0; //store the number of hits
            auto patch_map = patch.oriented_map('n', false); //get the patch map
            for (auto&& line : patch_map) { //go through the map and collect the hits
                for (size_t i = 0; i < line.size(); i++){
                    if (line[i]) {
                        num_true++;
                    }
                }               
            }
            base_patch_value[patch.get_patch_index() - PATCH_INDEX_OFFSET] = (num_true * 2) - patch.get_knobs_cost() - patch.get_time_cost(); //write down the numbers
            incremental_value[patch.get_patch_index() - PATCH_INDEX_OFFSET] = patch.get_bonus_knobs();
        }
    }

    size_t best_playeble_index(std::vector<Patch>& playeble_patches) {

        size_t num_bonus_left = 0;
        std::vector<int> bonus_knob_pos = std::vector<int>(std::begin(BASE_KNOB_POS), std::end(BASE_KNOB_POS));
        for (int i = 0; i < bonus_knob_pos.size(); i++) {
            if (game_logic.get_time(ai_int) > bonus_knob_pos[i]) {
                num_bonus_left = bonus_knob_pos.size() - i;
                break;
            }
        }
        size_t best_index = -1;
        int curr_max = std::numeric_limits<int>::min();

        for (size_t i = 0; i < playeble_patches.size(); i++) {
            size_t patch_index = playeble_patches[i].get_patch_index() -PATCH_INDEX_OFFSET;
            if (base_patch_value[patch_index] + num_bonus_left * incremental_value[patch_index] > curr_max) {
                if (game_logic.get_knobs(ai_int) >= playeble_patches[i].get_knobs_cost()) {
                    curr_max = base_patch_value[patch_index] + num_bonus_left * incremental_value[patch_index];
                    best_index = i;
                }
            }
        }
        return best_index;
    }

public:
    void make_move() {
        //placeholder
        if (true) {
            game_logic.spend_time_knobs(ai_int);
        }
        else {
            //placeholder
            game_logic.patch_blanket(ai_int, game_logic.get_playable_patches(ai_int)[0], 0, 0, 'n', false);
        }
    }
};


#endif

