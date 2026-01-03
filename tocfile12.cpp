#include <iostream>
#include <string>
using namespace std;

class TuringMachine
{
public:
    string tape;

    bool run(string input)
    {
        tape = input;
        int n = tape.length();

        // Loop until all 'a's are marked
        while (true)
        {
            int i = 0;
            while (i < n && tape[i] != 'a')
                i++; // find first 'a'

            if (i == n)
                break; // No 'a' left, check marks

            tape[i] = 'X'; // mark 'a' as 'X'

            // find matching 'b'
            int j = i + 1;
            while (j < n && tape[j] != 'b')
                j++;
            if (j == n)
                return false; // 'b' not found
            tape[j] = 'Y';    // mark 'b' as 'Y'

            // find matching 'c'
            int k = j + 1;
            while (k < n && tape[k] != 'c')
                k++;
            if (k == n)
                return false; // 'c' not found
            tape[k] = 'Z';    // mark 'c' as 'Z'
        }

        for (char c : tape)
        {
            if (c != 'X' && c != 'Y' && c != 'Z')
                return false;
        }
        return true;
    }
};

int main()
{
    string input;
    cout << "Samarth Kapdi, 0863CS231141" << endl;
    cout << "Enter string (e.g., aabbcc): ";
    cin >> input;

    TuringMachine tm;
    // run the machine
    if (tm.run(input))
        cout << "String Accepted (Format a^n b^n c^n)" << endl;
    else
        cout << "String Rejected" << endl;

    return 0;
}