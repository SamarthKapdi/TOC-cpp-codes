#include <iostream>
#include <string>
using namespace std;

bool divisibleBy2(string input);

int main()
{
    string input;
    cout << "enter string :";
    cin >> input;

    if (divisibleBy2(input))
        cout << "accepted " << endl;
    else
        cout << "rejected " << endl;
}
bool divisibleBy2(string input)
{
    int state = 0; //! state 0 = final (last digit 0), state 1 = non-final (last digit 1)

    for (char c : input)
    {
        switch (state)
        {
        case 0: // state 0 (last digit is 0)
            if (c == '0')
                state = 0; // stay in final
            else
                state = 1; // go to state 1
            break;

        case 1: // state 1 (last digit is 1)
            if (c == '0')
                state = 0; // back to final
            else
                state = 1; // remain in state 1
            break;
        }
    }
    return state == 0; // accepted only if last digit is 0
}