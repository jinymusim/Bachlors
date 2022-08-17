#ifndef AI_PLAYER
#define AI_PLAYER

#include "Value_based_AI.h"
#include "Game_handling.h"
#include <iostream>

class AI : public Value_based_AI {
public:

    AI(const int ai_start_int, Game_handling& game_logic_given) : Value_based_AI(ai_start_int, game_logic_given) { };
    //needed because class doesn't have default constructor
    AI& operator=(const AI& other) {
        Value_based_AI::operator=(other);
        return *this;
    }

    virtual ~AI() { std::cout << "AI player destructor" << std::endl; }


private:


public:
    void make_move() {
        switch (type_of_ai)
        {
        case greedy_no_space_man:
            break;
        case greedy_space_man:
            break;
        case min_max_no_space_man:
            break;
        case min_max_space_man:
            break;
        case min_max_free_space:
            break;
        case monte_carlo_free_space:
            break;
        default:
            break;
        }
    }
};


#endif
