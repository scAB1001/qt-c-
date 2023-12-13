#include <algorithm>

#include "blocks.h"
#include "location.h"
#include "tom.h"
#include "bomb.h"

using namespace std;

void Location::add(Thing *t)
{
    things.push_back( t );
}

void Location::remove(Thing *t)
{
    // note we don't free the memory here
    things.erase(std::remove(things.begin(), things.end(), t), things.end());
}

// Create a deep copy of Location and the items in the vector.
Location::Location(const Location& other) {
    for (auto t : other.things) {
        things.push_back(t->clone());
    }
    ++count;
}

// Mimics remove thing but for a bomb only.
void Location::removeBomb() {
    things.erase(remove_if(things.begin(), things.end(), [](Thing* t) {
                     return t->isBomb();
                 }), things.end());
}

// Explodes the vector of bombs in their prospective locations.
void Location::explode() {
    for (auto t : things) {
        if (!t->isBomb()) {
            delete t;
        }
    }
    things.clear();
}

// Methods of identifying bombs
// 1. Checking type
bool Location::isBomb()
{
    for (Thing* t : things)
    {
        // Check if Thing is a Bomb
        if (dynamic_cast<Bomb*>(t))
            return true;
    }
    return false;
}
// Calling method
bool Location::hasBomb() {
    for (auto t : things) {
        if (t->isBomb()) {
            return true;
        }
    }
    return false;
}

char Location::show() {

    int junk = 0, blocking = 0, tom = 0;

    // count properties of things at this location
    for (Thing* t : things)
    {
        if (dynamic_cast<Blocks*>(t) ) // is t subclass of Blocks?
            blocking++;
        else if (dynamic_cast<Tom*> (t) != NULL ) // is t Tom?
            tom++;
        else
            junk++; // otherwise just junk
    }

    // return a character based on the properties
    if (blocking) // remember that
        return 'X';
    else if (junk > 0)
    {
        if (tom)
            return 'L';
        else
            return '_';
    }
    else if (tom)
        return '|';
    else
        return '.';
}

bool Location::isBlocking() // does this location block tom's travels?
{
    int blocking = 0;

    for (Thing * t : things)
        if ( dynamic_cast<Blocks*>(t) )// is t subclass of Blocks?
            blocking++;

    return blocking; // 0 means false, otherwise true
}
