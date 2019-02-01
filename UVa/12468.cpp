// UVa.cpp : Defines the entry point for the console application.
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

    int a, b;
    while (cin >> a >> b, !(a == -1 && b == -1))
    {
        cout << min(abs(a - b), 100 - abs(a - b)) << endl;
    }

    return 0;
}

