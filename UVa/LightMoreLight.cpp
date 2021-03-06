// LightMoreLight.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n;
    cin >> n;

    while (n != 0)
    {
        double sr = sqrt(n);
        if (sr - floor(sr) == 0)
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
        cin >> n;
    }

    return 0;
}

