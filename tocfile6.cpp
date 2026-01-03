#include <iostream>
#include <stack>
using namespace std;

class count_0_1
{
public:
    stack<char> pda; // create an stack array of char type
    // create a function to count 0 and 1

    void count_01(string input)
    {
        // write all code here

        // loop to insert 0 and 1 in stack
        for (char c : input)
        {
            pda.push(c);
        }

        // declare count_0 and count_1
        int count_0 = 0, count_1 = 0;
        while (!pda.empty())
        {
            char point = pda.top(); //~! set pointer on the top of stack
            pda.pop();
            if (point == '0')
            {
                count_0++;
            }
            else
            {
                count_1++;
            }
        }
        cout << "total 0 = " << count_0 << endl;
        cout << "total 1 = " << count_1 << endl;
    }
};

int main()
{
    count_0_1 c1; // create object
    string input;
    cout << "Rohit Rajure, 0863CS231137" << endl;
    cout << "enter the binary string :";
    cin >> input;
    // call function
    c1.count_01(input);
}