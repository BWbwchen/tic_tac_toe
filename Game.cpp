#include "Game.hpp"



// private

bool Game::not_end (std::string map) {
    bool end = false;
    for (auto ch : map) {
        if (ch != 'o' || ch != 'x') {
            end = true;
            break;
        }
    }
    return end; 
}

bool Game::draw (std::string map) {
    if (not_end(map)) return false;
    if (!win(map) && !lose(map)) return true;
}
// player or computer win 
bool Game::win (std::string map) {
    // TODO : use 2d array
    if (map == "012345678") return false;
    // check for horizontal
    for (int i = 0; i <= 6; i += 3) { 
        if (map[i] == i+'0' || map[i+1] == i+'1' || map[i+2] == i+'2') continue;
        if (map[i] == map[i+1] && map[i+1] == map[i+2]) {
            if (map[i] == 'o') _State = WIN ;
            else _State = LOSE;
            return true;
    }
    // check for vertical 
    for (int i = 0; i <= 2; ++i) {
        if (map[i] == i+'0' || map[i+3] == i+'3' || map[i+6] == i+'6') continue;
        if (map[i] == map[i+3] && map[i+3] == map[i+6]) {
            if (map[i] == 'o') _State = WIN ;
            else _State = LOSE;
            return true;
        }
    }

    // check for diagonal
    if ((map[0] == map[4] && map[4] == map[8] && map[0] != '0') || 
        (map[2] == map[4] && map[4] == map[6] && map[2] != '2')) {
            if (map[i] == 'o') _State = WIN ;
            else _State = LOSE;
            return true;
    }
    return false;
}

// public

int Game::situation (std::string map) {
    if (not_end(map)) return NOT_END;
    if (win(map)) return WIN;
    if (draw(map)) return DRAW;
    return LOSE;
}
bool Game::valid_input (std::string , int );
void Game::message (std::string );
void Game::update (std::string& , int , bool , std::string );
void Game::print_map (std::string map) {
    system("clear");
    for (int i = 0; i < 3; ++i) {
        std::cout << "+-----+-----+-----+" << std::endl;
        std::cout << "|  " << map[i] 
                  << "  |  " << map[i+1] 
                  << "  |  " << map[i+2] 
                  << "  |\n";
    }
    std::cout << "+-----+-----+-----+" << std::endl;
    /*
        +-----+-----+-----+
        |  o  |  o  |  o  |
        +-----+-----+-----+
        |  o  |  o  |  o  |
        +-----+-----+-----+
        |  o  |  o  |  o  |
        +-----+-----+-----+
    */
}
