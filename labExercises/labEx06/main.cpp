#include <string>
#include <iostream>
#include <vector>

#include "person.h"

using namespace std;

//int argc, char* argv[]
int main() {
    /*
    if (argc != 4) {
        cout << "Usage: <name1> <age1> <name2> <age2>..." << endl;
        return 1;
    }
    */

    vector<Person> people;
    int input;
    cout << "How many people are we describing today?" << endl;
    cin >> input;

    string name;
    int age;

    for (int i = 0; i < 2*input; i += 2) {
        cout << "Person: " << i << ": Enter their name then age" << endl;
        cin >> name;
        cin >> age;
        people.push_back(Person(name, age));
    }

    for (auto& person : people) {
        person.printDetails();
    }

    return 0;
}

