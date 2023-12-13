#ifndef PERSON_H                                        // Include guards to prevent multiple inclusions
#define PERSON_H

#include <string>
using namespace std;

class Person {
public:
    string name;                                        // Data member to store the name of the person
    int age;                                            // Data member to store the age of the person
    Person(string n, int a) : name(n), age(a) {};       // Constructor to initialize the name
    void printDetails();                                // Function to print the person's details

};

#endif                                                  // PERSON_H
