/*
10324 - Zeros and Ones

problem description: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1265
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;

    string line;
    while (cin >> line)
    {
        cout << "Case " << t << ":" << endl;
        int n;
        cin >> n;

        int i, j;
        for (int k = 0; k < n; k++)
        {
            cin >> i >> j;
            if (i > j)
            {
                swap(i, j);
            }

            char digit = line[i];
            if (all_of(line.begin() + i, line.begin() + j + 1, [digit](char c) {return c == digit; }))
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }

        t++;
    }

    return 0;
}

