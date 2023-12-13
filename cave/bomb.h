#ifndef BOMB_H
#define BOMB_H

#include "thing.h"

// a bomb that can explode and explode nearby bombs!
class Bomb : public Thing
{
    string getName() override
    {
        return "bomb";
    }

    bool isBomb() override {
        return true;
    }
};

#endif // BOMB_H
