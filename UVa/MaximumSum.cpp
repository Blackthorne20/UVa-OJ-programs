// MaximumSum.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned short N;
    while (cin >> N)
    {
        vector<vector<int>> A(N, vector<int>(N));

        //create sum matrix as we're reading input
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                cin >> A[r][c];
                if (r > 0)
                {
                    A[r][c] += A[r - 1][c];
                }
                if (c > 0)
                {
                    A[r][c] += A[r][c - 1];
                }
                if (r > 0 && c > 0)
                {
                    A[r][c] -= A[r - 1][c - 1];
                }
            }
        }

        //find subrectangle with largest sum
        int maxSubRect = -127 * 100 * 100;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = i; k < N; k++)
                {
                    for (int l = j; l < N; l++)
                    {
                        int subRect = A[k][l];
                        if (i > 0)
                        {
                            subRect -= A[i - 1][l];
                        }
                        if (j > 0)
                        {
                            subRect -= A[k][j - 1];
                        }
                        if (i > 0 && j > 0)
                        {
                            subRect += A[i - 1][j - 1];
                        }
                        maxSubRect = max(maxSubRect, subRect);
                    }
                }
            }
        }
        cout << maxSubRect << endl;
    }

    return 0;
}

