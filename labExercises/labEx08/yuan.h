#ifndef YUAN_H
#define YUAN_H

#include "currency.h"

using namespace std;

class Yuan : public Currency {
public:
    Yuan(int a, int b) : Currency(a, b) {}
    string toString() override ;

    ~Yuan() = default;
};


#endif // YUAN_H
