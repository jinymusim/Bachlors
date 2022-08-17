#pragma once
#include "Value_based_AI.h"



public class Monte_carlo : public Value_based_AI{
public:
	Monte_carlo(const int ai_start_int, Game_state initial_game_state) : Value_based_AI(ai_start_int, initial_game_state) { };
    //needed because class doesn't have default constructor
    Monte_carlo& operator=(const Value_based_AI& other) {
        Value_based_AI::operator=(other);
        return *this;
    }

    virtual ~Monte_carlo() { std::cout << "Monte_carlo player desctutor" << std::endl; }

    virtual AI_responce make_move(Game_state current_game_state) {
        this->current_game_state = current_game_state;
        auto playable_patches = current_game_state.get_playable_patches();
        if (playable_patches.size() == 1) { //special patch, just put it there
            return find_best_placement(playable_patches[0], current_game_state.get_blanket(ai_int).get_blanket_map(), false);
        }
        else {
            //vector to store wins, choose best result
            std::vector<int> number_of_wins = std::vector<int>();
            //int for identification for opponent player
            auto opponent_player_int = (ai_int == 1) ? 2 : 1;
            //points
            auto current_points = current_game_state.get_actual_point_tally();
            auto ai_points = (ai_int == 1) ? current_points.first : current_points.second;
            auto opponent_points = (opponent_player_int == 1) ? current_points.first : current_points.second;


            for (size_t i = 0; i < playable_patches.size() + 1; i++) {
                //count the number of wins
                int number_of_wins_of_move = 0;
                //Generate values used in this setting             
                auto all_patches_in_order = current_game_state.get_actual_patches();
                //blanket data
                auto ai_blanket_map = current_game_state.get_blanket(ai_int).get_blanket_map();
                auto opponent_blanket = current_game_state.get_blanket(opponent_player_int);
                auto opponent_blanket_map = opponent_blanket.get_blanket_map();
                auto opponent_free_space = num_empty_space(opponent_blanket_map);
                //knobs count
                auto ai_knobs = current_game_state.get_knobs(ai_int);
                auto opponent_knobs = current_game_state.get_knobs(opponent_player_int);
                //bonus knobs count
                auto ai_bonus_knobs = current_game_state.get_blanket(ai_int).return_bonus_knobs();
                auto opponent_bonus_knobs = opponent_blanket.return_bonus_knobs();
                //time data
                auto ai_bonus_index = current_game_state.get_knob_index(ai_int);
                auto ai_time = current_game_state.get_time(ai_int);
                auto opponent_bonus_index = current_game_state.get_knob_index(opponent_player_int);
                auto opponent_time = current_game_state.get_time(opponent_player_int);

                if (i == 0) { //skip time for knobs
                    skip_time_value(ai_time, ai_bonus_index, ai_knobs, ai_points, ai_blanket_map, ai_bonus_knobs, opponent_time, true, opponent_free_space, false);
                }
                else {
                    //index of the possible patching patch
                    int index = (i - 1) % all_patches_in_order.size();
                    //if patching is possible erase the patch from this instance amd continue
                    auto result = patching_value(all_patches_in_order[index], ai_blanket_map, ai_time, ai_knobs, ai_bonus_knobs, ai_bonus_index, ai_points,
                        opponent_time, true, opponent_free_space, false);
                    if (result.success) {
                        all_patches_in_order.erase(all_patches_in_order.begin() + index);
                    }
                    else { //patch coudn't be placed, skip this patch
                        number_of_wins.push_back(-1);
                        continue;
                    }
                }

                std::vector<int> vaiable_patches = std::vector<int>(all_patches_in_order.size());
                for (int patch_pos = 0; patch_pos < all_patches_in_order.size(); patch_pos++) {
                    vaiable_patches[patch_pos] = patch_pos;
                }

                int monte_carlo_count_up = (int)ceil(MONTE_CARLO_COUNT * ((float)BASE_NUM_PATCHES / (float)all_patches_in_order.size()));

                for (int j = 0; j < monte_carlo_count_up; j++) {
                    //copy for every instance, so the tree can only pass the value by reference
                    Blanket::blanket_map ai_blanket_map_copy = ai_blanket_map;
                    Blanket::blanket_map opponent_blanket_map_copy = opponent_blanket_map;
                    std::vector<int> variable_patch_copy = vaiable_patches;

                    //make moves
                    if (i == 0) {
                        //skip time for knobs, call the algorithm, with index = -1 
                        number_of_wins_of_move += monte_carlo_algorithm(all_patches_in_order,variable_patch_copy , -1,
                            opponent_points, opponent_blanket_map_copy, opponent_free_space, opponent_time, opponent_bonus_knobs, opponent_bonus_index, opponent_knobs,
                            ai_points, ai_blanket_map_copy, ai_time, ai_bonus_knobs, ai_bonus_index, ai_knobs, true);
                    }
                    else {
                        //placed patch, no special index value
                        number_of_wins_of_move += monte_carlo_algorithm(all_patches_in_order,variable_patch_copy, (i - 1) % all_patches_in_order.size(),
                            opponent_points, opponent_blanket_map_copy, opponent_free_space, opponent_time, opponent_bonus_knobs, opponent_bonus_index, opponent_knobs,
                            ai_points, ai_blanket_map_copy, ai_time, ai_bonus_knobs, ai_bonus_index, ai_knobs, true);
                    }

                }
                number_of_wins.push_back(number_of_wins_of_move);
            }
            auto result = std::max_element(number_of_wins.begin(), number_of_wins.end());
            auto played = std::distance(number_of_wins.begin(), result);
            // get the best play
            if (played == 0) { //if it's 0 it means skip
                return AI_responce(ai_int, current_game_state.return_special_patch(), 0, 0, 'n', false, true, false);
            }
            else { //other means patching, i-1, beacuse i=0 is for skip
                return  find_best_placement(playable_patches[played - 1], current_game_state.get_blanket(ai_int).get_blanket_map(), false);
            }
        }
    }

