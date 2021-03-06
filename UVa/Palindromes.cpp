// Palindromes.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string chars = "AEHIJLMOSTUVWXYZ12358";
    string rev = "A3HILJMO2TUVWXY51SEZ8";
    map<char, char> list;
    for (int i = 0; i < chars.size(); i++)
    {
        list.insert(make_pair(chars[i], rev[i]));
    }

    string word;
    while (cin >> word)
    {
        bool isPalindrome = false, isMirrored = false, valid = false;
        string temp = word;
        reverse(word.begin(), word.end());
        if (word == temp)
        {
            isPalindrome = true;
        }

        for (int i = 0; i < word.size(); i++)
        {
            if (list.count(word[i]) != 0)
            {
                word[i] = list[word[i]];
                valid = true;
            }
            else
            {
                valid = false;
                i = word.size();
            }
        }
        if (word == temp && valid)
        {
            isMirrored = true;
        }

        if (isPalindrome)
        {
            if (isMirrored)
            {
                cout << temp << " -- is a mirrored palindrome." << endl;
            }
            else
            {
                cout << temp << " -- is a regular palindrome." << endl;
            }
        }
        else if (isMirrored)
        {
            cout << temp << " -- is a mirrored string." << endl;
        }
        else
        {
            cout << temp << " -- is not a palindrome." << endl;
        }
        cout << endl;
    }

    return 0;
}

