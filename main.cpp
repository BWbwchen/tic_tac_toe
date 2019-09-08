#include <iostream>
#include <string>
#define A true 
#define B false



bool win (std::string map) {
    // TODO : need to consider the initial state
    if (map == "         ") return false;
    // check for horizontal
    for (int i = 0; i <= 6; i += 3) { 
        if (map[i] == ' ' || map[i+1] == ' ' || map[i+2] == ' ') continue;
        if (map[i] == map[i+1] && map[i+1] == map[i+2]) return true;
    }
    // check for vertical 
    for (int i = 0; i <= 2; ++i) {
        if (map[i] == ' ' || map[i+3] == ' ' || map[i+6] == ' ') continue;
        if (map[i] == map[i+3] && map[i+3] == map[i+6]) return true;
    }

    // check for diagonal
    if (map[0] == ' ' || map[4] == ' ' || map[8] == ' ' 
        || map[2] ==' ' || map[6] == ' ') return false;
    if (map[0] == map[4] && map[4] == map[8]) return true;
    if (map[2] == map[4] && map[4] == map[6]) return true;

    return false;
}
bool valid_input (int position = -1, char player = '@') {
    if (position != -1 && player != '@') {
        if (0 <= position && position <= 8 && (player == 'o' || player == 'x')) 
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
void update(std::string map, int position, char player) {
    map[position] = player;
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
    // - for nothing
    // initial map
    std::string map = "         ";
    bool turn = A;
    print(map);

    while (!win(map)) {
        // input chess
        int position;
        char player;
        std::cout << "input where you want to place (0~8)\n";
        std::cin >> position >> player;
        if (valid_input(position, player)) {
            // update
            update(map, position, player);
            turn = !turn;
            // print map
            print(map);
        } else {
            message("invalid input please input again!");
        }
    }
}
