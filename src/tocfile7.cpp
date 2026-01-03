#include <iostream>
#include <string>
using namespace std;

class Compliment
{
public:
    string binary;
    // create a constructor
    Compliment(string input)
    {
        binary = input;
    }
    // create a method/function to find ones complement
    string ones()
    {
        string result = ""; // empty string
        for (char c : binary)
        {
            if (c == '0')
            {
                result = result + "1";
            }
            else
            {
                result = result + "0";
            }
        }
        return result;
    }

    // function to display result
    void display()
    {
        cout << "the given string is :" << binary << endl;
        cout << "ones compliment is  :" << ones() << endl;
    }
    string twos()
    {
        string result = ones();
        int carry = 1;
        for (int i = result.length() - 1; i >= 0; i--)
        { // reserve order
            // when last digit is 1 and carry is 1 make it 0 and carry must be 1
            if (result[i] == '1' && carry == 1)
            {
                result[i] = '0'; // update 1 to 0
                carry = 1;       // carry remain same
            }
            else if (result[i] == '0' && carry == 1)
            {                    // last digit is 0 and carry is 1
                result[i] = '1'; // update 0 to 1
                carry = 0;       // carry changes to 0
                break;
            }
        }
        if (carry == 1)
        {
            result = "1" + result;
        }

        return result; // go to line 47 eee
    }

    // function to display 2s compliment
    void two_display()
    {
        cout << "twos compliment is :" << twos() << endl;
    }
};

int main()
{
    string input;
    cout << "Rohit Rajure, 0863CS231137" << endl;
    cout << "enter binary no :";
    cin >> input;
    Compliment c1(input);
    c1.ones();    // ones complement
    c1.display(); // display the result
    c1.twos();
    c1.two_display();
}