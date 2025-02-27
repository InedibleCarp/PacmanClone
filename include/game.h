#ifndef GAME_H
#define GAME_H

#include <vector>
#include <thread>
#include "ghost.h"

class Game {
public:
    Game();
    ~Game();
    void run();
private:
    void gameLoop();
    void updateGhosts();

    bool isRunning;
    std::vector<Ghost> ghosts;
    std::thread ghostThread;
};

#endif // GAME_H
