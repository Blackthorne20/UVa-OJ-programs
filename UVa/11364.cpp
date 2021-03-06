// Parking_11364.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        int x, max = INT_MIN, min = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            if (x > max)
            {
                max = x;
            }
            if (x < min)
            {
                min = x;
            }
        }

        cout << 2 * (max - min) << endl;
    }

    return 0;
}

