#include <iostream>
#include <string.h>

#include "throw.h"
#include "thing.h"
#include "location.h"
#include "tom.h"

void Throw::fire(Cave& c, string userCommand)
{
    // Sever into object being thrown and the direction of the object
    string objdir = tail(userCommand);                 // "coin north"
    int pos = objdir.find(" ");

    string obj = objdir.substr(0, pos);                // "coin"
    string dir = tail(objdir);                         // "north"

    cout << endl << "*" << objdir << "*" << endl;
    cout << endl << "*" << obj << "*" << endl;
    cout << endl << "*" << dir << "*" << endl;

    // Check if the direction is valid
    if (dir.empty() || (dir != "north" && dir != "south" && dir != "east" && dir != "west")) {
        cerr << "Invalid direction for throw command." << endl;
        return;
    }

    // Calculate target coords based on the direction
    int targetX = c.getTom()->getX();
    int targetY = c.getTom()->getY();

    if (dir == "north")
        targetY--;
    else if (dir == "south")
        targetY++;
    else if (dir == "east")
        targetX++;
    else if (dir == "west")
        targetX--;

    // Check if target location is within bounds
    if (targetX < 0 || targetY < 0 || targetX >= c.getWidth() || targetY >= c.getHeight())
    {
        cerr << "Can't throw into the void" << endl;
        return;
    }

    // Get ptrs to current and target locations
    Location* curLocation = c.getMap()[c.getTom()->getX()][c.getTom()->getY()];
    Location* targetLocation = c.getMap()[targetX][targetY];

    // Point to vector of things at Tom's curr location
    vector<Thing*>* thingsWithTom = curLocation->getThings();
    Thing* objToThrow = nullptr;

    // Find object to throw in cur location
    for (auto it = thingsWithTom->begin(); it != thingsWithTom->end(); ++it)
    {
        // Dir??
        if ((*it)->getName() == obj) // Check if the name matches the direction
        {
            objToThrow = *it;
            thingsWithTom->erase(it);
            break;
        }
    }

    // Check if there's an object to throw
    if (objToThrow == nullptr)
    { // Dir??
        cerr << "Tom doesn't have a " << obj << " to throw." << endl;
        return;
    }

    // Add the object to the target location
    targetLocation->add(objToThrow);

    cout << "Tom throws a " << dir << " " << dir << "." << endl;
}
