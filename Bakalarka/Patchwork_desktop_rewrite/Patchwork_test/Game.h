#pragma once

#include "Game_handling.h"
#include "greedy_no_place_man.h"
#include "greedy_place_man.h"
#include "min_max_algs.h"
#include "monte_carlo.h"
#include "random_AI.h"
#include "just_random_select_ai.h"
#include "frequency_ai.h"

//base save file


class Game {
public:
	//get initial state
	Game() : game_logic{}{
		this->computer_AI_player1 = std::make_unique<Base_AI>(Base_AI(1, this->game_logic.current_game_state(1)));
		this->computer_AI_player2 = std::make_unique<Base_AI>(Base_AI(2, this->game_logic.current_game_state(2)));
		setup_save_file();
		active_AI_player1 = false;
		active_AI_player2 = false;
	};
	//needed because AI doesn't have default constructor
	Game(const Game& other) : game_logic(other.game_logic){
		this->computer_AI_player1 = std::make_unique<Base_AI>(Base_AI(1, this->game_logic.current_game_state(1)));
		this->computer_AI_player2 = std::make_unique<Base_AI>(Base_AI(2, this->game_logic.current_game_state(2)));
		setup_save_file();
		active_AI_player1 = other.active_AI_player1;
		active_AI_player2 = other.active_AI_player2;
	}

	void setup_save_file() {
		std::ifstream file(SAVE_FILE);
		if (!file.good()) {
			std::ofstream save_file(SAVE_FILE);
		}
	};

	void new_game() {
		this->game_logic = Game_handling();
	}

	void save_game() {
		//get file and open with append
		std::ofstream out;
		out.open(SAVE_FILE, std::ios::app);
		std::string out_line;
		//get the seed and write it 
		out_line = std::to_string(game_logic.get_game_seed());
		out << out_line << std::endl;

		//write down who won
		out << ((game_logic.who_won()) ? "Player1 won" : "Player2 won") << std::endl;
		//write down the used patch order
		out_line = "";
		auto temp_vector = game_logic.get_played_patches_in_order();
		for (int i = 0; i < ((int)temp_vector.size()); i++) { //int to prevent uderflow
			out_line += std::to_string(temp_vector[i].get_patch_index());
			out_line += ",";
		}

		out << out_line << std::endl;;
		//write down player name
		out << ((active_AI_player1) ? computer_AI_player1->get_name() : "") + "Player1" << std::endl;

		out_line = "";
		//write down the points and individual blankets
		auto score = game_logic.get_actual_point_tally();
		out_line = std::to_string(score.first) + 'p';
		out << out_line << std::endl;;

		//write down blanket
		auto blanket_player1 = game_logic.get_blanket(1).get_blanket_map();
		for (size_t i = 0; i < BLANKET_SIZE; i++) {
			out_line = "";
			for (size_t j = 0; j < BLANKET_SIZE; j++) { //at least BLANKSIZE, which is positive num
				if (blanket_player1[i][j] < 10) {
					out_line += " " + std::to_string(blanket_player1[i][j]);
					out_line += ",";
				}
				else {
					out_line += std::to_string(blanket_player1[i][j]);
					out_line += ",";
				}			
			}
			out << out_line << std::endl;
		}
		//write down player name
		out << ((active_AI_player2) ? computer_AI_player2->get_name() : "") + "Player2" << std::endl;

		out_line = "";
		//write down the other score and blanket
		out_line = std::to_string(score.second) + 'p';
		out << out_line << std::endl;
		//write down blanket
		auto blanket_player2 = game_logic.get_blanket(2).get_blanket_map();
		for (size_t i = 0; i < BLANKET_SIZE; i++) {
			out_line = "";
			for (size_t j = 0; j < BLANKET_SIZE; j++) {
				if (blanket_player2[i][j] < 10) {
					out_line += " " + std::to_string(blanket_player2[i][j]);
					out_line += ",";
				}
				else {
					out_line += std::to_string(blanket_player2[i][j]);
					out_line += ",";
				}
			}
			out << out_line << std::endl;
		}

	};

