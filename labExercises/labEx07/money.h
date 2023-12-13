#ifndef LAB2_MONEY_H
#define LAB2_MONEY_H
/* Rule of thumb
if the method's code is more
than 2 lines long (or has complex operations) then it should not
be in the header file
*/

#include <string>
#include <stdexcept>

using namespace std;

class Money {
public:
    Money(int e, int c): euros(e), cents(c) {
        if (e < 0) {
            throw invalid_argument("invalid euros");
        }
        if (c < 0 || c > 99) {
            throw invalid_argument("invalid cents");
        }
    }

    int getEuros() const { return euros; }
    int getCents() const { return cents; }

    string toString() const;

    Money plus(const Money&) const;

private:
    int euros, cents;
};

Money operator+ (const Money& m1, const Money& m2);

#endif //LAB2_MONEY_H
