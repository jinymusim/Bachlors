#ifndef GAME_HANDLING
#define GAME_HANDLING

#include "Game_state.h"
#include "AI_responce.h"
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>



class Game_handling {
public:

	using patch_sequence = std::vector<Patch>;

	//no seed is given, generate it 
	Game_handling() {
		//generate random seed
		std::random_device r;
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(1);
		seed = uniform_dist(e1);
		//create players and blankets
		player1 = Player(true, BASE_TIME);
		player2 = Player(false, BASE_TIME);
		player1_blanket = Blanket();
		player2_blanket = Blanket();
		added_now = false;
		//create all patches
		create_patches();
	}

	Game_handling(int first, std::size_t seed) : seed(seed) {
		//based on who is first, create players with proper atributes

		switch (first)
		{
		case 1:
			player1 = Player(true, BASE_TIME);
			player2 = Player(false, BASE_TIME);
			break;
		case 2:
			player1 = Player(false, BASE_TIME);
			player2 = Player(true, BASE_TIME);
			break;
		}

		//empty game space
		player1_blanket = Blanket();
		player2_blanket = Blanket();
		//create all patches
		create_patches();

	};

	//who should play, based on time and free 1x1 patch
	bool whos_turn() {
		if (player1.time > player2.time) {
			if (free_1x1_patch(2)) { return false; }
			return true;
		}
		else if (player1.time < player2.time) {
			if (free_1x1_patch(1)) { return true; }
			return false;
		}
		else if (player1.first == false) { return true; }
		else { return false; }
	};

	bool game_end() {
		return (player1.time == 0 && player2.time == 0);
	}

	//get the number of knobs from requested player
	int get_knobs(int player_ID) {
		switch (player_ID)
		{
		case 1:
			return player1.knobs;
		case 2:
			return player2.knobs;
		}
		return -1;
	}

	//get the remaining time from requested player
	int get_time(int player_ID) {
		switch (player_ID)
		{
		case 1:
			return player1.time;
		case 2:
			return player2.time;
		}
		return -1;
	}

	int get_knob_index(int player_ID) {
		switch (player_ID)
		{
		case 1:
			return player1.knob_index;
		case 2:
			return player2.knob_index;
		}
		return -1;
	}

	//return game seed
	int get_game_seed() {
		return seed;
	}

	//return the blanker of given player
	Blanket& get_blanket(int player_ID) {
		switch (player_ID)
		{
		case 1:
			return player1_blanket;
		case 2:
			return player2_blanket;
		}
	}

	//reset added flag
	void set_added_to_zero() {
		added_now = 0;
	}

	//get the added flag
	int added_curr_val() {
		return added_now;
	}

	//return score standing
	std::pair<int, int> get_actual_point_tally() {
		return std::make_pair(player1.knobs - 2 * player1_blanket.return_num_blank_spaces() + 7 * player1_blanket.blanket_7x7(),
			player2.knobs - 2 * player2_blanket.return_num_blank_spaces() + 7 * player2_blanket.blanket_7x7());
	}

	//Execute the action skip for given player
	bool spend_time_knobs(int player) {
		//game ended, can't spend time
		if (game_end()) {
			return false;
		}
		//is the player on the move
		bool proper_move = false;
		switch (player)
		{
		case 1:
			proper_move = whos_turn(); //whos_turn have true for player1 and false for player2
			break;
		case 2:
			proper_move = !whos_turn();
			break;
		}
		if (proper_move) {
			Player* first_player = &player1;
			Player* other_player = &player1;
			switch (player) //from player1 to player2 or the other way around
			{
			case 1:
				first_player = &player1;
				other_player = &player2;
				break;
			case 2:
				first_player = &player2;
				other_player = &player1;
				break;
			}
			//player with 1x1 free is on the move, but can't use this action
			if (first_player->time < other_player->time) {
				return false;
			}
			int new_time = other_player->time - 1; //player should move 1 space behind the other player
			if (new_time < 0) { new_time = 0; } //but player can't move to negative  
			bool is_first = !(new_time == other_player->time); //whos is first on the space (for 0)
			first_player->knobs += first_player->time - new_time; //the added knobs are the difference in time
			first_player->time = new_time; //update time and first
			first_player->first = is_first;
			add_player_bonus_knobs(player);
			return true; //move was successfully done
		}
		return false; //move wasn't proper, couldn't be done
	}

