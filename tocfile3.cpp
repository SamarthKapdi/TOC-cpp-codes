#include <iostream>
#include <string>
using namespace std;

bool mode_3(string input);

int main()
{
    string input;
    cout << "Rohit Rajure, 0863CS231137" << endl;
    cout << "enter string :";
    cin >> input;
    if (mode_3(input))
        cout << "accepted " << endl;
    else
        cout << "rejected " << endl;
}

bool mode_3(string input)
{
    int state = 0; // initial and final state
    for (char c : input)
    {
        switch (state)
        {
        case 0: // for state 0
            if (c == '0')
                state = 0;
            else
                state = 1; // go to state 1
            break;
        case 1: // for state 1
            if (c == '1')
                state = 0; // final
            else
                state = 2; // go to state 2
            break;

        case 2: // for state 2
            if (c == '1')
                state = 2; // remain on same state
            else
                state = 1; // go to state 1
            break;
        }
    }
    return state == 0;
}