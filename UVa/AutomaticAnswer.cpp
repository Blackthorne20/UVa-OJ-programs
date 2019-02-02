// AutomaticAnswer.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short t;
    cin >> t;

    for (unsigned short i = 0; i < t; i++)
    {
        long num;
        double ans;
        short n, digit;
        cin >> n;

        ans = (((n * 567 / 9) + 7492) * 235 / 47) - 498;
        num = lround(ans);
        num /= 10;
        cout << abs(num % 10) << endl;
    }


    return 0;
}

