#include <iostream>
#include "currency.h"
#include "euro.h"
#include "pound.h"
#include "yuan.h"

using namespace std;

void Currency::zero() {
    super = 0;
    sub = 0;
}

// Without knowing the type of currency, it must be cast and checked
void badBank(Currency* c) {
    Pound* p = dynamic_cast<Pound*>(c);
    Euro* e = dynamic_cast<Euro*>(c);
    Yuan* y = dynamic_cast<Yuan*>(c);

    if (p) {
        p->setSuper(p->getSuper() - 1);
    } else if (e) {
        e->setSuper(e->getSuper() + 1);
    } else if (y) {
        y->setSuper(y->getSuper() * 2);
    }
}
