// Cola11150.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N)
    {
        cout << N + floor(N / 2.0f) << endl;
    }

    return 0;
}

