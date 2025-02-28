#include "Ghost.h"
#include <iostream>

Ghost::Ghost(int id) : ghostId(id) {}

void Ghost::update() {
    // Simulate ghost AI processing (e.g., pathfinding)
    std::cout << "Ghost " << ghostId << " is updating its path concurrently..." << std::endl;
}
