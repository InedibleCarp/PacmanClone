#include "ghost.h"
#include <iostream>

Ghost::Ghost(int id) : ghostId(id) {}

void Ghost::update() {
    // For demonstration, print an update message.
    std::cout << "Ghost " << ghostId << " is updating its path..." << std::endl;
}
