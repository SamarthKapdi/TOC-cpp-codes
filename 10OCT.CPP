#include <iostream>
#include <string>
using namespace std;

class Compliment
{

public:
    string input;
    Compliment(string binput)
    { // constructor

        input = binput;
    }

    // method ones

    string ones()
    {
        string result = "";
        for (size_t i = 0; i < input.size(); ++i)
        {
            char c = input[i];
            if (c == '0')
                result = result + '1';
            else
                result = result + '0';
        }
        cout << "binary input:" << input << endl;
        cout << "1's compliment:" << result << endl;
        return result;
    }
};

int main()
{
    string input;
    cout << "Samarth Kapdi &  0863CS231141" << endl;

    cout << "enter binary string:";
    cin >> input;
    Compliment c1(input); // 1st object
}