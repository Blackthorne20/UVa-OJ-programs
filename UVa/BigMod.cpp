// BigMod.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
#include "BigInteger.h"
using namespace std;

#define endl '\n'

BigInteger raise(BigInteger &B, int P)
{
    if (P == 0)
    {
        return 1;
    }
    else if (P == 1)
    {
        return B;
    }
    else
    {
        BigInteger res(raise(B, P / 2));
        res *= res;
        if (P % 2 == 1)
        {
            res *= B;
        }
        return res;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int B, P, M;
    while (cin >> B >> P >> M)
    {
        BigInteger C(B);
        C = raise(C, P) % M;
        cout << string(C) << endl;
    }

    return 0;
}

