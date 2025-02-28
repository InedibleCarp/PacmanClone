#include "Game.h"
#include <iostream>
#include <chrono>

Game::Game() 
    : isRunning(true),
      threadPool(4) // Create a thread pool with 4 worker threads
{
    // Initialize ghosts (for example, creating 4 ghosts)
    for (int i = 0; i < 4; ++i) {
        ghosts.push_back(Ghost(i));
    }
}

Game::~Game() {
    isRunning = false;
    if (ghostSchedulerThread.joinable())
        ghostSchedulerThread.join();
}

void Game::run() {
    // Start a background thread to schedule ghost updates
    ghostSchedulerThread = std::thread(&Game::updateGhosts, this);
    // Run the main game loop
    gameLoop();
}

void Game::gameLoop() {
    while (isRunning) {
        // Handle game loop tasks (input, rendering, etc.)
        std::cout << "Main game loop is running..." << std::endl;

        // For demonstration, stop after 10 iterations
        static int counter = 0;
        if (++counter > 10) {
            isRunning = false;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Game::updateGhosts() {
    while (isRunning) {
        // Enqueue an update task for each ghost
        for (auto& ghost : ghosts) {
            threadPool.enqueueTask([&ghost]() {
                ghost.update();
            });
        }
        // Update frequency for ghost AI (e.g., every 500 ms)
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
