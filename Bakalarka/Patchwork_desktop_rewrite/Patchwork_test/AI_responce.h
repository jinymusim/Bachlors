#pragma once

#include "Game_state.h"

/* Struct to format the responce from AI. Can be also used to wrap user responce.
*
*/
struct AI_responce {
public:
	/* Identification number of the player
	*/
	int ai_int;
	/* Patch that the player selected to play
	*/
	Patch selected_patch;
	/* Position to place the patch on
	*/
	int y_pos;
	int x_pos;
	/* Char how to rotate the selected patch
	*/
	char rotation;
	/* Flag if the patch should be inverted
	*/
	bool inversion;

	/* Flag if the skip action should be used instead
	*/
	bool skip;
	/* Flag used internaly if the propoed move was succesful.
	*/
	bool success;

	/* Constructor, takes elements and assigns them to their proper atribute
	*
	*/
	AI_responce(int ai_int, Patch selected_patch, int y_pos, int x_pos, char rotation, bool inversion, bool skip, bool success) {
		this->ai_int = ai_int;
		this->selected_patch = selected_patch;
		this->y_pos = y_pos;
		this->x_pos = x_pos;
		this->rotation = rotation;
		this->inversion = inversion;
		this->skip = skip;
		this->success = success;
	}


};
