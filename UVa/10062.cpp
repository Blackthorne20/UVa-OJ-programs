/*
10062 - Tell me the frequencies!

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1003
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

bool sortBySec(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first > b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    bool addBlankLine = false;
    string line;
    while (getline(cin, line))
    {
        // insert blank line between test cases
        if (addBlankLine)
        {
            cout << endl;
        }
        else
        {
            addBlankLine = true;
        }

        vector<pair<int, int>> ascii(128, { 0, 0 }); // associative array where key = an ascii value, and value = a pair containing
                                                     // the ascii value and the number of times the ascii character appears in line
                                                     // (this is done because the array needs to be sorted)

        for (auto c : line)
        {
            ascii[c].first = c;
            ascii[c].second++;
        }

        sort(ascii.begin(), ascii.end(), sortBySec); // sorts by frequency in ascending order, then by ascii value in decreasing order

        for (auto i : ascii)
        {
            if (i.second > 0)
            {
                cout << i.first << " " << i.second << endl;
            }
        }
    }

    return 0;
}

