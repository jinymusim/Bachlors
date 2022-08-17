#pragma once

//Blanket constant
constexpr int BLANKET_SIZE = 9;

//Game logic constant
constexpr int BASE_NUM_PATCHES = 33;
//constexpr int INIT_POINTS = -157; //Not necesray
constexpr int BASE_TIME = 50;
constexpr char BASE_FILENAME[] = "Patchwork_patches.txt"; //String can't be constexpr, use char[]
constexpr int BASE_KNOB_POS[] = { 45,40,35,30,25,20,15,10,5 };
constexpr int BASE_SPECIAL_POS[] = { 35,25,15,5 };

//AI constatnt
constexpr int PATCH_INDEX_OFFSET = 1;

//Freqency_AI constant
constexpr int RANDOM_INITIAL_MAX = 5;

//Min max AI constant
constexpr bool USE_NEW_EVAL = true;
constexpr int PREDICTION_DETPH_SPACE = 7;
constexpr int PREDICTION_DEPTH_NO_SPACE = 7;

//Monte Carlo base game num
constexpr int MONTE_CARLO_COUNT = 200;


//Game save file constatnt
constexpr char SAVE_FILE[] = "Patchwork_saves.txt";

//Game stats displaying
constexpr int NUM_GAMES_PAGE = 20;

//Interactive interafce number of game constant
constexpr int NUM_GENERATE_GAMES = 100;




