#pragma once

#include "Value_based_AI.h"

class Min_max_base : public Value_based_AI {
public:

    Min_max_base(const int ai_start_int, Game_state initial_game_state) : Value_based_AI(ai_start_int, initial_game_state) { };
    //needed because class doesn't have default constructor
    Min_max_base& operator=(const Value_based_AI& other) {
        Value_based_AI::operator=(other);
        return *this;
    }

    virtual ~Min_max_base() { std::cout << "Min_max_base player destructor" << std::endl; }

    virtual std::string get_name() {
        return "Min_max_base_AI ";
    }

protected:

    //algorithm of minimax, now without alpha beta pruning
    int min_max_alg(bool min_max, int depth_left, std::vector<Patch> patches, int prev_index,
        int opponent_points, Blanket::blanket_map& opponent_blanket, int opponent_free_place, int opponent_time, int opponent_bonus, int opponent_bonus_index, int opponent_knobs,
        int ai_points, Blanket::blanket_map& ai_blanket, int ai_time, int ai_bonus, int ai_bonus_index, int ai_knobs,
        int alpha, int beta, bool space_man, bool consider_free_space) {
        //now depth, return the difference of value
        if (depth_left == 0) {
            auto bonus_num = (sizeof(BASE_KNOB_POS) / sizeof(BASE_KNOB_POS[0]));
            if (USE_NEW_EVAL) {
                //more robust evaluation function
                return (ai_points + ai_bonus * (bonus_num - ai_bonus_index) + ai_time) -
                    (opponent_points + opponent_bonus * (bonus_num - opponent_bonus_index) + opponent_time);
            }
            return ai_points - opponent_points; //maybe look for different type of evaluation function
            //with this function, rush to quick points, but not good value
            //Different evaluating functions
        }
        //one player doesn't have time, just pass to the other player
        else if ((min_max && ai_time == 0) || (!min_max && opponent_time == 0) || (ai_time == 0 && opponent_time == 0)) {
            return min_max_alg(!min_max, depth_left - 1, patches, prev_index,
                opponent_points, opponent_blanket, opponent_free_place, opponent_time, opponent_bonus, opponent_bonus_index, opponent_knobs,
                ai_points, ai_blanket, ai_time, ai_bonus, ai_bonus_index, ai_knobs,
                alpha, beta, space_man, consider_free_space);
        }
        else { //min max
            if (ai_time > opponent_time || (ai_time == opponent_time && !min_max)) { //maximazing if my turn (more time or arrival after
                //vector of values
                std::vector<int> value_vector = std::vector<int>();
                //skip time

                //ai data copy for future use
                int skip_ai_points = ai_points;
                Blanket::blanket_map skip_ai_blanket = ai_blanket;
                int skip_ai_time = ai_time;
                //int skip_ai_bonus = ai_bonus;
                int skip_ai_bonus_index = ai_bonus_index;
                int skip_ai_knobs = ai_knobs;

                //get the incremental value of the skip
                skip_time_value(skip_ai_time, skip_ai_bonus_index, skip_ai_knobs, skip_ai_points, skip_ai_blanket,
                    ai_bonus, opponent_time, space_man, opponent_free_place, false);//can't be free space, player

                //the result value is the result of minimax subtree under this node
                auto value_of_move = min_max_alg(false, depth_left - 1, patches, prev_index,
                    opponent_points, opponent_blanket, opponent_free_place, opponent_time, opponent_bonus, opponent_bonus_index, opponent_knobs,
                    skip_ai_points, skip_ai_blanket, skip_ai_time, ai_bonus, skip_ai_bonus_index, skip_ai_knobs, alpha, beta, space_man, false); //can't be free space, player
                value_vector.push_back(value_of_move);
                //pruning based on beta value
                if (value_of_move > beta) {
                    //min has lower value, max will not affect it
                    return std::numeric_limits<int>::max();
                }
                //update new max value if possible
                if (value_of_move > alpha) {
                    alpha = value_of_move;
                }

                //skip time

                //play patches
                //all 3 posibilities
                for (int i = 0; i < 3; i++) {
                    //ai data copy for future use
                    int placement_ai_points = ai_points;
                    int placement_ai_time = ai_time;
                    Blanket::blanket_map placement_ai_blanket = ai_blanket;
                    int placement_ai_bonus = ai_bonus;
                    int placement_ai_bonus_index = ai_bonus_index;
                    int placement_ai_knobs = ai_knobs;

                    //the 3 new indexes of patches
                    int index = (prev_index + 1 + i) % patches.size();
                    auto result = patching_value(patches[index], placement_ai_blanket, placement_ai_time, placement_ai_knobs,
                        placement_ai_bonus, placement_ai_bonus_index, placement_ai_points, opponent_time, space_man, opponent_free_place, false);
                    //look if patching can ocurr
                    if (result.success) {
                        //patch sequence without played patch
                        Game_handling::patch_sequence placement_patches = patches;
                        placement_patches.erase(placement_patches.begin() + index);
                        //the result value is the result of minimax subtree under this node
                        value_of_move = min_max_alg(false, depth_left - 1, placement_patches, index,
                            opponent_points, opponent_blanket, opponent_free_place, opponent_time, opponent_bonus, opponent_bonus_index, opponent_knobs,
                            placement_ai_points, placement_ai_blanket, placement_ai_time, placement_ai_bonus, placement_ai_bonus_index, placement_ai_knobs, alpha, beta, space_man, consider_free_space);
                        value_vector.push_back(value_of_move);
                        //prunning
                        if (value_of_move > beta) {
                            return std::numeric_limits<int>::max();
                        }
                        if (value_of_move > alpha) {
                            alpha = value_of_move;
                        }
                    }
                }

                //play patches
                //the final result of this layer is the max
                return *std::max_element(value_vector.begin(), value_vector.end());

            }
            else { //same as max but with oponent value and minimazing
                std::vector<int> value_vector = std::vector<int>();
                //skip time

                int skip_opponent_points = opponent_points;
                Blanket::blanket_map skip_opponent_blanket = opponent_blanket;
                int skip_opponent_time = opponent_time;
                //int skip_ai_bonus = ai_bonus;
                int skip_opponent_bonus_index = opponent_bonus_index;
                int skip_opponent_knobs = opponent_knobs;
                int skip_opponent_empty_space = opponent_free_place;


                skip_time_value(skip_opponent_time, skip_opponent_bonus_index, skip_opponent_knobs, skip_opponent_points,
                    skip_opponent_blanket, opponent_bonus, ai_time, space_man, opponent_free_place, consider_free_space);

                auto value_of_move = min_max_alg(true, depth_left - 1, patches, prev_index,
                    skip_opponent_points, skip_opponent_blanket, skip_opponent_empty_space, skip_opponent_time, opponent_bonus, skip_opponent_bonus_index, skip_opponent_knobs,
                    ai_points, ai_blanket, ai_time, ai_bonus, ai_bonus_index, ai_knobs, alpha, beta, space_man, consider_free_space);
                value_vector.push_back(value_of_move);
                //prunning based on given alpha value
                if (value_of_move < alpha) {
                    //alrady have better than this value, can return absolute minimum
                    return std::numeric_limits<int>::min();
                }
                //update beta value if new minimum found
                if (value_of_move < beta) {
                    beta = value_of_move;
                }

                //skip time

                //play patches
                for (int i = 0; i < 3; i++) {
                    int placement_opponent_points = opponent_points;
                    int placement_opponent_time = opponent_time;
                    Blanket::blanket_map placement_opponent_blanket = opponent_blanket;
                    int placement_opponent_bonus = opponent_bonus;
                    int placement_opponent_bonus_index = opponent_bonus_index;
                    int placement_opponent_knobs = opponent_knobs;
                    int placement_opponent_empty_space = opponent_free_place;

                    int index = (prev_index + 1 + i) % patches.size();
                    auto result = patching_value(patches[index], placement_opponent_blanket, placement_opponent_time, placement_opponent_knobs,
                        placement_opponent_bonus, placement_opponent_bonus_index, placement_opponent_points, ai_time, space_man, placement_opponent_empty_space, consider_free_space);
                    if (result.success) {
                        Game_handling::patch_sequence placement_patches = patches; //errase, need of new patches
                        placement_patches.erase(placement_patches.begin() + index);
                        value_of_move = min_max_alg(true, depth_left - 1, placement_patches, index,
                            placement_opponent_points, placement_opponent_blanket, placement_opponent_empty_space, placement_opponent_time, placement_opponent_bonus, placement_opponent_bonus_index, placement_opponent_knobs,
                            ai_points, ai_blanket, ai_time, ai_bonus, ai_bonus_index, ai_knobs, alpha, beta, space_man, consider_free_space);
                        value_vector.push_back(value_of_move);
                        //prunning
                        if (value_of_move < alpha) {
                            return std::numeric_limits<int>::min();
                        }
                        if (value_of_move < beta) {
                            beta = value_of_move;
                        }
                    }
                }

                return *std::min_element(value_vector.begin(), value_vector.end());
                //play patches
            }
        }

    }


