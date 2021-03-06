// TriangleWave.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
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
        int a, f;
        cin >> a >> f;

        for (int j = 0; j < f; j++)
        {
            for (int k = 0; k < a * 2; k++)
            {
                for (int l = 0, m = a - abs(a - k); l < m; l++)
                {
                    cout << m;
                }
                if (i > 0 || j > 0 || k > 0)
                {
                    cout << endl;
                }
            }
        }
    }

    return 0;
}

