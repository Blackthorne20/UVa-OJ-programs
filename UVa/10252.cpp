// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define endl '\n'
constexpr auto numLetters = 26;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    while (getline(cin, a))
    {
        getline(cin, b);
        vector<int> freqA(numLetters, 0), freqB(numLetters, 0);

        for (auto c : a)
        {
            ++freqA[c - 'a'];
        }
        for (auto c : b)
        {
            ++freqB[c - 'a'];
        }
        for (int i = 0; i < numLetters; ++i)
        {
            int l = min(freqA[i], freqB[i]);
            for (int j = 0; j < l; ++j)
            {
                cout << (char)(i + 'a');
            }
        }
        cout << endl;
    }

    return 0;
}

