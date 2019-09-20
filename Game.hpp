#pragma once

#include <string>

#define P 1
#define C 0
#define NONE 2
#define NOT_END 3
#define PLAYER true 
#define COMPUTER false

class Game {
private:
    // for easy to print map
    // player is o
    // computer is x
    std::string _map; 
    bool _turn;
    int _winner;

    void message (std::string );
    bool valid_input (int );
    bool is_full (void);
    bool win (void);
    int computer_solve (void);
public:
    Game(bool turn){
        // dont know whether it is ok
        _map = "012345678";
        _turn = turn;
        _winner = NOT_END;
    }

    bool end (void);
    void update (void);
    void print_map (void) ;
    void winner (void);
};
