#ifndef BLANKET
#define BLANKET

#include <vector>
#include <utility>
#include "constants.h"

class Blanket { //blanket to keep player patch progresion
public:
	using blanket_map = std::vector<std::vector<int>>;
	using patch_map = std::vector<std::vector<bool>>;

	//Initialization just empty blanket with set size
	Blanket() {
		map = blanket_map();
		for (int i = 0; i < BLANKET_SIZE; i++) {
			map.push_back(std::vector<int>(BLANKET_SIZE, 0));
		}
		sum_bonus_knobs = 0;
	}

	blanket_map get_blanket_map() {
		return map;
	}

	int return_bonus_knobs() {
		return sum_bonus_knobs;
	}


	//return current num of knobs
	int return_num_blank_spaces() {
		int num_blank = 0;
		for (size_t i = 0; i < map.size(); i++) {
			for (size_t j = 0; j < map[0].size(); j++) {
				if (map[i][j] == 0) { num_blank += 1; }
			}
		}
		return num_blank;
	}

	//not very effective, but does the work
	//TODO: Replace this code with something more effective
	int blanket_7x7() {
		//where the 7x7 can start
		std::vector<std::pair<int, int>> possible_starts =
		{
			std::make_pair(0,0), std::make_pair(1,0), std::make_pair(0,1), std::make_pair(1,1),
			std::make_pair(2,0), std::make_pair(0,2), std::make_pair(2,1), std::make_pair(1,2), std::make_pair(2,2)
		};
		int size_query = 7;
		size_t start_index = 0;
		int i = 0;
		int j = 0;
		//check the blanket
		while (i < size_query) {
			while (j < size_query) {
				if (map[i + possible_starts[start_index].first][j + possible_starts[start_index].second] == 0) { //is zero, hole, go to next start
					i = 0;
					j = 0;
					if (start_index < possible_starts.size() - 1) {
						start_index += 1;
					}
					else { //no other starts, return 0
						return 0;
					}
				}
				else {
					j++;
				}
			}
			i++;
		} //no hole, return 1
		return 1;
	}

	//add patch to requested position, return bool of succeding (use patch_map, because of rotation)
	bool add_patch(const patch_map& map_patch, int patch_index, int bonus_knobs, int y_pos_new, int x_pos_new) {
		blanket_map new_map = map; //adding may not be successfull
		//go through patch and lock for conflicts
		for (size_t i = 0; i < map_patch.size(); i++) {
			for (size_t j = 0; j < map_patch[0].size(); j++) {
				//sizes are based on positive hits, meaning even tho some negative hit will trigger this,
				//some positive hit would have triggerd this in future
				if ((i + y_pos_new >= BLANKET_SIZE) || (j + x_pos_new >= BLANKET_SIZE)) { //out of position, false
					return false;
				}
				else if (map_patch[i][j] && map[i + y_pos_new][j + x_pos_new] > 0) { //conflict, can't add, false
					return false;
				}
				else { //add proper index to position to differentiate patches
					int temp = 0;
					if (map_patch[i][j]) {
						temp = patch_index;
					}
					new_map[i + y_pos_new][j + x_pos_new] = map[i + y_pos_new][j + x_pos_new] + temp;

				}
			}
		}
		//all successfull, set it as new blanket
		map = new_map;
		sum_bonus_knobs += bonus_knobs; //add bonus knobs to tally
		return true;
	}

private:

	blanket_map map;
	int sum_bonus_knobs;
};

#endif
