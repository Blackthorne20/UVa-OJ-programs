// PizzaCutting.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;

    while (N >= 0)
    {
        cout << (N * N + N + 2) / 2 << endl;
        cin >> N;
    }

    return 0;
}

