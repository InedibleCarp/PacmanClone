#ifndef GAME_H
#define GAME_H

#include <vector>
#include <thread>
#include "Ghost.h"
#include "ThreadPool.h"

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
    ThreadPool threadPool;           // Thread pool to process tasks concurrently
    std::thread ghostSchedulerThread; // Schedules ghost updates by enqueuing tasks
};

#endif // GAME_H
