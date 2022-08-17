#ifndef VALUE_BASED_AI
#define VALUE_BASED_AI

#include "Base_AI.h"
#include <limits>
#include <iostream>

public class Value_based_AI : public Base_AI
{
public:
    Value_based_AI(const int ai_start_int, Game_state initial_game_state) : Base_AI(ai_start_int, initial_game_state) {
        base_patch_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //base, some patches can have negative value
        incremental_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //same
        patch_value(); //calculate patch value and patch increment value
    }

    //needed because class doesn't have default constructor
    Value_based_AI& operator=(const Value_based_AI& other) {
        Base_AI::operator=(other);
        base_patch_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //base, some patches can have negative value
        incremental_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //same
        patch_value(); //calculate patch value and patch increment value
        return *this;
    }

    virtual ~Value_based_AI() { std::cout << "Value based destructor" << std::endl; }


protected:
    std::vector<int> base_patch_value; //storing patch value
    std::vector<int> incremental_value;

    virtual void patch_value() {
        auto patches = initial_game_state.current_patches_in_game;
        for (auto&& patch : patches) { //go through all the matches
            int num_true = 0; //store the number of hits
            auto patch_map = patch.oriented_map('n', false); //get the patch map
            for (auto&& line : patch_map) { //go through the map and collect the hits
                for (size_t i = 0; i < line.size(); i++) {
                    if (line[i]) {
                        num_true++;
                    }
                }
            }
            base_patch_value[patch.get_patch_index() - PATCH_INDEX_OFFSET] = (num_true * 2) - patch.get_knobs_cost() - patch.get_time_cost(); //write down the numbers
            incremental_value[patch.get_patch_index() - PATCH_INDEX_OFFSET] = patch.get_bonus_knobs();
        }
    }
    //find the index in playeble pathces with highest value
    virtual int best_playeble_index(std::vector<Patch>& playeble_patches) {
        //number of bonuses left
        int num_bonus_left = (sizeof(BASE_KNOB_POS) / sizeof(BASE_KNOB_POS[0]) - current_game_state.get_knob_index(ai_int));
        //current best index (-1 a null value)
        int best_index = -1;
        //max value
        int curr_max = std::numeric_limits<int>::min();

        //go through patches and find the best
        for (size_t i = 0; i < playeble_patches.size(); i++) {
            size_t patch_index = playeble_patches[i].get_patch_index() - PATCH_INDEX_OFFSET;
            if (base_patch_value[patch_index] + num_bonus_left * incremental_value[patch_index] > curr_max) {
                if (current_game_state.get_knobs(ai_int) >= playeble_patches[i].get_knobs_cost()) {
                    curr_max = base_patch_value[patch_index] + num_bonus_left * incremental_value[patch_index];
                    best_index = i;
                }
            }
        }
        return best_index; //return value
    }

    //gets the whole value of a patch
    virtual int compute_value(int patch_index) {
        int value = base_patch_value[patch_index - 1]; //base value
        //add their incremental value
        value += incremental_value[patch_index - 1] *
            (sizeof(BASE_KNOB_POS) / sizeof(BASE_KNOB_POS[0]) - current_game_state.get_knob_index(ai_int));

        return value;
    }

    //Count the number of empty spaces on the Blanket
    virtual int num_empty_space(Blanket::blanket_map& blanket_map) {
        int empty_space = 0;
        for (int i = 0; i < BLANKET_SIZE; i++) {
            for (int j = 0; j < BLANKET_SIZE; j++) {
                if (blanket_map[i][j] == 0) {
                    empty_space++;
                }
            }
        }
        return empty_space;
    }

    //Count the minimal number of spaces that Patch need to take
    virtual int num_space_patch(Patch::patch_map& patch_map) {
        int full_space = 0;
        for (auto&& line : patch_map) {
            for (auto&& indiv_bool : line) {
                full_space = (indiv_bool) ? full_space + 1 : full_space;
            }
        }
        return full_space;
    }

