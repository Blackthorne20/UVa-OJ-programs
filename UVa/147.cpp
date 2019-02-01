// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'
#define MAX 6001

const vector<int> coins = { 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };
const int vsize = coins.size();
vector<vector<long long>> memo(vsize, vector<long long>(MAX, -1));

long long numWays(int coinType, int valRem)
{
    if (valRem == 0)
    {
        return 1;
    }
    if (coinType == vsize || valRem < 0)
    {
        return 0;
    }
    if (memo[coinType][valRem] != -1)
    {
        return memo[coinType][valRem];
    }
    return memo[coinType][valRem] = numWays(coinType + 1, valRem) + numWays(coinType, valRem - coins[coinType]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double n;
    while (cin >> n, n != 0.0)
    {
        cout << right << setw(6) << fixed << setprecision(2) << n;

        int t = lround(n * 20.00);
        cout << right << setw(17) << numWays(0, t) << endl;
    }

    return 0;
}

