// PrimaryArithmetic.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned long m, n;
    cin >> m >> n;
    while (!(m == 0 && n == 0))
    {
        unsigned short numCarries = 0;
        bool carryover = false;
        while (!(m == 0 && n == 0))
        {
            unsigned short digit1 = m % 10, digit2 = n % 10, sumDigits = digit1 + digit2;
            if (sumDigits >= 10)
            {
                numCarries++;
                carryover = true;
            }
            else if (sumDigits == 9 && carryover)
            {
                numCarries++;
            }
            else
            {
                carryover = false;
            }
            m /= 10;
            n /= 10;
        }
        switch (numCarries)
        {
        case(0):
            cout << "No carry operation." << endl;
            break;
        case(1):
            cout << "1 carry operation." << endl;
            break;
        default:
            cout << numCarries << " carry operations." << endl;
            break;
        }
        cin >> m >> n;
    }
    return 0;
}