    //do the incremental step in knobs and  points for player when skiping
    virtual void skip_time_value(int& skiping_player_time, int& skiping_player_bonus_index, int& skiping_player_knobs, int& skiping_player_points, Blanket::blanket_map& skip_player_blanket,
        int skiping_player_bonus, int opponent_player_time, bool space_man, int& free_space, bool consider_free_space) {
        //initial new knobs and point from the skip
        skiping_player_knobs += skiping_player_time - opponent_player_time + 1;
        skiping_player_points += skiping_player_time - opponent_player_time + 1;
        //new time
        int new_time = skiping_player_time - opponent_player_time - 1;
        //acess negative values
        if (new_time < 0) {
            //opponent time, can't be lower than 0
            skiping_player_knobs -= 1;
            skiping_player_points -= 1;
            new_time = 0;
        }
        //add bonus knobs and points
        while (skiping_player_bonus_index < (sizeof(BASE_KNOB_POS) / sizeof(BASE_KNOB_POS[0])) && new_time < BASE_KNOB_POS[skiping_player_bonus_index]) {
            skiping_player_knobs += skiping_player_bonus;
            skiping_player_points += skiping_player_bonus;
            skiping_player_bonus_index++;
        }
        //index of next free 1x1
        int special_index = 0;
        while (special_index < sizeof(BASE_SPECIAL_POS) / sizeof(BASE_SPECIAL_POS[0]) && opponent_player_time < BASE_SPECIAL_POS[special_index]) {
            special_index++;
        }
        //try if free 1x1
        if (special_index < sizeof(BASE_SPECIAL_POS) / sizeof(BASE_SPECIAL_POS[0]) && new_time < BASE_SPECIAL_POS[special_index]) {
            auto special_patch = current_game_state.return_special_patch();
            if (consider_free_space) {
                free_space--; //assuming there is always free space
            }
            else {
                auto result = (space_man) ? find_best_placement(special_patch, skip_player_blanket, true) : find_first_placable(special_patch, skip_player_blanket, 'n', false, true);
            }
            skiping_player_points += 2;
        }
        skiping_player_time = new_time;
    }

    //do the incremental step of knobs and points when patching, signal if patching possible
    virtual AI_responce patching_value(Patch& patch, Blanket::blanket_map& patching_blanket, int& patching_player_time, int& patching_player_knobs, int& patching_player_bonus, int& patching_player_bonus_index,
        int& patching_player_points, int opponent_player_time, bool space_man, int& free_space, bool opponent) {
        //not enough knobs
        if (patch.get_knobs_cost() > patching_player_knobs) {
            return AI_responce(0, current_game_state.return_special_patch(), 0, 0, 'n', false, false, false);
        }
        //the pathing wasn't posible
        bool result;
        if (opponent) {
            if (free_space < num_space_patch(patch.oriented_map('n', false))) {
                result = false;
            }
            else {
                free_space -= num_space_patch(patch.oriented_map('n', false));
                result = true;
            }
        }
        else {
            result = (space_man) ? find_best_placement(patch, patching_blanket, true).success : find_first_placable(patch, patching_blanket, 'n', false, true).success;
        }
        if (!result) { return AI_responce(0, current_game_state.return_special_patch(), 0, 0, 'n', false, false, false); }
        else { //pathcing possible, increment the player information
            patching_player_points += base_patch_value[patch.get_patch_index() - PATCH_INDEX_OFFSET] + patch.get_time_cost();
            patching_player_knobs -= patch.get_knobs_cost();
            patching_player_bonus += patch.get_bonus_knobs();
            int new_time = patching_player_time - patch.get_time_cost();
            if (new_time < 0) { new_time = 0; }

            //bonus knobs
            while (patching_player_bonus_index < (sizeof(BASE_KNOB_POS) / sizeof(BASE_KNOB_POS[0])) && new_time < BASE_KNOB_POS[patching_player_bonus_index]) {
                patching_player_knobs += patching_player_bonus;
                patching_player_points += patching_player_bonus;
                patching_player_bonus_index++;
            }
            int special_index = 0;
            //possible free 1x1 
            while (special_index < sizeof(BASE_SPECIAL_POS) / sizeof(BASE_SPECIAL_POS[0]) && opponent_player_time < BASE_SPECIAL_POS[special_index]) {
                special_index++;
            }
            if (special_index < sizeof(BASE_SPECIAL_POS) / sizeof(BASE_SPECIAL_POS[0]) && new_time < BASE_SPECIAL_POS[special_index]) {
                auto special_patch = current_game_state.return_special_patch();
                if (opponent) {
                    free_space -= 1;
                }
                else {
                    auto result_special = (space_man) ? find_best_placement(special_patch, patching_blanket, true) : find_first_placable(special_patch, patching_blanket, 'n', false, true);
                }
                patching_player_points += 2;
            }
            patching_player_time = new_time;

            return AI_responce(0, current_game_state.return_special_patch(), 0, 0, 'n', false, false, true);
        }

    }

