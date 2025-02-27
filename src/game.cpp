#include "Game.h"
#include <iostream>
#include <chrono>

Game::Game() : isRunning(true) {
    // Initialize ghosts (for example, creating 4 ghosts)
    for (int i = 0; i < 4; ++i) {
        ghosts.push_back(Ghost(i));
    }
}

Game::~Game() {
    isRunning = false; // signal threads to stop
    if (ghostThread.joinable())
        ghostThread.join();
}

void Game::run() {
    // Start a background thread for ghost updates
    ghostThread = std::thread(&Game::updateGhosts, this);
    // Run the main game loop
    gameLoop();
}

void Game::gameLoop() {
    while (isRunning) {
        // Here you would handle input, collision detection, etc.
        std::cout << "Game loop running..." << std::endl;

        // For demonstration, run the loop for a few iterations then stop.
        static int counter = 0;
        if (++counter > 5) {
            isRunning = false;
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Game::updateGhosts() {
    while (isRunning) {
        for (auto& ghost : ghosts) {
            ghost.update();
        }
        // Simulate ghost update frequency
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}
