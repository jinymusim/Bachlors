#ifndef BASE_AI
#define BASE_AI

#include "Game_state.h"
#include "AI_responce.h"
#include <iostream>

//Types of AIs 
enum AI_type {
    greedy_no_space_man, greedy_space_man, min_max_no_space_man, min_max_space_man, min_max_free_space,
    monte_carlo_free_space, random_ai, just_random_select_ai, frequency_ai
};

public class Base_AI
{
public:
    Base_AI(const int ai_start_int, Game_state initial_game_state) : ai_int(ai_start_int), initial_game_state(initial_game_state), current_game_state(initial_game_state) {
    }
    //needed because class doesn't have default constructor
    Base_AI& operator=(const Base_AI& other) {
        this->initial_game_state = other.initial_game_state;
        this->current_game_state = other.current_game_state;
        this->ai_int = other.ai_int;
        return *this;
    }

    virtual ~Base_AI() { std::cout << "BASE desctutor" << std::endl; }

    // Generate new move from given position
    virtual AI_responce make_move(Game_state current_state) {
        return AI_responce(ai_int, current_game_state.return_special_patch(), 0, 0, 'n', false, false, false);
    };

    // Name of the AI
    virtual std::string get_name() {
        return "Base_AI ";
    }


protected:
    int ai_int; //number of the ai player
    Game_state initial_game_state;
    Game_state current_game_state;

    //counts the number of empty neighbours around empty places
    virtual void get_neighbor_blank_count(Blanket::blanket_map& blanket_map) {
        //neighbors
        std::vector<std::pair<int, int>> neighbors = {
            std::make_pair(-1,0), std::make_pair(0,-1), std::make_pair(1,0), std::make_pair(0,1)
        };
        //go through blanket 
        for (int i = 0; i < BLANKET_SIZE; i++) {
            for (int j = 0; j < BLANKET_SIZE; j++) {
                if (blanket_map[i][j] <= 0) { //if blank, start counting neighbours
                    for (auto&& neigh : neighbors) {
                        int new_i = i + neigh.first;
                        int new_j = j + neigh.second;
                        //neighbour must be in blanket
                        if (new_i >= 0 && new_i < BLANKET_SIZE && new_j >= 0 && new_j < BLANKET_SIZE) {
                            //look if neighbour is blank
                            if (blanket_map[new_i][new_j] <= 0) {
                                blanket_map[i][j] -= 1;
                            }
                        }
                    }
                }
            }
        }
    }