    //places patch on first available place
    virtual AI_responce find_first_placable(Patch& patch, Blanket::blanket_map& blanket_map, const char orientation, const bool inverse, bool virtual_place) {
        //get the patch and blanket map
        auto patch_map = patch.oriented_map(orientation, inverse);

        //iterate through blanket and try to patch it
        for (size_t j = 0; j < BLANKET_SIZE; j++) {
            for (size_t k = 0; k < BLANKET_SIZE; k++) {
                bool placeable = true; //if patch is placeable on the position
                for (size_t l = 0; l < patch_map.size(); l++) {
                    for (size_t m = 0; m < patch_map[0].size(); m++) {
                        if (patch_map[l][m]) { //check if place is suitable
                            if (j + l < BLANKET_SIZE && k + m < BLANKET_SIZE) {
                                if (blanket_map[j + l][k + m] != 0) {
                                    placeable = false;
                                }
                            }
                            else {
                                placeable = false;
                            }
                        }
                    }
                }
                if (placeable) { //if placeable place it
                    //place is only virtual to the blanket_map
                    if (virtual_place) {
                        for (size_t l = 0; l < patch_map.size(); l++) {
                            for (size_t m = 0; m < patch_map[0].size(); m++) {
                                if (patch_map[l][m]) {
                                    blanket_map[j + l][k + m] = patch.get_patch_index();
                                }
                            }
                        }
                        return AI_responce(0, current_game_state.return_special_patch(), 0, 0, 'n', false, false, true);
                    }
                    return AI_responce(ai_int, patch, j, k, orientation, inverse, false, true);
                }
            }
        }
        return AI_responce(0, current_game_state.return_special_patch(), 0, 0, 'n', false, false, false); //flag fail
    }

    //Try to find 1x1 holes, if found, patch the small hole
    virtual AI_responce patch_special_hole(Patch& patch, Blanket::blanket_map& blanket_map, bool virtual_place) {
        std::vector<std::pair<int, int>> neighbors = {
                 std::make_pair(0,0), std::make_pair(-1,0), std::make_pair(0,-1), std::make_pair(1,0), std::make_pair(0,1)
        };

        //try to find holes
        for (int i = 0; i < BLANKET_SIZE; i++) {
            for (int j = 0; j < BLANKET_SIZE; j++) {
                bool corrnered = true;
                for (auto&& neigh : neighbors) {
                    //check boundry
                    int new_i = i + neigh.first;
                    int new_j = j + neigh.second;
                    if (new_i >= 0 && new_i < BLANKET_SIZE && new_j >= 0 && new_j < BLANKET_SIZE) {
                        //look if neighbor is blank
                        if (blanket_map[new_i][new_j] == 0) {
                            corrnered = false;
                        }
                    }
                }
                //corrnered hole, patch it there
                if (corrnered) {
                    //placement is only virtual
                    if (virtual_place) {
                        blanket_map[i][j] = 50;
                        return AI_responce(0, current_game_state.return_special_patch(), 0, 0, 'n', false, false, true);
                    }
                    return AI_responce(ai_int, patch, i, j, 'n', false, false, true);
                }
            }
        }
        return AI_responce(0, current_game_state.return_special_patch(), 0, 0, 'n', false, false, false); //flag fail
    }

    virtual std::string get_name() {
        return "Value_based_AI ";
    }
};

#endif