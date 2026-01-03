#include <iostream>
#include <string>
using namespace std;

// Function declaration
bool is_divisible_by_2(string input);

int main()
{
    string input;
    cout << "Name, Rol No \n";
    cout << "Enter a decimal number: ";
    cin >> input;

    if (is_divisible_by_2(input))
    {
        cout << "Accepted" << endl;
    }
    else
    {
        cout << "Rejected" << endl;
    }
    return 0;
}

// Function definition
bool is_divisible_by_2(string input)
{
    // state 0 is the initial state and also the final state
    int state = 0;

    for (char c : input)
    {
        switch (state)
        {
        // current state is 0 (number is even)
        case 0:
            if (c == '0' c == '2' c == '4' c == '6' c == '8')
            {
                state = 0; //~& remains even
            }
            else
            {              // '1', '3', '5', '7', '9'
                state = 1; //~& becomes odd
            }
            break;

        // current state is 1 (number is odd)
        case 1:
            if (c == '0' c == '2' c == '4' c == '6' c == '8')
            {
                state = 0; // becomes even
            }
            else
            {              // '1', '3', '5', '7', '9'
                state = 1; // remains odd
            }
            break;
        }
    }

    // Accept if the final state is 0 (even)
    return (state == 0);
}