// SummingDigits.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int addDigits(int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n;
    cin >> n;
    while (n != 0)
    {
        cout << addDigits(n) << endl;
        cin >> n;
    }

    return 0;
}

int addDigits(int n)
{
    if (n < 10)
    {
        return n;
    }
    else
    {
        int sum = 0;
        while (n)
        {
            sum += n % 10;
            n /= 10;
        }
        return addDigits(sum);
    }
}

