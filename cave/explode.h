#ifndef EXPLODE_H
#define EXPLODE_H

#include "command.h"

// Mimics Place class.h behaviour
class Explode : public Command
{
public:
    Explode() : Command("explode") {};
    void fire(Cave& c, string userCommand);
};

#endif // EXPLODE_H
