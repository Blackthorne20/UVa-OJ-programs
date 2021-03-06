// What'sCryptanalysis.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <cctype>
#include <vector>
using namespace std;

#define endl '\n'

bool sortbysec(const pair<int, int> &a,
    const pair<int, int> &b)
{
    if (a != b)
    {
        return (a.second > b.second);
    }
    else
    {
        return(a.first > b.first);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    vector<int> table(127, 0);
    vector<pair<char, int>> frequency;
    frequency.reserve(26);
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);

        for (auto c : line)
        {
            c = toupper(c);
            if (isalpha(c))
            {
                table[c]++;
            }
        }
    }

    for (int i = 65; i <= 90; i++)
    {
        if (table[i] > 0)
        {
            frequency.push_back(make_pair((char)i, table[i]));
        }
    }

    sort(frequency.begin(), frequency.end(), sortbysec);

    for (auto c : frequency)
    {
        cout << c.first << " " << c.second << endl;
    }

    return 0;
}

