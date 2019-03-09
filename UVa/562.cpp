// Dividing Coins
//
// This program calculates the most fair division of coins between two people.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'

// 0-1 Knapsack
int val(vector<int> &coins, vector<vector<int>> &memo, int id, int remAmt)
{
    // no more coins to check or maximum value found
    if (id == coins.size() || remAmt == 0)
    {
        return 0;
    }

    // use pre-calculated value if available
    if (memo[id][remAmt] != -1)
    {
        return memo[id][remAmt];
    }

    // if the coin is too big, skip to the next coin
    if (coins[id] > remAmt)
    {
        return memo[id][remAmt] = val(coins, memo, id + 1, remAmt);
    }

    // either pick this coin and subtract it from the remaining amount, or go to the next one
    return memo[id][remAmt] = max(val(coins, memo, id + 1, remAmt), coins[id] + val(coins, memo, id + 1, remAmt - coins[id]));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // number of test cases
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, sum = 0; // m = number of coins in the bag
        cin >> m;
        vector<int> coins(m);
        for (int j = 0; j < m; j++)
        {
            cin >> coins[j];
            sum += coins[j];
        }

        vector<vector<int>> memo(m, vector<int>(sum + 1, -1));
        int half = val(coins, memo, 0, (sum + 1) / 2);

        // output the difference between the two halves
        cout << abs(sum - 2 * half) << endl;
    }

    return 0;
}