    virtual std::string get_name() {
        return "Monte_carlo_AI ";
    }


private:

    //holder for full algorithm
    int monte_carlo_algorithm(Game_handling::patch_sequence& patches, std::vector<int>& variable_patch, int prev_index,
        int opponent_points, Blanket::blanket_map& opponent_blanket, int opponent_free_space, int opponent_time, int opponent_bonus, int opponent_bonus_index, int opponent_knobs,
        int ai_points, Blanket::blanket_map& ai_blanket, int ai_time, int ai_bonus, int ai_bonus_index, int ai_knobs, bool previous_me) {
        if (ai_time == 0 && opponent_time == 0) {
            if (ai_points != opponent_points) //who has more points
                return (ai_points > opponent_points) ? 1 : 0;
            else //same value, first with 0 is the winner (so if previous action was ai, lose)
                return (previous_me) ? 0 : 1;
        }
        else if (ai_time > opponent_time || (ai_time == opponent_time && previous_me)) { //ai on move
            //get the random action
            int selected_action = rand() % 4;
            if (selected_action != 0) { //patch placement
                for (int i = 0; i < 3; i++) { //try patches if others not possible
                    int action = (selected_action + i) % 4;
                    int index = (prev_index + action) % variable_patch.size();
                    //if patching is successful
                    auto result = patching_value(patches[variable_patch[index]], ai_blanket, ai_time, ai_knobs, ai_bonus, ai_bonus_index,
                        ai_points, opponent_time, true, opponent_free_space, false);
                    if (result.success) {
                        //erase the patch, so it couldn't be used
                        variable_patch.erase(variable_patch.begin() + index);
                        //propagate forward and back
                        return monte_carlo_algorithm(patches, variable_patch,index,
                            opponent_points, opponent_blanket, opponent_free_space, opponent_time, opponent_bonus, opponent_bonus_index, opponent_knobs,
                            ai_points, ai_blanket, ai_time, ai_bonus, ai_bonus_index, ai_knobs, true);
                    }
                }
            }
            //skip or no placement possible
            //value of skipping
            skip_time_value(ai_time, ai_bonus_index, ai_knobs, ai_points, ai_blanket, ai_bonus, opponent_time, true, opponent_free_space, false);
            //the result is propagated as parameters to next level, get it back from there
            return monte_carlo_algorithm(patches, variable_patch,prev_index,
                opponent_points, opponent_blanket, opponent_free_space, opponent_time, opponent_bonus, opponent_bonus_index, opponent_knobs,
                ai_points, ai_blanket, ai_time, ai_bonus, ai_bonus_index, ai_knobs, true);

        }
        else { //same but for opponent
            int selected_action = rand() % 4;
            if (selected_action != 0) {
                for (int i = 0; i < 3; i++) {
                    int action = (selected_action + i) % 4;
                    int index = (prev_index + action) % variable_patch.size();
                    auto result = patching_value(patches[variable_patch[index]], opponent_blanket, opponent_time, opponent_knobs, opponent_bonus, opponent_bonus_index, opponent_points,
                        ai_time, true, opponent_free_space, true);
                    if (result.success) {
                        variable_patch.erase(variable_patch.begin() + index);
                        return monte_carlo_algorithm(patches, variable_patch, index,
                            opponent_points, opponent_blanket, opponent_free_space, opponent_time, opponent_bonus, opponent_bonus_index, opponent_knobs,
                            ai_points, ai_blanket, ai_time, ai_bonus, ai_bonus_index, ai_knobs, false);
                    }
                }

            }
            skip_time_value(opponent_time, opponent_bonus_index, opponent_knobs, opponent_points, opponent_blanket, opponent_bonus,
                ai_time, true, opponent_free_space, true);
            return monte_carlo_algorithm(patches, variable_patch,prev_index,
                opponent_points, opponent_blanket, opponent_free_space, opponent_time, opponent_bonus, opponent_bonus_index, opponent_knobs,
                ai_points, ai_blanket, ai_time, ai_bonus, ai_bonus_index, ai_knobs, false);
        }
    }
};

