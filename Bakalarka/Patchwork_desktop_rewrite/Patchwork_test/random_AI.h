#pragma once
#include "Base_AI.h"

//AI with random moves, doesn't take any strategy into question
class Random_AI : public Base_AI {
public:
	Random_AI(const int ai_start_int, Game_state initial_game_state) : Base_AI(ai_start_int, initial_game_state) {}
	Random_AI& operator=(const Base_AI& other) {
		Base_AI::operator=(other);
		return *this;
	}

	virtual ~Random_AI() { std::cout << "Random_AI desctutor" << std::endl; }

	virtual AI_responce make_move(Game_state current_state) {
		this->current_game_state = current_state;
		return get_Random_move();
	};

	virtual std::string get_name() {
		return "Random_AI ";
	}
protected:

	// Try to find random move from possible moves
	virtual AI_responce get_Random_move() {
		//until permitable move is found
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
			// get the random orientation
			char orientation = 'n';
			action = rand() % 4;
			switch (action) {
			case 0:
				orientation = 'n';
				break;
			case 1:
				orientation = 's';
				break;
			case 2:
				orientation = 'e';
				break;
			case 3:
				orientation = 'w';
				break;
			default:
				break;
			}
			//get the random inversion
			bool inverse = false;
			action = rand() % 2;
			inverse = (action == 1) ? true : false;
			auto true_patch_map = selected_patch.oriented_map(orientation, inverse);
			//get the bounded random position
			int y_axis = rand() % (BLANKET_SIZE - true_patch_map.size());
			int x_axis = rand() % (BLANKET_SIZE - true_patch_map[0].size());
			//try patching, if successfull return the move
			bool result_patch = testing_map.add_patch(true_patch_map, selected_patch.get_patch_index(), selected_patch.get_bonus_knobs(), y_axis, x_axis);
			if (result_patch) {
				return AI_responce(ai_int, selected_patch, y_axis, x_axis, orientation, inverse, false, result_patch);
			}
		}

	}

};