// SearchingForNessy.cpp : Defines the entry point for the console application.
//

#include <iostream>
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
        int n, m;
        cin >> n >> m;

        cout << (n / 3) * (m / 3) << endl;
    }
    return 0;
}

