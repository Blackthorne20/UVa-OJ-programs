/*
10260 - Soundex

This program reads in a word and outputs its id based on the value-assigned letters.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string letters = "BFPVCGJKQSXZDTLMNR";
    int values[] = { 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 4, 5, 5, 6 };

    // associative array
    vector<int> ascii(128, 0);
    for (int i = 0; i < letters.size(); i++)
    {
        ascii[letters[i]] = values[i];
    }

    string word;
    while (cin >> word)
    {
        int last = 0;
        for (auto c : word)
        {
            int v = ascii[c];
            if (v != 0 && v != last) // the letter cannot have same value as the previous letter
            {
                cout << v;
            }
            last = v;
        }
        cout << endl;
    }

    return 0;
}

