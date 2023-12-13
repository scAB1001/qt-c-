#include <iostream>
#include <Array>
#include <Deque>
#include <Vector>
#include <forward_list>
#include <list>
#include <Stack>
#include <Queue>
#include <Set>
#include <Map>
#include <Unordered_set>
#include <Unordered_map>
#include <Unordered_map>

using namespace std;

int main()
{
    map<string, float> myfloats{ {"pi:", 3.14f}, {"zero:", 0.0f} };
    myfloats.insert({ "sqrt2:", 1.41421f });
    myfloats.insert(pair<string, int>("golden ratio:", 1.61803f));

    /* In C++, when iterating through a map,
    //the key-value pairs are of type const pair<const Key, T>&
    //both the key and value are constant.
    //for (const pair<string, int> p : myfloats) {
    //    cout << p.first << " "<< p.second << endl;
    //}

    // &: This is the reference operator. It indicates that p is a reference to an existing object.
    // Useful when dealing with large objects or classes, as it avoids unnecessary copying.
    // "let the compiler figure out the type of p, regardless, p should be a const ref to that type"
    */
    for (const auto& p : myfloats) {
        cout << p.first << " "<< p.second << endl;
    }

    cout << endl << "iterating thru v{}" << endl;
    vector<int> v = { 1, 3, 4, 6123, 1 };

    // Conventional to use auto to iterate
    // We use *i because i gives the value pointed to in the vector
    for (auto i = v.begin(); i != v.end(); i++) {
        cout << *i << endl;
    }
    /* Can also use a generated iterator for the data structure
    vector<int>::iterator itr;
    for (itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << endl;
    //}
    */

    cout << endl;

    return 0;
}