	//Execute the action of patching for given player
	bool patch_blanket(int player, Patch selected_patch, int y_pos_new, int x_pos_new, char rotation, bool inversion_bool) {
		//game ended, don't accept input
		if (game_end()) {
			return false;
		}
		//special blanket, special patch
		if (selected_patch.get_map() == special_patch.get_map()) {
			return patch_special(player, y_pos_new, x_pos_new);
		}
		else {
			//is the player on the move
			//check if blanket not far away
			bool proper_move = false;
			switch (player)
			{
			case 1:
				proper_move = whos_turn() && is_patch_proper(selected_patch.get_patch_index()); //whos_turn have true for player1 and false for player2
				break;
			case 2:
				proper_move = !whos_turn() && is_patch_proper(selected_patch.get_patch_index());
				break;
			}
			if (proper_move) {
				Player* first_palyer = &player1;
				Player* other_player = &player1;
				Blanket* adding_blanket = &player1_blanket;
				switch (player) //player1 turn or player2 turn, player2 needed for who is first, decide blanket
				{
				case 1:
					first_palyer = &player1;
					other_player = &player2;
					adding_blanket = &player1_blanket;
					break;
				case 2:
					first_palyer = &player2;
					other_player = &player1;
					adding_blanket = &player2_blanket;
					break;
				}
				if (selected_patch.get_knobs_cost() <= first_palyer->knobs) //does player have knobs to buy patch
				{
					auto map_patch = selected_patch.oriented_map(rotation, inversion_bool); //the patch map based on rotation
					bool successfull_add = adding_blanket->add_patch(map_patch, selected_patch.get_patch_index(),
						selected_patch.get_bonus_knobs(), y_pos_new, x_pos_new); //try adding(have enough knobs)
					if (successfull_add) { //if successfull deduct costs
						first_palyer->knobs -= selected_patch.get_knobs_cost();
						first_palyer->time -= selected_patch.get_time_cost();
						if (first_palyer->time < 0) { first_palyer->time = 0; }
						first_palyer->first = !(first_palyer->time == other_player->time);
						add_player_bonus_knobs(player);
						update_patch_index_add_patch_to_used(selected_patch.get_patch_index());
						return true;
					}
				}
			}
			return false;
		}
	}

	//return the patches in order from curr_index
	patch_sequence get_actual_patches() {
		patch_sequence ordered_patch = patch_sequence();
		int temp_index = 0;
		for (size_t i = 0; i < BASE_NUM_PATCHES - used_patches.size(); i++) {
			temp_index = (curr_patch_index + i) % (BASE_NUM_PATCHES - used_patches.size());
			ordered_patch.push_back(unused_patches[temp_index]);
		}
		return ordered_patch;
	}

	//return all patches playeble by player
	patch_sequence get_playable_patches(int player) {
		patch_sequence ordered_patch = patch_sequence();
		if (free_1x1_patch(player)) { //free 1x1 need to be placed
			ordered_patch.push_back(special_patch);
		}
		else { //only the 3 patches infront can be placed
			size_t i = 0;
			int temp_index = 0;
			while (i < 3 && i < unused_patches.size()) {
				temp_index = (curr_patch_index + i) % (BASE_NUM_PATCHES - used_patches.size());
				ordered_patch.push_back(unused_patches[temp_index]);
				i++;
			}
		}
		return ordered_patch;
	}

	// Return all the played patches
	patch_sequence get_played_patches_in_order() {
		return used_patches;
	}

	// Get the times, when the bonus patch is given out
	std::vector<int> get_special_patch_pos() {
		return special_patch_pos;
	}

	// Flag if given player will be given the special patch bonus
	bool free_1x1_patch(int player) {
		Player* player_query = &player1;
		switch (player)
		{
		case 1:
			player_query = &player1;
			break;
		case 2:
			player_query = &player2;
			break;
		}
		if (special_patch_pos.size() > 0) { //some special patches must still be there for query
			return player_query->time < special_patch_pos[0]; //time must be less then the max time
		}
		return false;
	}

	// Return the special patch
	Patch return_special_patch() {
		return special_patch;
	}

	// Generate the current gamestate from the view of given player
	Game_state current_game_state(int player) {
		return Game_state(Player(player1), Player(player2), Blanket(player1_blanket), Blanket(player2_blanket),
			this->get_actual_patches(), this->get_playable_patches(player), this->return_special_patch());
	}

	// Flag who is winning the game
	bool who_won() {
		auto&& point_taly = get_actual_point_tally();
		if (point_taly.first > point_taly.second)
			return true;
		else if (point_taly.first < point_taly.second)
			return false;
		else if (player1.first)
			return true;
		else
			return false;
	}

	// Evaluate the requested action from AI
	bool compact_action_evaluation(AI_responce compact_responce) {
		if (compact_responce.skip)
			return spend_time_knobs(compact_responce.ai_int);
		else {
			return patch_blanket(compact_responce.ai_int, compact_responce.selected_patch,
				compact_responce.y_pos, compact_responce.x_pos, compact_responce.rotation, compact_responce.inversion);
		}
	}


private:

	patch_sequence unused_patches;
	patch_sequence used_patches;
	Player player1;
	Player player2;
	Blanket player1_blanket;
	Blanket player2_blanket;
	int seed;
	int curr_patch_index;
	int added_now;

	std::vector<int> special_patch_pos;
	Patch special_patch;

