#include <string>
#include <iostream>
#include <vector>

#include "money.h"

using namespace std;

int main()
{
    cout << endl;
    Money m1(2, 50);
    Money m2(0, 42);
    Money sum = m1+m2;

    try {
        Money m3 (23, 101);
    } catch (invalid_argument const& e ) {
        cout << "invalid argument " << e.what() << endl;
    }

    cout << "Sum = " << sum.toString() << endl;

    cout << endl;
    return 0; // everything went as planned
}
