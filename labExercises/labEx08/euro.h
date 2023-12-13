#ifndef EURO_H
#define EURO_H

#include "currency.h"

using namespace std;

class Euro : public Currency {
public:
    Euro(int a, int b) : Currency(a, b) {}
    string toString() override;

    ~Euro() = default;
};


#endif // EURO_H
