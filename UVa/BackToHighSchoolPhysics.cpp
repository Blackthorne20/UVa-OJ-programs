// BackToHighSchoolPhysics.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, t;
    while (cin >> v >> t)
    {
        v *= 2;
        t *= 2;

        cout << v / 2 * t << endl;
    }
    return 0;
}

