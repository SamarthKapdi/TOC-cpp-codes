#include <iostream>
#include <string>
#include <stack>

using namespace std;

class PDA
{
public:
    stack<char> stack1;

    bool check_paranthesis(string input)
    {
        // loop to iterate the parenthesis
        for (char c : input)
        {
            // if c == '(' push into pda
            if (c == '(')
            {
                stack1.push(c);
            }
            else if (c == ')')
            {
                stack1.pop();
            }
        }
        return stack1.empty();
    }
};

int main()
{
    string input;
    cout << "Samarth Kapdi, 0863CS231141" << endl;
    cout << "enter a string of paranthesis :";
    cin >> input;

    PDA pda;
    if (pda.check_paranthesis(input))
    {
        cout << "correct paranthesis" << endl;
    }
    else
    {
        cout << "incorrect paranthesis";
    }
}
