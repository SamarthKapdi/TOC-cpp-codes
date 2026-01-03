#include <iostream>
#include <string>
using namespace std;

//~! declare a function
bool end_with_101(string input);

int main()
{
    string input;
    cout << "Rohit Rajure, 0863CS231137" << endl;
    cout << "enter the string :";
    cin >> input;
    if (end_with_101(input))
    { // true
        cout << "accepted" << endl;
    }
    else
    { // false
        cout << "rejected" << endl;
    }
    return 0;
}

// define function here
bool end_with_101(string input)
{ // input 101110
    // lets create an initial state 0
    int state = 0;
    for (char c : input)
    {
        switch (state)
        {
        case 0: //~! initial state 0
            if (c == '1')
                state = 1; // go to state 1
            else
                state = 0; // go to stat 0
            break;

        case 1: //~! now when you are on state 1
            if (c == '1')
                state = 1; // go to state 1
            else
                state = 2; // go to state 2
            break;
        case 2: //~! state 2
            if (c == '1')
                state = 3; // go to state 3
            else
                state = 0;
            break;

        case 3:
            if (c == '1')
                state = 1; // go to state 1
            else
                state = 2; // go to state 2
            break;
        }
    }
    return (state == 3);
}