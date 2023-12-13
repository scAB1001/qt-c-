#include <string>
#include <iostream>
#include <vector>

using namespace std;

double avg_arr(double numbers[], int size) {
    double sum = 0;

    for(int i = 0; i < size; i++) {
        sum += numbers[i];
    }

    return sum / size;
}

double avg_vect(vector<double> numbers) {
    double sum = 0;

    for(double i : numbers) {
        sum += numbers[i];
    }

    return sum / numbers.size();
}

int main() {
    /*
    vector<string> words;
    words.push_back("Apple");       // puts "Apple" at end
    words.push_back("Banana");      // "Banana" after "Apple"
    words.push_back("Kiwi");        // "Kiwi" after "Banana"

    cout << words.size() << endl;   // prints 3
    cout << words[1] << endl;       // prints Banana
    cout << words.at(1) << endl;    // same as above,

    // but at() does bounds checking
    words.pop_back();               // removes "Kiwi"

    cout << words.size() << endl;   // prints 2
    words.clear();                  // vector now empty
    */

    // Write program to avg 5 doubles from cli using arrays
    double dubs[5], summ;

    for(int i = 0; i < 5; i++) {
        cout << i << " > ";
        cin >> dubs[i];
    }
    int sizer = sizeof(dubs)/sizeof(double);
    summ = avg_arr(dubs, sizer); // Fixed the function call syntax
    cout << "Average: " << summ << endl;

    // Modify the program to use a vector<double> instead of an array.
    double x;
    vector<double> dub;
    for (int i = 0; i < 5; i++)
    {
        cout << i << " > ";
        cin >> x;
        dub.push_back(x);
    }
    summ = avg_vect(dub);

    cout << "Average: " << summ << endl;
    return 0;
}
