// for only pvc 
// player is o
#include <iostream>
#include <string>
#include <vector>
#include "Game.hpp"
#define PLAYER true 
#define COMPUTER false
#define WIN 1
#define LOSE -1
#define DRAW 0
#define NOT_END 2



bool win (std::string map) {
    // TODO : use 2d array
    if (map == "012345678") return false;
    // check for horizontal
    for (int i = 0; i <= 6; i += 3) { 
        if (map[i] == i+'0' || map[i+1] == i+'1' || map[i+2] == i+'2') continue;
        if (map[i] == map[i+1] && map[i+1] == map[i+2]) return true;
    }
    // check for vertical 
    for (int i = 0; i <= 2; ++i) {
        if (map[i] == i+'0' || map[i+3] == i+'3' || map[i+6] == i+'6') continue;
        if (map[i] == map[i+3] && map[i+3] == map[i+6]) return true;
    }

    // check for diagonal
    if (map[0] == map[4] && map[4] == map[8] && map[0] != '0') return true;
    if (map[2] == map[4] && map[4] == map[6] && map[2] != '2') return true;

    return false;
}
bool valid_input (std::string map, int position = -1){
    // for overwriting 
    if (map[position] != position+'0') return false;

    if (position != -1) {
        if (0 <= position && position <= 8) 
            return true;
        else 
            return false;
    } else {
        return false;
    }
}

void message (std::string output) {
    std::cout << output << std::endl;
}
void update(std::string& map, int position, bool turn, std::string player_notation){
    map[position] = (turn)?player_notation[0]:player_notation[1];
}
void print (std::string map) {
    system("clear");
    std::cout << "+-----+-----+-----+" << std::endl;
    std::cout << "|  " << map[0] << "  |  " << map[1] << "  |  " << map[2] << "  |\n";
    std::cout << "+-----+-----+-----+" << std::endl;
    std::cout << "|  " << map[3] << "  |  " << map[4] << "  |  " << map[5] << "  |\n";
    std::cout << "+-----+-----+-----+" << std::endl;
    std::cout << "|  " << map[6] << "  |  " << map[7] << "  |  " << map[8] << "  |\n";
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
std::vector extend_map(std::string map) {
}
// return what position to place 
// use minimax
int computer_solve (std::string map, int depth = 0, std::vector<int > static_value) {
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
}
int main () {
    // ' ' for nothing
    // initial map
    // TODO : use 2d array
    std::string map = "012345678";
    bool turn = PLAYER;
    int position;
    std::string player_notation = "";

    
    while (player_notation.length()==0 || (player_notation != "o" && player_notation != "x")) {
        system("clear");
        message("\tTic-Tac-Toe game!\n");
        message("choose which player you want to be!(o or x)\n");
        std::getline(std::cin, player_notation);
    }
    
    player_notation.push_back((player_notation[0]=='o')?'x':'o');
    print(map);

    while (situation(map) == NOT_END) {
        // TODO : consider the 'draw' condition
        // input chess
        if (turn == COMPUTER) {
            position = computer_solve(map);
        } else {
            std::cout << "It is PLAYER's turn\n";
            std::cout << "input where you want to place (0~8)\n";
            std::cin >> position ;
        }
        if (valid_input(map, position)) {
            // update
            update(map, position, turn, player_notation);
            turn = !turn;
            // print map
            print(map);
        } else {
            message("invalid input please input again!");
        }
    }
    // turn wherer is the next turn of the game
    if (turn == PLAYER) std::cout << "COMPUTER is winner !\n";
    else std::cout << "PLAYER is winner !\n";
}
