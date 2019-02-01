// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <iomanip>
using namespace std;

#define endl '\n'

const double r = 5.0 / 9.0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i)
    {
        double C, d;
        cin >> C >> d;
        cout << "Case " << i << ": " << fixed << setprecision(2) << C + d * r << endl;
    }

    return 0;
}

