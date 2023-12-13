#ifndef BOMB_H
#define BOMB_H

#include "thing.h"

// A type of thing that represents a bomb.
class Bomb : public Thing
{
    string getName()
    {
        return "bomb";
    }

    bool isBomb() override {
        return true; // This Thing is a bomb
    }
};

#endif // BOMB_H
