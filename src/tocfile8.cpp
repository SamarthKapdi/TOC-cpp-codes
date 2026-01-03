#include <iostream>
#include <string>
using namespace std;

class Increment
{
public:
    string input;
    Increment(string binput)
    {
        input = binput;
    }

    void do_inc()
    {
        string result = input;
        int carry = 1; //~! we need to add 1
        for (int i = result.length() - 1; i >= 0; i--)
        {
            if (result[i] == '1' && carry == 1)
            {
                result[i] = '0';
                carry = 1;
            }
            else if (result[i] == '0' && carry == 1)
            {
                result[i] = '1';
                carry = 0;
            }
        }

        if (carry == 1)
            result = "1" + result;
        cout << "binary input = " << input << endl;
        cout << "binary increment =" << result << endl;
        // No return needed for a void function
    }
};

int main()
{
    string input;
    cout << "Rohit Rajure, 0863CS231137" << endl;
    cout << "enter binary string :";
    cin >> input;
    Increment c1(input); // object c1
    c1.do_inc();
    return 0;
}