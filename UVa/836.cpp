//Evan Wood : Largest Submatrix : 836 : Blackthorne20
//
//data structure required: vector
//
//tricks of the trade: Dynamic programming (max 2D range sum)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        string line;
        getline(cin, line);
        while (line.empty())
        {
            getline(cin, line);
        }
        int N = line.size();
        vector<vector<int>> A(N, vector<int>(N));

        // build sum matrix as we're reading in data
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                // convert zeros to -50 so only the ones are counted
                A[r][c] = (line[c] - 48) ? 1 : -50;

                // add previous element in row
                if (c > 0)
                {
                    A[r][c] += A[r][c - 1];
                }
            }
            getline(cin, line);
        }

        int maxSubRect = 0, subRect; // the lowest possible value for this problem

        // taken from page 105, ch3_05_UVa108.cpp
        // this is a fast, O(n^3) algorithm that uses Kandane's solution
        for (int l = 0; l < N; l++)
        {
            for (int r = l; r < N; r++)
            {
                subRect = 0;
                for (int row = 0; row < N; row++)
                {
                    // Max 1D Range Sum on columns of this row i
                    if (l > 0)
                    {
                        subRect += A[row][r] - A[row][l - 1];
                    }
                    else
                    {
                        subRect += A[row][r];
                    }

                    // Kadane's algorithm on rows
                    if (subRect < 0)
                    {
                        subRect = 0;     // greedy, restart if running sum < 0
                    }
                    maxSubRect = max(maxSubRect, subRect);
                }
            }
        }
        cout << maxSubRect << endl;
        if (i < t - 1)
        {
            cout << endl;
        }
    }

    return 0;
}

