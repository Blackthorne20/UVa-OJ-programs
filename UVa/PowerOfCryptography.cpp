// PowerOfCryptography.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;

#define end '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double n;
    long double p;

    while (cin >> n >> p)
    {
        cout << lround(pow(p, 1 / n)) << endl;
    }

    return 0;
}

