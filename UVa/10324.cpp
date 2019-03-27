/*
10324 - Zeros and Ones

This program reads in a string of zeros and ones and determines if all the digits in a 
given range are the same
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

    int t = 1; // test case

    string line;
    while (cin >> line)
    {
        cout << "Case " << t << ":" << endl;
        int n; // number of ranges
        cin >> n;

        int i, j;
        for (int k = 0; k < n; k++)
        {
            cin >> i >> j; // i = start index, j = end index
            if (i > j)
            {
                swap(i, j);
            }

            // check if all digits in the range are the same
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

