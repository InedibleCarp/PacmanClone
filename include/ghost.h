#ifndef GHOST_H
#define GHOST_H

#include <iostream>

// Define possible AI modes for later expansion
enum class GhostMode {
    Chase,
    Scatter
};

class Ghost {
public:
    explicit Ghost(int id);
    void update();  // Update ghost AI logic
    void printPosition() const;
    
private:
    int ghostId;
    int posX;
    int posY;
    GhostMode mode;
};

#endif // GHOST_H
