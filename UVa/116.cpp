/*
116 - Unidirectional TSP

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=52
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define endl '\n'

bool sorter(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) // the minCost from both paths are the same
    {
        return a.first < b.first;
    }
    else
    {
        return a.second < b.second;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n; // dimensions of the matrix (m x n)
    while (cin >> m >> n)
    {
        // initialize the matrix
        // ---------------------
        vector<vector<int>> mat(m, vector<int>(n)), dp(m, vector<int>(n));
        for (int r = 0; r < m; r++)
        {
            for (int c = 0; c < n; c++)
            {
                cin >> mat[r][c];
            }
        }

        // bottom-up DP (O(n^2))
        // ---------------------
        int minCost = INT_MAX;
        for (int col = n - 1; col >= 0; col--)
        {
            for (int row = 0; row < m; row++)
            {
                if (col == n - 1)
                {
                    dp[row][col] = mat[row][col]; // base case
                }
                else
                {
                    // wrap-around moves are valid
                    dp[row][col] = mat[row][col] + min(dp[((row - 1) % m + m) % m][col + 1], min(dp[row][col + 1], dp[((row + 1) % m + m) % m][col + 1]));
                }
                if (col == 0 && dp[row][col] < minCost)
                {
                    minCost = dp[row][col];
                }
            }
        }

        // find the first row that has a minimum cost path
        // -----------------------------------------------
        int startingRow;
        for (int row = 0; row < m; row++)
        {
            if (dp[row][0] == minCost)
            {
                startingRow = row;
                cout << row + 1;
                break;
            }
        }

        // trace the minimum cost path, print output
        // -----------------------------------------
        int row = startingRow;
        for (int i = 1; i < n; i++)
        {
            int up = ((row - 1) % m + m) % m, down = ((row + 1) % m + m) % m;
            vector <pair<int, int>> dir = { {up, dp[up][i]},{row,dp[row][i]},{down,dp[down][i]} };
            sort(dir.begin(), dir.end(), sorter);
            cout << " " << dir[0].first + 1; // print the row of the element
            row = dir[0].first;
        }

        cout << endl << minCost << endl;
    }

    return 0;
}

