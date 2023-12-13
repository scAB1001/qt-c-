#include <iostream>

using namespace std;

// Reference the memory address of var x and y, swap their contents.
void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
}

int& getLarger(int& x, int& y)
{
    return (x > y) ? x : y;
}

void doubleValue(int& num)
{
    num *= 2;
}

int main()
{
    int a, b, x;
    cout << "Enter 3 values: a, b and x" << endl;

    cout << endl << "a: ";
    cin >> a;
    cout << endl << "b: ";
    cin >> b;
    cout << endl << "x: ";
    cin >> x;


    cout << endl << a << "," << b << endl;


    doubleValue(x); // 'x' will now be 10
    cout << a << ", " << b << ", " << x << endl;

    getLarger(a, b) = 20;
    cout << a << ", " << b << endl;

    swap(a, b);
    cout << a << ", " << b << endl;


    return 0;
}
