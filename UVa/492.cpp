// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <bitset>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string vowels = "AEIOUaeiou";
    bitset<128> isVowel;
    for (auto c : vowels)
    {
        isVowel[c] = true;
    }

    string line;
    while (getline(cin, line))
    {
        bool wordFound = false, printConsonant = false;
        char consonant;

        for (auto c : line)
        {
            if (isalpha(c))
            {
                if (isVowel[c])
                {
                    if (!wordFound)
                    {
                        printConsonant = false;
                    }
                    cout << c;
                }
                else
                {
                    if (wordFound)
                    {
                        cout << c;
                    }
                    else
                    {
                        consonant = c;
                        printConsonant = true;
                    }
                }
                wordFound = true;
            }
            else
            {
                if (wordFound)
                {
                    wordFound = false;
                    if (printConsonant)
                    {
                        cout << consonant;
                    }
                    cout << "ay";
                }
                cout << c;
            }
        }

        if (wordFound)
        {
            if (printConsonant)
            {
                cout << consonant;
            }
            cout << "ay";
        }
        cout << endl;
    }

    return 0;
}

