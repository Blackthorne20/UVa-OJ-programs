// HashmatTheBraveWarrior.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long m, n;
    while (cin >> m >> n)
    {
        cout << abs(m - n) << endl;
    }
    return 0;
}

