// ConsecutiveIntegers.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    while (n != -1)
    {
        int j;
        for (int r = lround(sqrt(2 * n)); r >= 1; r--)
        {
            double a = (2 * n + r - pow(r, 2)) / (2 * r);
            if ((int)a == a)
            {
                j = lround(a);
                cout << n << " = " << j << " + ... + " << j + r - 1 << endl;
                break;
            }
        }

        cin >> n;
    }

    return 0;
}

