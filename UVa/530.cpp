// Binomial Showdown
//
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    while (cin >> n >> k, n || k)
    {
        unsigned long long ans = 1;
        k = min(k, n - k);
        
        for (int i = 0; i < k; i++)
        {
            ans = ans * (n - i) / (1 + i);
        }

        cout << ans << endl;
    }

    return 0;
}

