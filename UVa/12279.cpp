// UVa.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, t = 1;
    while (cin >> N, N != 0)
    {
        int ans = 0;
        for (int i = 0; i < N; ++i)
        {
            int n;
            cin >> n;
            ans += n == 0 ? -1 : 1;
        }
        cout << "Case " << t++ << ": " << ans << endl;
    }

    return 0;
}

