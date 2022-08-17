#ifndef PATCH
#define PATCH

#include <vector>
#include <utility>


/* Class representing the Patch that should be placed on Blanket
*
*/
class Patch {
public:
	// Alias for the True positions of the Patch in rectangular matrix
	using patch_map = std::vector<std::vector<bool>>;

	// Base constructor
	Patch() : cost_time(0), cost_knobs(0), bonus_knobs(0), map(), patch_index(0) {};

	// Constructor with specific values
	Patch(patch_map map, int cost_time, int cost_knobs, int bonus_knobs, int patch_index) :
		cost_time(cost_time), cost_knobs(cost_knobs), bonus_knobs(bonus_knobs), map(std::move(map)), patch_index(patch_index) {}



	//Get the matrix with Patch position after specific orientation
	patch_map oriented_map(const char& orientation, const bool inversion_bool) {
		patch_map new_map = map;
		switch (orientation)
		{
		case 'n': //base map orientation
		{

			for (size_t i = 0; i < map.size(); i++) {
				new_map[i] = map[i]; //copy cols
			}
			break;
		}
		case 's': //south orientation, reverse both individual col and whole patch
		{

			for (size_t i = 0; i < map.size(); i++) {
				new_map[i] = map[i]; //copy cols
				std::reverse(new_map[i].begin(), new_map[i].end()); //reverse cols
			}
			std::reverse(new_map.begin(), new_map.end()); //reverse map
			break;

		}
		case 'e': //to side, row is now colm, and sizes are fliped
		{
			new_map = patch_map(); //new map

			for (size_t i = 0; i < map[0].size(); i++) { //add cols, but fliped size
				std::vector<bool> temp(map.size(), false); //proper size of cols
				for (size_t j = 0; j < map.size(); j++) {
					temp[j] = map[j][i]; //add the proper positions
				}
				new_map.push_back(std::move(temp));
			}
			std::reverse(new_map.begin(), new_map.end()); //reverse because first row is now last col, but added first
			break;


		}
		case 'w'://similer to previous just adding the position to the back of a col
		{
			new_map = patch_map();

			for (size_t i = 0; i < map[0].size(); i++) { //fliped sizes
				std::vector<bool> temp(map.size(), false);
				for (size_t j = 0; j < map.size(); j++) {
					temp[(temp.size() - 1) - j] = map[j][i]; //(0,0) is now (0,back), so add from the back
				}
				new_map.push_back(std::move(temp)); //no need to invert, first row is first col
			}
			break;

		}
		}
		if (inversion_bool) {
			std::reverse(new_map.begin(), new_map.end());
		}
		return new_map;
	}

	int get_patch_index() {
		return patch_index;
	}

	int get_time_cost() {
		return cost_time;
	}

	int get_knobs_cost() {
		return cost_knobs;
	}

	int get_bonus_knobs() {
		return bonus_knobs;
	}

	patch_map get_map() {
		return map;
	}

private:
	patch_map map;
	int cost_time;
	int cost_knobs;
	int bonus_knobs;
	int patch_index;
};

#endif 