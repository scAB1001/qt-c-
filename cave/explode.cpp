#include "explode.h"
#include "bomb.h"

void Explode::fire(Cave& c, string userCommand)
{
    Location* tomLocation = c.getMap()[c.getTom()->getX()][c.getTom()->getY()];
    vector<Location*> locationsToExplode; // Stores locations to be exploded

    // Get XY coords of Tom
    int tomX = c.getTom()->getX();
    int tomY = c.getTom()->getY();

    // Check Tom's location
    if (tomLocation->isBomb()) {
        locationsToExplode.push_back(tomLocation);
    }

    // Check coords for bomb to the north, south, east, and west of Tom
    //  If a bomb exists, add to vector of bombs to explode
    if (tomX > 0) {
        if (c.getMap()[tomX-1][tomY]->isBomb()) {
            locationsToExplode.push_back(c.getMap()[tomX-1][tomY]);
        }
    }
    if (tomX < c.getWidth() - 1) {
        if (c.getMap()[tomX+1][tomY]->isBomb()) {
            locationsToExplode.push_back(c.getMap()[tomX+1][tomY]);
        }
    }
    if (tomY > 0) {
        if (c.getMap()[tomX][tomY-1]->isBomb()) {
            locationsToExplode.push_back(c.getMap()[tomX][tomY-1]);
        }
    }
    if (tomY < c.getHeight() - 1) {
        if (c.getMap()[tomX][tomY+1]->isBomb()) {
            locationsToExplode.push_back(c.getMap()[tomX][tomY+1]);
        }
    }

    // Explode the locations
    for (Location* loc : locationsToExplode) {
        loc->removeBomb();
        loc->explode();
    }
}
