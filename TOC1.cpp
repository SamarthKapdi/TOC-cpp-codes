#include <iostream>
#include <string>
#include <cstddef>
using namespace std;

bool check_111(string input); // define
// true false
int main()
{
    string input;
    cout << "Samarth Kapdi" << endl;
    cout << "Enter a string: ";
    cin >> input;

    if (check_111(input))
    {
        cout << "accepted" << endl;
    }
    else
    {
        cout << "rejected" << endl;
    }
    // declare
}

// Define check_111 outside main
bool check_111(string input)
{
    int state = 0;
    for (std::size_t i = 0; i < input.length(); ++i)
    {
        char c = input[i];
        switch (state)
        {
        case 0:
            if (c == '1')
                state = 1;
            else
                state = 3;
            break;
        case 1:
            if (c == '1')
                state = 2;
            else
                state = 3;
            break;
        case 2:
            if (c == '1')
                state = 2;
            else
                state = 3;
            break;
        case 3:
            state = 3;
            break;
        }
    }
    // Accept if state == 2 (three consecutive '1's)
    return state == 2;
}
