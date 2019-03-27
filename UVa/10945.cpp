/*
10945 - Mother Bear

This program reads in a line and checks whether or not it's a palindrome.
*/
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line), line != "DONE")
    {
        // copy line to a (remove puncuation and spaces, and make all letters lowercase)
        string a = "";
        for (auto c : line)
        {
            if (isalpha(c))
            {
                a = a + (char)tolower(c);
            }
        }

        // copy a to b and reverse b
        string b = a;
        reverse(b.begin(), b.end());

        // compare a to b
        if (a == b)
        {
            cout << "You won't be eaten!" << endl;
        }
        else
        {
            cout << "Uh oh.." << endl;
        }
    }

    return 0;
}

