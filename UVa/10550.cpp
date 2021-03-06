// CombinationLock_10550.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, f, s, t;
    cin >> i >> f >> s >> t;
    while (!(i == 0 && f == 0 && s == 0 && t == 0))
    {
        int ans = 1080;
        ans += 9 * (f > i ? 40 - (f - i) : i - f);
        ans += 9 * (s >= f ? s - f : 40 - (f - s));
        ans += 9 * (t > s ? 40 - (t - s) : s - t);

        cout << ans << endl;

        cin >> i >> f >> s >> t;
    }

    return 0;
}

