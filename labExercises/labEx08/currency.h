#ifndef CURRENCY_H
#define CURRENCY_H

#include <string>
#include <stdexcept>

using namespace std;

class Currency {
public:
    Currency(int a, int b): super(a), sub(b) {
        if (a < 0) {
            throw invalid_argument("invalid super");
        }
        if (b < 0 || b > 99) {
            throw invalid_argument("invalid sub");
        }
    }

    int getSuper() const { return super; }
    int getSub() const { return sub; }

    void setSuper(int a) {
        if (a < 0) {
            throw invalid_argument("invalid euros");
        }
        super = a;
    }
    void setSub(int b) {
        if (b < 0 || b > 99) {
            throw invalid_argument("invalid cents");
        }
        sub = b;
    }

    virtual string toString() = 0;
    void zero(); // Declaration of the zero() method


    virtual ~Currency() = default;


private:
    int super, sub;

};

void badBank(Currency* c);

#endif // CURRENCY_H
