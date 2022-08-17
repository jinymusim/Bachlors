#ifndef GREEDY_NO_PLACE_MAN
#define GREEDY_NO_PLACE_MAN

#include "Value_based_AI.h"

public class Greedy_no_place_man : public Value_based_AI {

public:

    Greedy_no_place_man(const int ai_start_int, Game_state initial_game_state) : Value_based_AI(ai_start_int, initial_game_state) { };
    //needed because class doesn't have default constructor
    Greedy_no_place_man& operator=(const Value_based_AI& other) {
        Value_based_AI::operator=(other);
        return *this;
    }

    virtual ~Greedy_no_place_man() { std::cout << "Greedy_no_place_man player destructor" << std::endl; }

    virtual AI_responce make_move(Game_state current_game_state) {
        this->current_game_state = current_game_state;
        //not to get stuck
        auto available_patches = current_game_state.get_playable_patches();
        auto blanket_map = current_game_state.get_blanket(ai_int).get_blanket_map();
        if (available_patches.size() == 1) {
            return find_best_placement(available_patches[0], blanket_map, false);
        }
        else {
            //check if ai has knobs for patch
            auto ai_knob = current_game_state.get_knobs(ai_int);
            int max_value = std::numeric_limits<int>::min();
            //get the best patch
            int vector_index = best_playeble_index(available_patches);
            while (available_patches.size() > 0 && vector_index != -1) { //try to place patch
                auto result_patch = find_first_placable(available_patches[vector_index], blanket_map, 'n', false, false);
                if (!result_patch.success) { //if patch wasn't placed erase it and try other
                    available_patches.erase(available_patches.begin() + vector_index);
                    vector_index = best_playeble_index(available_patches);
                }
                else { //placed, return
                    return result_patch;
                }
            }

            return AI_responce(ai_int, current_game_state.return_special_patch(), 0, 0, 'n', false, true, true); //wasn't placed skip
        }

    }

    virtual std::string get_name() {
        return "Greedy_no_space_man_AI ";
    }
};


#endif