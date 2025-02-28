#include "Ghost.h"
#include <cstdlib>
#include <ctime>

// Constructor sets a unique starting position for each ghost.
// For a real game, these would be positions within your maze.
Ghost::Ghost(int id) : ghostId(id), mode(GhostMode::Chase) {
    // For demonstration, initialize positions based on ghost id.
    posX = id * 2;  // Example: ghost 0 at (0, 0), ghost 1 at (2, 2), etc.
    posY = id * 2;
}

// The update() method simulates simple ghost "chase" AI.
// In this example, the ghost moves one unit toward a fixed target
// representing Pacman's position (e.g., (5, 5)).
void Ghost::update() {
    // Target position for Pacman.
    const int targetX = 5;
    const int targetY = 5;
    
    // Calculate differences between ghost position and target.
    int dx = targetX - posX;
    int dy = targetY - posY;
    
    // Move horizontally if not aligned; otherwise move vertically.
    if (dx != 0) {
        posX += (dx > 0) ? 1 : -1;
    } else if (dy != 0) {
        posY += (dy > 0) ? 1 : -1;
    }
    
    std::cout << "Ghost " << ghostId << " moved to (" 
              << posX << ", " << posY << ")" << std::endl;
}

// Helper function to display the ghost's current position.
void Ghost::printPosition() const {
    std::cout << "Ghost " << ghostId << " is at (" 
              << posX << ", " << posY << ")" << std::endl;
}
