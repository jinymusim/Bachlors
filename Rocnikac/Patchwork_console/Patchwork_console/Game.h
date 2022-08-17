#pragma once
#include "Game_handling.h";



//base save file
constexpr char SAVE_FILE[] = "Patchwork_saves.txt";

class Game {
public:
	//get initial state
	Game() : game_logic{} {
		setup_save_file();
	};

	void setup_save_file() {
		std::ifstream file(SAVE_FILE);
		if (!file.good()) {
			std::ofstream save_file(SAVE_FILE);
		}
	};

	void save_game() {
		//get file and open with append
		std::ofstream out;
		out.open(SAVE_FILE, std::ios::app);
		std::string out_line;
		//get the seed and write it 
		out_line = std::to_string(game_logic.get_game_seed());
		out << out_line << std::endl;

		//write down the used patch order
		out_line = "";
		auto temp_vector = game_logic.get_played_patches_in_order();
		for (int i = 0; i < ((int)temp_vector.size()); i++) { //int to prevent uderflow
			out_line += std::to_string(temp_vector[i].get_patch_index());
			out_line += ",";
		}

		out << out_line << std::endl;;

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

	Game_handling game_logic;
	Patch input_patch;
	int actual_player;
	char orientation;
	int x_pos;
	int y_pos;
	int patch_look_index; //curr looking patches
	int stored_seed;
	bool invert;
};

Game GAME = Game();
