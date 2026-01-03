#include <iostream>
#include <stack>
#include <string>
using namespace std;

class PDA
{
public:
    stack<char> pda; // create a stack char type --> pda

    // create a method --> check_0_1
    bool check_0_1(string input)
    {
        // write logic here
        // for every new string pop the elements
        while (!pda.empty())
        {
            pda.pop();
        }
        for (char c : input)
        {
            if (!pda.empty() && pda.top() != c)
            {
                pda.pop();
            }
            else
            {
                pda.push(c);
            }
        }
        return pda.empty();
    }
};

int main()
{
    PDA p1;
    string input;
    cout << "Rohit Rajure, 0863CS231137 \n";
    cout << "enter a binary string :";
    cin >> input;
    if (p1.check_0_1(input))
    {
        cout << "equal number " << endl;
    }
    else
    {
        cout << "not equal " << endl;
    }
}