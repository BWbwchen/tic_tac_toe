#pragma once

#include <vector>

#define PLAYER true 
#define COMPUTER false
#define WIN 1
#define LOSE -1
#define DRAW 0
#define NOT_END 2

class Game {
private:
    int _size = 9;
    enum State { BLANK , OCCUPY };
    std::vector<State > _map(size); 
    bool _turn;

    bool not_end (std::vector );
    bool draw (std::vector );
    bool win (std::vector );
public:
    Game(){
        // dont know whether it is ok
        fill(_map.begin(), _map.end(), State::BLANK);
        _turn = PLAYER;
    }

    int situation (std::vector );
    bool valid_input (std::vector , int );
    void message (std::vector );
    void update (std::vector& , int , bool , std::vector );
    void print_map (std::vector map);
};
