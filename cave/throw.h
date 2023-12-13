#ifndef THROW_H
#define THROW_H

#include "command.h"

class Throw : public Command
{
public:
    // When the "throw" command is caught, Throw() is invoked
    Throw() : Command("throw") {};
    void fire(Cave& c, string userCommand);
};

#endif // THROW_H