	//find all seed
	std::vector<std::string> get_save_game_seeds() {
		std::ifstream file(SAVE_FILE);
		std::string line;
		std::vector<std::string> seed_vector = std::vector<std::string>();
		//go thourgh all the lines
		while (std::getline(file, line)) {
			bool add = true;
			//chceck the line by char
			for (auto&& line_char : line) {
				if (!isdigit(line_char)) { //if some char is not digit, can't be seed
					add = false;
				}
			}
			if (add && line != "") { //if no problems were found add to seed vector
				seed_vector.push_back(line);
			}

		}
		return seed_vector;
	};
	//create new game_logic based on given seed
	void load_seed(std::string seed) {
		size_t seed_int = std::stoi(seed);
		game_logic = Game_handling(1, seed_int);
	};

	void set_AI(AI_type type_of_AI, int AI_int) {
		switch (type_of_AI)
		{
		case greedy_no_space_man:
			if(AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Greedy_no_place_man>(Greedy_no_place_man(1, this->game_logic.current_game_state(1)));
			else if(AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Greedy_no_place_man>(Greedy_no_place_man(2, this->game_logic.current_game_state(2)));
			break;
		case greedy_space_man:
			if (AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Greedy_place_man>(Greedy_place_man(1, this->game_logic.current_game_state(1)));
			else if (AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Greedy_place_man>(Greedy_place_man(2, this->game_logic.current_game_state(2)));
			break;
		case min_max_no_space_man:
			if (AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Min_max_no_space_man>(Min_max_no_space_man(1, this->game_logic.current_game_state(1)));
			else if (AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Min_max_no_space_man>(Min_max_no_space_man(2, this->game_logic.current_game_state(2)));
			break;
		case min_max_space_man:
			if (AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Min_max_space_man>(Min_max_space_man(1, this->game_logic.current_game_state(1)));
			else if (AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Min_max_space_man>(Min_max_space_man(2, this->game_logic.current_game_state(2)));
			break;
		case min_max_free_space:
			if (AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Min_max_free_space>(Min_max_free_space(1, this->game_logic.current_game_state(1)));
			else if (AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Min_max_free_space>(Min_max_free_space(2, this->game_logic.current_game_state(2)));
			break;
		case monte_carlo_free_space:
			if (AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Monte_carlo>(Monte_carlo(1, this->game_logic.current_game_state(1)));
			else if (AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Monte_carlo>(Monte_carlo(2, this->game_logic.current_game_state(2)));
			break;
		case random_ai:
			if (AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Random_AI>(Random_AI(1, this->game_logic.current_game_state(1)));
			else if (AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Random_AI>(Random_AI(2, this->game_logic.current_game_state(2)));
			break;
		case just_random_select_ai:
			if(AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Just_random_select_ai>(Just_random_select_ai(1, this->game_logic.current_game_state(1)));
			else if (AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Just_random_select_ai>(Just_random_select_ai(2, this->game_logic.current_game_state(2)));
			break;
		case frequency_ai:
			if (AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Frequency_AI>(Frequency_AI(1, this->game_logic.current_game_state(1)));
			else if (AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Frequency_AI>(Frequency_AI(2, this->game_logic.current_game_state(2)));
			break;
		default:
			if (AI_int == 1)
				this->computer_AI_player1 = std::make_unique<Greedy_no_place_man>(Greedy_no_place_man(1, this->game_logic.current_game_state(1)));
			else if (AI_int == 2)
				this->computer_AI_player2 = std::make_unique<Greedy_no_place_man>(Greedy_no_place_man(2, this->game_logic.current_game_state(2)));
			break;
		}
	}

	Game_handling game_logic;
	Patch input_patch;
	int actual_player;
	char orientation;
	int x_pos;
	int y_pos;
	int patch_look_index; //curr looking patches
	int game_look_index; //for game looking
	int num_games;
	int stored_seed;
	bool invert;

	std::unique_ptr<Base_AI> computer_AI_player1;
	bool active_AI_player1;

	std::unique_ptr<Base_AI> computer_AI_player2;
	bool active_AI_player2;
};

Game GAME = Game();
