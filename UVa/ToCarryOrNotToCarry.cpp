// ToCarryOrNotToCarry.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned a, b;
    while (cin >> a >> b)
    {
        int c = a ^ b;
        cout << c << endl;
    }

    return 0;
}

