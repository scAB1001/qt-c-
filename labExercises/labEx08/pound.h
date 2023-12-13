#ifndef POUND_H
#define POUND_H

#include "currency.h"

using namespace std;

class Pound : public Currency {
public:
    Pound(int a, int b) : Currency(a, b) {}
    string toString() override ;

    ~Pound() = default;
};


#endif // POUND_H
