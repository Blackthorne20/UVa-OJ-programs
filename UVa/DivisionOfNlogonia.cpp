// DivisionOfNlogonia.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, m, n;
    cin >> k;
    while (k != 0)
    {
        cin >> m >> n;
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;

            if (x == m || y == n)
            {
                cout << "divisa" << endl;
            }
            else if (x > m && y > n)
            {
                cout << "NE" << endl;
            }
            else if (x > m && y < n)
            {
                cout << "SE" << endl;
            }
            else if (x < m && y > n)
            {
                cout << "NO" << endl;
            }
            else if (x < m && y < n)
            {
                cout << "SO" << endl;
            }
        }
        cin >> k;
    }
    return 0;
}

