// Exponentiation.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long double a;
    int b;

    cin >> a >> b;
    long double c = pow(a, b);
    cout << pow(a, b) << endl;

    return 0;
}

