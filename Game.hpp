#pragma once

#include <string>

#define PLAYER true 
#define COMPUTER false
// player win or lose 
#define WIN 1
#define LOSE -1
#define DRAW 0
#define NOT_END 2

class Game {
private:
    // for easy to print map
    std::string _map; 
    bool _turn;
    int _State;

    bool not_end (std::string );
    // not win and not lose 
    bool draw (std::string );
    bool win (std::string );
public:
    Game(bool turn){
        // dont know whether it is ok
        _map = "012345678";
        _turn = turn;
        _State = NOT_END;
    }

    int situation (std::string );
    bool valid_input (std::string , int );
    void message (std::string );
    void update (std::string& , int , bool , std::string );
    void print_map (std::string ) ;
};
