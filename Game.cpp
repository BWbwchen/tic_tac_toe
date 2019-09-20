#include "Game.hpp"
#include <iostream>


// private

bool Game::is_full (void) {
    for (auto ch : _map) {
        if (48 <= ch && ch <= 56) {
            return false;;
        }
    }
    return true; 
}

// player or computer win 
bool Game::win (void) {
    // TODO : use 2d array
    if (_map == "012345678") return false;
    // check for horizontal
    for (int i = 0; i <= 6; i += 3) { 
        if (_map[i] == i+'0' || _map[i+1] == i+'1' || _map[i+2] == i+'2') continue;
        if (_map[i] == _map[i+1] && _map[i+1] == _map[i+2]) {
            if (_map[i] == 'o') _winner = P ;
            else _winner = C;
            return true;
        }
    }
    // check for vertical 
    for (int i = 0; i <= 2; ++i) {
        if (_map[i] == i+'0' || _map[i+3] == i+'3' || _map[i+6] == i+'6') continue;
        if (_map[i] == _map[i+3] && _map[i+3] == _map[i+6]) {
            if (_map[i] == 'o') _winner = P ;
            else _winner = C;
            return true;
        }
    }

    // check for diagonal
    if ((_map[0] == _map[4] && _map[4] == _map[8] && _map[0] != '0') || 
        (_map[2] == _map[4] && _map[4] == _map[6] && _map[2] != '2')) {
            if (_map[4] == 'o') _winner = P;
            else _winner = C;
            return true;
    }
    return false;
}
bool Game::valid_input (int position) {
    // for overwriting 
    if (_map[position] != position+'0') return false;

    if (0 <= position && position <= 8) 
        return true;
    else 
        return false;
}
void Game::message (std::string output) {
    std::cout << output << std::endl;
}

int Game::computer_solve (void) {
    int test;
    std::cout << "this is computer's turn\n";
    std::cin >> test ;
    return test;
}

/*
    switch (situation(map)) {
        case WIN : return 1;
        case LOSE : return -1;
        case DRAW : return 0;
        default : break;
    }

    for (auto possible_move : extend_map(map)) {
        put_on_map(possible_move);
        static_value[possible_move] = calculate_static_value(possible_move, map);
        take_out_map(possible_move);
    }

    return max(index_of_static_value);
*/

// public
bool Game::end (void ) {
    if (win ())
        return true;
    else if (is_full ()) {
        _winner = NONE;
        return true;
    }
    return false;
}
void Game::update (void) {
    int position;
    if (_turn == COMPUTER) {
        position = computer_solve();
    } else {
        do {
            print_map();
            std::cout << "It is PLAYER's turn\n";
            std::cout << "input where you want to place (0~8)\n";
            std::cin >> position ;
            system("clear");
        } while (!valid_input(position));
    }

    if (valid_input(position)) {
        // update
        _map[position] = (_turn == PLAYER)?'o':'x';
        _turn = !_turn;
        // print map
        print_map();
    } else {
        message("invalid input please input again!");
    }

}
void Game::print_map (void) {
    system("clear");
    for (int i = 0; i < 9; i+=3) {
        std::cout << "+-----+-----+-----+" << std::endl;
        std::cout << "|  " << _map[i] 
                  << "  |  " << _map[i+1] 
                  << "  |  " << _map[i+2] 
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
void Game::winner (void ) {
    if (_winner == C) std::cout << "COMPUTER is winner !\n";
    else if (_winner == P ) std::cout << "PLAYER is winner !\n";
    else if (_winner == NONE) std::cout << "DRAW\n";
    else std::cout << "something wrong\n";
}