    AI_responce min_max_make_move(bool space_man, bool consider_free_space) {
        //do not try to place oponnent patches, just count the number of free spaces in his patch and compare it with size of patch
        //just 4 options
        //current points
        auto curr_points = current_game_state.get_actual_point_tally();
        //patches, that can be played
        auto playable_patches = current_game_state.get_playable_patches();
        if (playable_patches.size() == 1) { //special patch, just put it there
            return (space_man) ? find_best_placement(playable_patches[0], current_game_state.get_blanket(ai_int).get_blanket_map(), false) :
                find_first_placable(playable_patches[0], current_game_state.get_blanket(ai_int).get_blanket_map(), 'n', false, false);
        }
        else {
            //values
            std::vector<int> values = std::vector<int>();
            int alpha = std::numeric_limits<int>::min();
            int beta = std::numeric_limits<int>::max();

            for (size_t i = 0; i < playable_patches.size() + 1; i++) {
                auto all_patches_in_order = current_game_state.get_actual_patches();
                //depth of the prediction
                int PREDICTION_DEPTH = (space_man) ? PREDICTION_DETPH_SPACE : PREDICTION_DEPTH_NO_SPACE;

                //opponent data index
                int opponent_player = (ai_int == 1) ? 2 : 1;
                //blanket data
                auto ai_blanket_map = current_game_state.get_blanket(ai_int).get_blanket_map();
                auto opponent_blanket = current_game_state.get_blanket(opponent_player);
                auto opponent_blanket_map = opponent_blanket.get_blanket_map();
                auto opponent_free_place = num_empty_space(opponent_blanket_map);
                //bonus knobs data
                auto ai_bonus = current_game_state.get_blanket(ai_int).return_bonus_knobs();
                auto opponent_bonus = opponent_blanket.return_bonus_knobs();
                //time data
                auto ai_bonus_index = current_game_state.get_knob_index(ai_int);
                auto ai_time = current_game_state.get_time(ai_int);
                auto opponent_bonus_index = current_game_state.get_knob_index(opponent_player);
                auto opponent_time = current_game_state.get_time(opponent_player);
                //knobs data
                auto ai_knobs = current_game_state.get_knobs(ai_int);
                auto opponent_knobs = current_game_state.get_knobs(opponent_player);
                //points data
                auto ai_points = (ai_int == 1) ? curr_points.first : curr_points.second;
                auto opponent_points = (opponent_player == 1) ? curr_points.first : curr_points.second;






                if (i == 0) { //use of i=0 as skip value, get incremental value after skip
                    skip_time_value(ai_time, ai_bonus_index, ai_knobs, ai_points, ai_blanket_map, ai_bonus, opponent_time, space_man, opponent_free_place, false);
                    //final result is the result of subtree
                    auto value_of_move = min_max_alg(false, PREDICTION_DEPTH - 1, all_patches_in_order, -1,
                        opponent_points, opponent_blanket_map, opponent_free_place, opponent_time, opponent_bonus, opponent_bonus_index, opponent_knobs,
                        ai_points, ai_blanket_map, ai_time, ai_bonus, ai_bonus_index, ai_knobs, alpha, beta, space_man, consider_free_space);
                    values.push_back(value_of_move);
                    alpha = value_of_move;
                }
                else { //3 patching options
                    //because of use of i=0 as skip, i-1 for first 3 patches
                    int index = (i - 1) % all_patches_in_order.size();
                    //try patching
                    auto result = patching_value(all_patches_in_order[index], ai_blanket_map, ai_time, ai_knobs,
                        ai_bonus, ai_bonus_index, ai_points, opponent_time, space_man, opponent_free_place, false);
                    if (result.success) {
                        //pathches without current patch
                        Game_handling::patch_sequence placement_patches = all_patches_in_order;
                        placement_patches.erase(placement_patches.begin() + index);
                        //final result is the result of subtree
                        auto value_of_move = min_max_alg(false, PREDICTION_DEPTH - 1, placement_patches, index,
                            opponent_points, opponent_blanket_map, opponent_free_place, opponent_time, opponent_bonus, opponent_bonus_index, opponent_knobs,
                            ai_points, ai_blanket_map, ai_time, ai_bonus, ai_bonus_index, ai_knobs, alpha, beta, space_man, consider_free_space);
                        values.push_back(value_of_move);
                        alpha = (value_of_move > alpha) ? value_of_move : alpha;
                    }
                    else { //couldn't patch, value minimal for distance reasons
                        values.push_back(std::numeric_limits<int>::min());
                    }
                }
            }
            //get the best play
            auto result = std::max_element(values.begin(), values.end());
            auto played = std::distance(values.begin(), result);
            if (played == 0) { //if it's 0 it means skip
                return AI_responce(ai_int, current_game_state.return_special_patch(), 0, 0, 'n', false, true, true);
            }
            else { //other means patching, i-1, beacuse i=0 is for skip
                return (space_man) ? find_best_placement(playable_patches[played - 1], current_game_state.get_blanket(ai_int).get_blanket_map(), false) :
                    find_first_placable(playable_patches[played - 1], current_game_state.get_blanket(ai_int).get_blanket_map(), 'n', false, false);
            }
        }
    }
};

