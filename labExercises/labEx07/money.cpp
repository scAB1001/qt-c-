#include <iostream>
#include "money.h"
// The file for long methods

using namespace std;

string Money::toString() const {
    // to_string is a utility in the std namespace
    return "EUR " + to_string(euros) +'.' + to_string (cents);
}

Money Money::plus(const Money& other) const {
    return Money(euros + other.euros, cents + other.cents );
}

Money operator+ (const Money& m1, const Money& m2)
{
    int e = m1.getEuros() + m2.getEuros();
    int c = m1.getCents() + m2.getCents();
    return Money(e + c/100, c % 100);
}

