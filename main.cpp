#include <iostream>
#include <string>
#define PLAYER true 
#define COMPUTER false



bool win (std::string map) {
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
bool valid_input (int position = -1){
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
void update(std::string& map, int position, bool turn){
    map[position] = (turn==PLAYER)?'o':'x';
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
int main () {
    // ' ' for nothing
    // initial map
    std::string map = "012345678";
    bool turn = PLAYER;
    int position;

    print(map);

    while (!win(map)) {
        // input chess
        std::cout << "It is " << (turn?"PLAYER":"COMPUTER") << "'s turn\n";
        std::cout << "input where you want to place (0~8)\n";
        std::cin >> position ;
        if (valid_input(position)) {
            // update
            update(map, position, turn);
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
