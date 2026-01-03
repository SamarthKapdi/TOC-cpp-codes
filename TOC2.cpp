#include <iostream>
#include <string>

using namespace std;

bool mode_3(string input)
{
    int state = 0; // initial and final state
    for (char c : input)
    {
        switch (state)
        {
        case 0:
            if (c == '0')
                state = 0;
            else
                state = 1;
            break;
        case 1:
            if (c == '1')
                state = 0;
            else
                state = 2;
            break;
        case 2:
            if (c == '1')
                state = 2;
            else
                state = 1;
            break;
        }
    }
    return state == 0;
}

bool mode_3(string input);

int main()
{
    string input;
    cout << "enter string :";
    cin >> input;
    if (mode_3(input))
        cout << "accepted " << endl;
    else
        cout << "rejected " << endl;
}