#include <iostream>
#include <vector>

#include "currency.h"
#include "euro.h"
#include "pound.h"
#include "yuan.h"

using namespace std;

int main() {
    cout << endl;

    /* Toying with ptrs and mrefs
    Currency *c = new Yuan(1, 99);
    // You use static_cast to safely downcast it to a Pound*
    Yuan* y = static_cast<Yuan*>(c);
    // This is valid only if you are sure that c actually points to a Pound object.
    cout << y->toString() << endl << endl;

    // In this case, dynamic_cast is used when you are uncertain about the actual type of the object pointed to by maybePound.
    // If it's a Pound, it will return a non-null pointer to definitelyAPound.
    Currency *maybePound = new Pound(3,99);
    if (Pound* definitelyAPound = dynamic_cast<Pound*>(maybePound))
        cout << definitelyAPound ->toString() << endl;
    else
        cout << "that wasn't a pound!" << endl;

    // Casting works with references as well
    Currency *c = new Pound(4, 10);
    Currency& ref = *c;  // Assuming c is a valid pointer
    Pound& poundRef = dynamic_cast<Pound&>(ref);
    cout << c->toString();
    cout << poundRef.toString();
    */

    Currency* pound = new Pound(5, 99);
    Currency* euro = new Euro(3, 7);
    Currency* yuan = new Yuan(8, 50);

    badBank(pound);
    badBank(euro);
    badBank(yuan);

    cout << "Pound: " << pound->toString() << endl;
    cout << "Euro: " << euro->toString() << endl;
    cout << "Yuan: " << yuan->toString() << endl;

    delete pound;
    delete euro;
    delete yuan;

    /* Add all the currencies to a general vector, display
    vector<Currency*> vbucks;
    Euro euros(03, 70);
    Pound pounds(45, 20);
    Yuan yuans(12, 18);
    yuans.zero();

    vbucks.push_back(&euros);
    vbucks.push_back(&pounds);
    vbucks.push_back(&yuans);

    // If I pushed just euros to a Currency vector,
    // then the Euro euros would become Currency euros.
    for(Currency* i : vbucks) {
        cout << i->toString() << endl;
    }*/

    return 0;
}
