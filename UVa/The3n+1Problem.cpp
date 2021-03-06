// The3n+1Problem.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long i, j;

    while (cin >> i >> j)
    {
        int maxCycleLength = 0;

        cout << i << " " << j << " ";
        for (unsigned long k = min(i, j); k <= max(i, j); k++)
        {
            unsigned long l = k;
            int cycleLength = 1;
            while (l != 1)
            {
                if ((l % 2) == 1)
                {
                    l = 3 * l + 1;
                }
                else
                {
                    l = l / 2;
                }
                cycleLength++;
            }
            if (cycleLength > maxCycleLength)
            {
                maxCycleLength = cycleLength;
            }
        }
        cout << maxCycleLength << endl;
    }
    return 0;
}

