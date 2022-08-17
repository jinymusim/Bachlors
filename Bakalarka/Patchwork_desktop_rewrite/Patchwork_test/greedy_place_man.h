#pragma once
#include "Value_based_AI.h"

public class Greedy_place_man : public Value_based_AI {

public:

    Greedy_place_man(const int ai_start_int, Game_state initial_game_state) : Value_based_AI(ai_start_int, initial_game_state) { };
    //needed because class doesn't have default constructor
    Greedy_place_man& operator=(const Value_based_AI& other) {
        Value_based_AI::operator=(other);
        return *this;
    }

    virtual ~Greedy_place_man() { std::cout << "Greedy_place_man player destructor" << std::endl; }

    virtual AI_responce make_move(Game_state current_game_state) {
        this->current_game_state = current_game_state;
        auto available_patches = current_game_state.get_playable_patches();
        auto blanket_map = current_game_state.get_blanket(ai_int).get_blanket_map();
        if (available_patches.size() == 1) {
            return find_best_placement(available_patches[0], blanket_map, false);
        }
        int vector_index = best_playeble_index(available_patches);
        while (available_patches.size() > 0 && vector_index != -1) {
            auto result = find_best_placement(available_patches[vector_index], blanket_map, false);
            if (!result.success) { //if patch wasn't placed erase it and try other
                available_patches.erase(available_patches.begin() + vector_index);
                vector_index = best_playeble_index(available_patches);
            }
            else { //placed, return
                return result;
            }
        }
        return AI_responce(ai_int, current_game_state.return_special_patch(), 0, 0, 'n', false, true, true); //wasn't placed skip
    }

    virtual std::string get_name() {
        return "Greedy_space_man_AI ";
    }
};
