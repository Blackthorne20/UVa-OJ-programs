// OddSum.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b, sum = 0;
        cin >> a >> b;
        if (a % 2 == 0)
        {
            a++;
        }
        while (a <= b)
        {
            sum += a;
            a += 2;
        }

        cout << "Case " << i + 1 << ": " << sum << endl;
    }

    return 0;
}

