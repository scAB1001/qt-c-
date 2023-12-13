//
// Do not change this file - but you might edit the arguments passed to main:
//  - Projects (spanner on right)
//  - Under "Build and Run", select "Run" (small green arrow)
//  - Edit "Command line arguments" (main panel)
//
// v1: initial release
// v2: removed std:: from some strings & allowed students to edit the Location class
//

#include <string>
#include <iostream>

#include "cave.h"
#include "test.cpp"
#include "throw.h"
#include "place.h"
#include "move.h"
#include "explode.h"

using namespace std;


int main(int argc, char** argv) {

    int width = 8, height = 8; // provided code only works for these values(!)

    if (argc == 3) {
        width  = stoi (argv[1]);
        height = stoi (argv[2]);
    }

    if (argc != 2) {
        Cave c(width, height);

        string input;
        while (true) {
            c.show();
            cout << ">";
            getline(cin, input);

            if (input.compare("exit") == 0)
                break;

            // Create a temporary instance of Move/Place/Throw class
            //  calls triggersOn(input) which may result in a command.

            // Handle the "move" command
            else if (Move().triggersOn(input))
                Move().fire(c, input);
            // Handle the "place" command
            else if (Place().triggersOn(input))
                Place().fire(c, input);
            // Handle the "throw" command
            else if (Throw().triggersOn(input))
                Throw().fire(c, input);
            else if (Explode().triggersOn(input))
                Explode().fire(c, input);
            else
                cerr << "Invalid command: " << input << endl;
            //c.command(input);
        }
    }
    else test();
}
