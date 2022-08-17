#pragma once

#include "Base_AI.h"
#include <fstream>
#include <sstream>
#include <string>

class Frequency_AI : public Base_AI {
public:
	Frequency_AI(const int ai_start_int, Game_state initial_game_state) : Base_AI(ai_start_int, initial_game_state) {
		patch_winning_frequency = std::vector<long>(BASE_NUM_PATCHES, 0);
		for (int i = 0; i < BASE_NUM_PATCHES; i++) {
			patch_winning_frequency[i] = rand() % (RANDOM_INITIAL_MAX + 1);
		}
		get_patch_frequency();
	}
	//needed because class doesn't have default constructor
	Frequency_AI& operator=(const Base_AI& other) {
		Base_AI::operator=(other);
		patch_winning_frequency = std::vector<long>(BASE_NUM_PATCHES, 0);
		for (int i = 0; i < BASE_NUM_PATCHES; i++) {
			patch_winning_frequency[i] = rand() % (RANDOM_INITIAL_MAX + 1);
		}
		get_patch_frequency();
		return *this;
	}

	virtual ~Frequency_AI() { std::cout << "Frequency_AI desctutor" << std::endl; }

	virtual AI_responce make_move(Game_state current_state) {
		this->current_game_state = current_state;

		auto playable = current_game_state.get_playable_patches();
		//deal with special patch
		if (playable.size() == 1 && playable[0].get_knobs_cost() == 0) {
			return find_best_placement(playable[0], current_game_state.get_blanket(ai_int).get_blanket_map(), false);
		}
		//erase patches that we can't use
		int i = 0;
		while (i < (int)playable.size()) {
			if (playable[i].get_knobs_cost() > current_game_state.get_knobs(ai_int)) {
				playable.erase(playable.begin() + i);
				i--;
			}
			i++;
		}
		//if patches left find one with highest propability and try to use it
		while (playable.size() > 0) {
			int best_index = get_best_index(playable);
			auto result = find_best_placement(playable[best_index], current_game_state.get_blanket(ai_int).get_blanket_map(), false);
			//placement was successfull return with this patch
			if (result.success) {
				return result;
			}
			//wasn't, remove it
			playable.erase(playable.begin() + best_index);
		}
		//no more patches, skip
		return AI_responce(ai_int, current_game_state.return_special_patch(), 0, 0, 'n', false, true, true);

	};

	virtual std::string get_name() {
		return "Frequency_AI ";
	}

protected:
	std::vector<long> patch_winning_frequency;

	//get the position of patch with highest winning frequency
	virtual int get_best_index(std::vector<Patch>& playable_patches) {
		int best_frequency = -1;
		int best_index = -1;
		for (size_t i = 0; i < playable_patches.size(); i++) {
			if (patch_winning_frequency[playable_patches[i].get_patch_index() - PATCH_INDEX_OFFSET] > best_frequency) {
				best_frequency = patch_winning_frequency[playable_patches[i].get_patch_index() - PATCH_INDEX_OFFSET];
				best_index = i;
			}
		}
		return best_index;
	}

	//Load the number of wins for each patch from past games
	virtual void get_patch_frequency() {
		std::ifstream file(SAVE_FILE);
		std::string line;
		while (std::getline(file, line)) {
			bool is_start = true;
			for (auto&& line_char : line) {
				if (!isdigit(line_char)) {
					is_start = false;
				}
			}
			if (is_start) {
				//read winner
				std::getline(file, line);
				int winning_int = (line == "Player1 won") ? 1 : 2;
				//read used patches
				std::getline(file, line);
				//read player1 name
				std::getline(file, line);
				//read player 1 points
				std::getline(file, line);
				//read the first player board and player 2 name and points
				if (winning_int == 2) {
					//read player 1 blanket
					for (int i = 0; i < BLANKET_SIZE; i++) {
						std::getline(file, line);
					}
					//read player 2 name
					std::getline(file, line);
					//read player 2 points;
					std::getline(file, line);
				}
				//look if patch in winning board
				std::vector<int> is_patch_winning = std::vector<int>(BASE_NUM_PATCHES, 0);
				for (int i = 0; i < BLANKET_SIZE; i++) {
					//get the line of Blanket
					std::getline(file, line);
					std::stringstream patches_line = std::stringstream(line);
					std::string line_split;
					//look at individual numbers
					while (std::getline(patches_line, line_split, ',')) {
						if (!line_split.empty()) {
							int patch_index = std::stoi(line_split);
							if (patch_index != 0 && patch_index != 50) {
								//mark the patch as present
								is_patch_winning[patch_index - PATCH_INDEX_OFFSET] = 1;
							}
						}
					}

				}
				//increment the present patches
				for (int i = 0; i < BASE_NUM_PATCHES; i++) {
					patch_winning_frequency[i] += is_patch_winning[i];
				}
			}
		}
	}
};