public class Min_max_no_space_man : public Min_max_base {
public:

    Min_max_no_space_man(const int ai_start_int, Game_state initial_game_state) : Min_max_base(ai_start_int, initial_game_state) { };
    //needed because class doesn't have default constructor
    Min_max_no_space_man& operator=(const Value_based_AI& other) {
        Min_max_base::operator=(other);
        return *this;
    }

    virtual ~Min_max_no_space_man() { std::cout << "Min_max_no_space_man player destructor" << std::endl; }

    virtual AI_responce make_move(Game_state current_game_state) {
        this->current_game_state = current_game_state;
        return min_max_make_move(false, false);
    }

    virtual std::string get_name() {
        return "Min_max_no_space_man_AI ";
    }
};

public class Min_max_space_man : public Min_max_base {
public:

    Min_max_space_man(const int ai_start_int, Game_state initial_game_state) : Min_max_base(ai_start_int, initial_game_state) { };
    //needed because class doesn't have default constructor
    Min_max_space_man& operator=(const Value_based_AI& other) {
        Min_max_base::operator=(other);
        return *this;
    }

    virtual ~Min_max_space_man() { std::cout << "Min_max_space_man player destructor" << std::endl; }

    virtual AI_responce make_move(Game_state current_game_state) {
        this->current_game_state = current_game_state;
        return min_max_make_move(true, false);
    }

    virtual std::string get_name() {
        return "Min_max_space_man_AI ";
    }
};

public class Min_max_free_space : public Min_max_base {
public:

    Min_max_free_space(const int ai_start_int, Game_state initial_game_state) : Min_max_base(ai_start_int, initial_game_state) { };
    //needed because class doesn't have default constructor
    Min_max_free_space& operator=(const Value_based_AI& other) {
        Min_max_base::operator=(other);
        return *this;
    }

    virtual ~Min_max_free_space() { std::cout << "Min_max_free_space player destructor" << std::endl; }

    virtual AI_responce make_move(Game_state current_game_state) {
        this->current_game_state = current_game_state;
        return min_max_make_move(true, true);
    }

    virtual std::string get_name() {
        return "Min_max_free_space_AI ";
    }
};
