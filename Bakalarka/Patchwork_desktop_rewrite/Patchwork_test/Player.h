#pragma once

struct Player { //struct to keep information about player
public:
	//construtor, base points and knobs
	Player() : time{ 0 }, first{ false }, knobs{ 5 }, knob_index{ 0 } { };
	Player(bool first, int time) : time{ time }, first{ first }, knobs{ 5 }, knob_index{ 0 }  { };

	int time;
	int knobs;
	bool first;
	int knob_index;
};