    //Find the best posible placement for the patch, greedy.
    virtual AI_responce find_best_placement(Patch& patch, Blanket::blanket_map& blanket_map, bool virtual_place) {
        //posible orientations
        std::vector<char> orientation = { 'n', 'e', 's', 'w' };
        //get the marked map
        auto neighbour_map = current_game_state.get_blanket(ai_int).get_blanket_map();
        get_neighbor_blank_count(neighbour_map);
        //all the neighbours categories count
        std::vector<std::vector<int>> neigh_count = std::vector<std::vector<int>>();
        // [0] - i, [1] - j, [2] - orientation, [3] - inverse
        std::vector<std::vector<int>> place_config = std::vector<std::vector<int>>();
        //neigh_count have base value on index 0
        int INDEX_OFFSET = 1;
        //count the base neigh_count value
        neigh_count.push_back({ 0,0,0,0,0 });
        for (size_t i = 0; i < BLANKET_SIZE; i++) {
            for (size_t j = 0; j < BLANKET_SIZE; j++) {
                if (neighbour_map[i][j] <= 0) {
                    neigh_count[0][-1 * neighbour_map[i][j]] += 1;
                }
            }
        }
        //neighbours
        std::vector<std::pair<int, int>> neighbours = {
            std::make_pair(-1,0), std::make_pair(0,-1), std::make_pair(1,0), std::make_pair(0,1)
        };

        //on whitch part we are
        size_t curr_config = 0;
        //overplaced positions
        //[0] - i, [1] - i, [2] - original value
        std::vector<std::vector<int>> placed_pos_and_base = std::vector<std::vector<int>>();
        //inversion
        for (size_t my_bool = 0; my_bool < 2; my_bool++) {
            //orientation
            for (size_t ch = 0; ch < orientation.size(); ch++) {
                //get the patch_map (same for position)
                auto patch_map = patch.oriented_map(orientation[ch], my_bool);
                //for every start position
                for (size_t i = 0; i < BLANKET_SIZE; i++) {
                    for (size_t j = 0; j < BLANKET_SIZE; j++) {
                        //try to place (bool indicator)
                        bool placeable = true;
                        //base count
                        neigh_count.push_back(neigh_count[0]);
                        //mark config
                        place_config.push_back({ (int)i,(int)j,(int)ch,(int)my_bool });
                        //try to place
                        for (size_t l = 0; l < patch_map.size(); l++) {
                            for (size_t m = 0; m < patch_map[0].size(); m++) {
                                //must be inside blanket
                                if (patch_map[l][m]) {
                                    if (i + l < BLANKET_SIZE && j + m < BLANKET_SIZE) {
                                        if (neighbour_map[i + l][j + m] > 0) {
                                            placeable = false; //not placable
                                        }
                                        else if (placeable) { //placable
                                            //mark what value is beeing overwritten
                                            placed_pos_and_base.push_back({ (int)(i + l), (int)(j + m),neighbour_map[i + l][j + m] });
                                            //decrese counter on that value
                                            neigh_count[curr_config + INDEX_OFFSET][-1 * neighbour_map[i + l][j + m]] -= 1;
                                            //mark with temp value
                                            neighbour_map[i + l][j + m] = 50;
                                            //decrese value for neighbours
                                            for (auto&& neigh : neighbours) {
                                                //neighbour position
                                                int new_i = i + l + neigh.first;
                                                int new_j = j + m + neigh.second;
                                                //if in blanket
                                                if (new_i >= 0 && new_i < BLANKET_SIZE && new_j >= 0 && new_j < BLANKET_SIZE) {
                                                    //if blank
                                                    if (neighbour_map[new_i][new_j] <= 0) {
                                                        //get the class value
                                                        auto value = -1 * neighbour_map[new_i][new_j];
                                                        //decrese number of neighbours
                                                        neighbour_map[new_i][new_j] += 1;
                                                        //decrese previous count class
                                                        neigh_count[curr_config + INDEX_OFFSET][value] -= 1;
                                                        //increase new class
                                                        neigh_count[curr_config + INDEX_OFFSET][value - 1] += 1;
                                                    }
                                                }

                                            }
                                        }
                                    }
                                    //outside of blanket
                                    else {
                                        placeable = false;
                                    }
                                }
                            }
                        }
                        //return the values of neighbour map, in reverse order, because of +-1
                        for (int o = placed_pos_and_base.size() - 1; o > -1; o--) {
                            //position
                            int l = placed_pos_and_base[o][0];
                            int m = placed_pos_and_base[o][1];
                            //placement
                            neighbour_map[l][m] = placed_pos_and_base[o][2];
                            //return for neighbours
                            for (auto&& neigh : neighbours) {
                                //neighbour position
                                int new_i = l + neigh.first;
                                int new_j = m + neigh.second;
                                //if in blanket
                                if (new_i >= 0 && new_i < BLANKET_SIZE && new_j >= 0 && new_j < BLANKET_SIZE) {
                                    if (neighbour_map[new_i][new_j] <= 0) {
                                        neighbour_map[new_i][new_j] -= 1;
                                    }
                                }
                            }
                        }
                        //clear the whole vector
                        placed_pos_and_base.clear();
                        curr_config++; //next config
                        if (!placeable) { //wasn't placed properly, remove config
                            place_config.pop_back();
                            neigh_count.pop_back();
                            curr_config--; //no increment
                        }
                    }
                }
            }
        }

        //if not good position, false
        if (place_config.size() == 0) {
            return AI_responce(0, current_game_state.return_special_patch(), 0, 0, 'n', false, false, false);
        }
        //try to find best position
        else {
            size_t best_index = 0;
            //best position is the one with fewest holes
            std::vector<int> best_class = neigh_count[1];
            for (size_t i = 2; i < neigh_count.size(); i++) {
                auto cont_class = neigh_count[i];
                for (size_t j = 0; j < cont_class.size(); j++) {
                    if (cont_class[j] < best_class[j]) {
                        best_class = cont_class;
                        best_index = i - INDEX_OFFSET;
                        break;
                    }
                    else if (cont_class[j] > best_class[j]) {
                        break;
                    }
                }
            }
            //placement only virtual to local blanket map
            if (virtual_place) {
                auto patch_map = patch.oriented_map(orientation[place_config[best_index][2]], place_config[best_index][3]);
                for (size_t l = 0; l < patch_map.size(); l++) {
                    for (size_t m = 0; m < patch_map[0].size(); m++) {
                        if (patch_map[l][m]) {
                            blanket_map[l + place_config[best_index][0]][m + place_config[best_index][1]] = patch.get_patch_index();
                        }
                    }
                }
                return AI_responce(0, current_game_state.return_special_patch(), 0, 0, 'n', false, false, true);
            }
            return AI_responce(ai_int, patch, place_config[best_index][0], place_config[best_index][1], orientation[place_config[best_index][2]], place_config[best_index][3], false, true);
        }
    }

};


#endif
