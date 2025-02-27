#ifndef GHOST_H
#define GHOST_H

class Ghost {
public:
    Ghost(int id);
    void update();  // Update ghost AI logic
private:
    int ghostId;
};

#endif // GHOST_H
