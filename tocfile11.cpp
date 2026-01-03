#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    // Read input string (no spaces)
    string input;
    cout << "Samarth Kapdi, 0863CS231141" << endl;
    cout << "enter a string ";
    cin >> input;

    // Reverse the string
    string rev_str = input;
    for (int i = 0; i < static_cast<int>(rev_str.length()) / 2; i++)
    {
        swap(rev_str[i], rev_str[rev_str.length() - 1 - i]);
    }
    cout << "reverse string " << rev_str << endl;

    // Push input characters into a stack
    stack<char> pda;
    for (char c : input)
        pda.push(c);

    // Compare stack top with reversed string
    int i = 0;
    while (!pda.empty())
    {
        if (pda.top() == rev_str[i])
        {
            i++;
            pda.pop();
        }
    }

    // If stack is empty, it matched
    if (pda.empty())
        cout << "valid";
    else
        cout << "invalid";

    return 0;
}
