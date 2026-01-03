#include <iostream>
#include <string>
using namespace std;
// declare a function
bool issub_111(string input);
int main()
{
    string input;
    cout << "Rohit Rajure, 0863CS231137" << endl;
    cout << "enter the string :";
    cin >> input;
    if (issub_111(input))
    { // true
        cout << "accepted" << endl;
    }
    else
    {
        // false
        cout << "rejected" << endl;
    }
    return 0;
}
// define function here
bool issub_111(string input)
{ // input 101110
    // lets create an intital state 0
    int state = 0;
    for (char c : input)
    {
        switch (state)
        {
        case 0:
            // initial state 0
            if (c == '1')
            {
                state = 1;
            }
            else
            {
                state = 0;
            }
            break;
        // go to next state 1
        // remain on same state
        case 1:
            // now when you are on state 2
            if (c == '1')
            {
                state = 2;
            }
            // go to next state 2
            else
            {
                state = 0;
            }
            // go to next state 0
            break;
        case 2:
            if (c == '1')
            {
                state = 3;
            }
            // go to final state
            else
            {
                state = 0;
            }
            break;
            // go to next state 0
        }
    }
    return (state == 3);
}