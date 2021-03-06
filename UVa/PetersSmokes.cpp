// PetersSmokes.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while (cin >> n >> k)
    {
        int r = n, m = 0;
        while (r >= k)
        {
            m = r % k;
            r /= k;
            n += r;
            r += m;
        }
        cout << n << endl;
    }

    return 0;
}

