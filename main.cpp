// for only pvc 
// player is o
#include "Game.hpp"

int main () {
    // ' ' for nothing
    // initial map
    
    Game ttt(PLAYER);

    while (!ttt.end()) {
        ttt.update();
    }
    ttt.winner();
    return 0;
}
