// SquareNumbers.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    while (a != 0.0f || b != 0.0f)
    {
        if (a == 0)
        {
            a++;
        }
        cout << floor(sqrt(b)) - ceil(sqrt(a)) + 1 << endl;
        cin >> a >> b;
    }

    return 0;
}

