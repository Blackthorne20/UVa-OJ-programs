// AllInAll.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    while (cin >> s >> t)
    {
        int i = 0;
        for (auto c : t)
        {
            if (c == s[i])
            {
                i++;
            }
        }
        if (i == s.length())
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }

    return 0;
}