	//is selected patch proper?
	bool is_patch_proper(int patch_index) {
		int temp_index = 0;
		for (int i = 0; i < 3; i++) { //try find it
			temp_index = (curr_patch_index + i) % (BASE_NUM_PATCHES - used_patches.size());
			if (unused_patches[temp_index].get_patch_index() == patch_index) {
				return true; //found 
			}
		}
		return false; //not found
	}

	//update the index based on selected patch, add it to used
	void update_patch_index_add_patch_to_used(int patch_index) {
		int temp_index = 0;
		for (int i = 0; i < 3; i++) { //find the patch
			temp_index = (curr_patch_index + i) % (BASE_NUM_PATCHES - used_patches.size());
			if (unused_patches[temp_index].get_patch_index() == patch_index) {
				curr_patch_index = temp_index % (BASE_NUM_PATCHES - used_patches.size() - 1); //update the index,1 is yet to be removed
				used_patches.push_back(unused_patches[temp_index]); //add it to used
				unused_patches.erase(unused_patches.begin() + temp_index); //remove it from unused
				break;
			}
		}
	}

	// Create the patches that will be played with
	void create_patches() {
		curr_patch_index = 0; //set it to the one who has 0

		auto patch_random = std::default_random_engine(seed); //create randomnes based on seed
		unused_patches = patch_sequence(); //vector for pacthes
		used_patches = patch_sequence();

		std::ifstream file(BASE_FILENAME); //ifstream from file
		std::string line;

		std::string line_segment;

		int j = 0; //num of lines of the patch in file
		int time = 0;
		int knobs = 0;
		int bonus_knobs = 0;

		for (int i = 1; i <= BASE_NUM_PATCHES; i++) { //for all patches
			std::getline(file, line); //read the header with information about patch
			std::stringstream temp(line); //process the information into chunks
			std::getline(temp, line_segment, ',');
			j = std::stoi(line_segment);
			std::getline(temp, line_segment, ',');
			time = std::stoi(line_segment);
			std::getline(temp, line_segment, ',');
			knobs = std::stoi(line_segment);
			std::getline(temp, line_segment, ',');
			bonus_knobs = std::stoi(line_segment);

			std::vector<std::vector<bool>> temp_map{};
			for (int k = 0; k < j; k++) { //read the patch itself
				std::vector<bool> temp_vector{};
				std::getline(file, line); //line by line, X is true, 0 is false
				for (auto&& x : line) {
					if (x == 'X') {
						temp_vector.push_back(true);
					}
					else {
						temp_vector.push_back(false);
					}
				}
				temp_map.push_back(temp_vector); //push back the created vector
			}
			unused_patches.push_back(Patch(temp_map, time, knobs, bonus_knobs, i)); //create the patch with the information
		}

		std::shuffle(unused_patches.begin(), unused_patches.end(), patch_random); //with the random shuffle the patches

		for (size_t i = 0; i < unused_patches.size(); i++) { //find base patch to have base curr_index for grabing patches
			if (unused_patches[i].get_patch_index() == 1) {
				curr_patch_index = i;
				break;
			}
		}

		std::vector<std::vector<bool>> temp_map = { //create special 1x1 patch
			{true}
		};
		special_patch = Patch(temp_map, 0, 0, 0, 50);
		special_patch_pos = std::vector<int>(std::begin(BASE_SPECIAL_POS), std::end(BASE_SPECIAL_POS));

	}

	// Special form of patching with special patch
	bool patch_special(int player, int y_pos_new, int x_pos_new) { //patch using 1x1

		if (free_1x1_patch(player)) { //is this action permisible
			Player* player_query = &player1; //select proper player and blanket
			Blanket* patch_blanket = &player1_blanket;
			switch (player)
			{
			case 1:
				player_query = &player1;
				patch_blanket = &player1_blanket;
				break;
			case 2:
				player_query = &player2;
				patch_blanket = &player2_blanket;
			}
			auto succ = patch_blanket->add_patch(special_patch.get_map(), special_patch.get_patch_index(),
				special_patch.get_bonus_knobs(), y_pos_new, x_pos_new); //patch the blanket
			if (succ) {
				special_patch_pos.erase(special_patch_pos.begin()); //erase the time
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}

	//add bonus knobs to player
	void add_player_bonus_knobs(int player) {
		Player* player_query = &player1;
		Blanket* player_blanket = &player1_blanket;
		switch (player) //get the player blanket and information
		{
		case 1:
			player_query = &player1;
			player_blanket = &player1_blanket;
			break;
		case 2:
			player_query = &player2;
			player_blanket = &player2_blanket;
			break;
		}
		//find if player can get bonus knobs
		while (player_query->knob_index < sizeof(BASE_KNOB_POS) / sizeof(BASE_KNOB_POS[0]) && player_query->time < BASE_KNOB_POS[player_query->knob_index]) {
			player_query->knobs += player_blanket->return_bonus_knobs(); //yes, add bonus knobs and increse index
			player_query->knob_index += 1;
			added_now = player;
		}
	}
};
#endif 
