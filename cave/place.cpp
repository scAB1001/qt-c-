#include "place.h"
#include "thing.h"
#include "coin.h"
#include "mushroom.h"
#include "bomb.h"

void Place::fire(Cave& c, string userCommand)
{
    // Get string after " " (which is the object)
    string s = tail(userCommand);
    // Get Tom's current location in Cave
    Location* loc = c.getMap()[c.getTom()->getX()][c.getTom()->getY()];

    // Identifies the object/item
    if (s.compare("coin")==0)
        loc ->add(new Coin());
    else if (s.compare("mushroom")==0)
        loc ->add(new Mushroom());
    else if (s.compare("bomb")==0)
        loc->add(new Bomb());
    else
        cerr << "I don't know how to place a " << userCommand << endl;
}
