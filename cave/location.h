#ifndef LOCATION_H
#define LOCATION_H


#include <vector>

#include "thing.h"

class Location
{
public:
    Location(){++count;}
    Location(const Location& other);
    ~Location()
    {
        for (auto t : things)
            delete(t);
        --count;
    }
    // Allows adding of objects eg. mushroom
    void add(Thing *t);
    void remove(Thing *t);
    char show();
    bool isBlocking();
    void removeBomb();
    bool isBomb();
    bool hasBomb();
    void explode();
    vector<Thing*>* getThings() { return &things; }
    static int count; // a count of the number of locations allocated/deleted

private:
    vector<Thing*> things;

};


#endif // LOCATION_H
