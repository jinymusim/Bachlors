#pragma once
#include "Value_based_AI.h"

//Just move selection is random, placement is the greedy best
class Just_random_select_ai : public Value_based_AI {
public:
    Just_random_select_ai(const int ai_start_int, Game_state initial_game_state) : Value_based_AI(ai_start_int, initial_game_state) {
        base_patch_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //base, some patches can have negative value
        incremental_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //same
        patch_value(); //calculate patch value and patch increment value
    }

    //needed because class doesn't have default constructor
    Just_random_select_ai& operator=(const Value_based_AI& other) {
        Base_AI::operator=(other);
        base_patch_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //base, some patches can have negative value
        incremental_value = std::vector<int>(BASE_NUM_PATCHES, std::numeric_limits<int>::min()); //same
        patch_value(); //calculate patch value and patch increment value
        return *this;
    }

    virtual ~Just_random_select_ai() { std::cout << "Just_random_select_ai player destructor" << std::endl; }

    virtual AI_responce make_move(Game_state current_game_state) {
        this->current_game_state = current_game_state;
		while (true) {
			//get blanket to test the move on
			Blanket testing_map(current_game_state.get_blanket(ai_int));
			//get the action to play
			int action = rand() % (1 + current_game_state.get_playable_patches().size());
			//if special patching is needed it takes over 
			if (current_game_state.get_actual_patches().size() == 1)
				action = 1;
			Patch selected_patch = current_game_state.return_special_patch();
			//get the action based on random
			switch (action) {
				//if 0 or some bad number, just skip
			case 0:
				return AI_responce(ai_int, current_game_state.return_special_patch(), 0, 0, 'n', false, true, true);
			case 1:
			case 2:
			case 3:
				selected_patch = current_game_state.get_playable_patches()[action - 1];
				break;
			default:
				return AI_responce(ai_int, current_game_state.return_special_patch(), 0, 0, 'n', false, true, true);
			}

			auto patch_result = find_best_placement(selected_patch, testing_map.get_blanket_map(), false);
			if (patch_result.success)
				return patch_result;
		}
    }
	virtual std::string get_name() {
		return "Just_random_select_AI ";
	}
};
