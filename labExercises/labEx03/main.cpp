#include <iostream>
#include <string>
using namespace std;

int main()
{
    string target = "World";
    string message = "Hey " + target + "!";

    int msgLen = message.length();
    cout << message << endl;

    for (int i = msgLen; i > 0; i--) {
        string msg = message.substr (0, i);
        cout << msg << endl;
    }

    return 0;
}
