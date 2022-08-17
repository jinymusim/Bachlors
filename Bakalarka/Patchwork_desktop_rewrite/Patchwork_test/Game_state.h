#pragma once

#include "Player.h"
#include "Blanket.h"
#include "Patch.h"
#include "constants.h"

struct Game_state {
public:
	Player player1;
	Player player2;
	Blanket blanket_player1;
	Blanket blanket_player2;
	std::vector<Patch> current_patches_in_game;
	std::vector<Patch> playble_patches;
	Patch special_patch;

	Game_state(Player&& player1, Player&& player2, Blanket&& blanket_player1, Blanket&& blanket_player2,
		std::vector<Patch>&& current_patches_in_game, std::vector<Patch>&& playble_patches, Patch&& special_patch) {
		this->player1 = player1;
		this->player2 = player2;
		this->blanket_player1 = blanket_player1;
		this->blanket_player2 = blanket_player2;
		this->current_patches_in_game = current_patches_in_game;
		this->playble_patches = playble_patches;
		this->special_patch = special_patch;
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

	Patch return_special_patch() {
		return special_patch;
	}

	Blanket& get_blanket(int player_ID) {
		switch (player_ID)
		{
		case 1:
			return blanket_player1;
		case 2:
			return blanket_player2;
		}
	}

	std::pair<int, int> get_actual_point_tally() {
		return std::make_pair(player1.knobs - 2 * blanket_player1.return_num_blank_spaces() + 7 * blanket_player1.blanket_7x7(),
			player2.knobs - 2 * blanket_player2.return_num_blank_spaces() + 7 * blanket_player2.blanket_7x7());
	}

	std::vector<Patch> get_actual_patches() {
		return current_patches_in_game;
	}

	std::vector<Patch> get_playable_patches() {
		return playble_patches;
	}

};
