#include "person.h"
#include <iostream>

using namespace std;

// Constructor implementation
Person::Person(string n, int a) : name(n), age(a) {}

// Implementation of printName function
void Person::printDetails() {
    cout << name << ": " << age << endl;
}
