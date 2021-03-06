// Continents_11094.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int dr[] = { 1,-1,0,0 };
int dc[] = { 0,0,1,-1 };

int floodfill(int r, int c, char c1, char c2, vector<vector<char>> &grid, int &R, int &C)
{
    r = (r + R) % R;
    if (r < 0 || r >= R || c < 0 || c >= C)
    {
        return 0;
    }
    if (grid[r][c] != c1)
    {
        return 0;
    }
    int ans = 1;
    grid[r][c] = c2;
    for (int d = 0; d < 4; d++)
    {
        ans += floodfill(r + dr[d], c + dc[d], c1, c2, grid, R, C);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<pair<int, int>> adjList;
    int M, N;
    while (cin >> M >> N)
    {
        vector<vector<char>> grid(M, vector<char>(N));
        for (int r = 0; r < M; r++)
        {
            for (int c = 0; c < N; c++)
            {
                cin >> grid[r][c];
            }
        }

        pair<int, int> loc;
        cin >> loc.first >> loc.second;

        char f = grid[loc.first][loc.second];

        int max = 0;
        floodfill(loc.first, loc.second, f, '.', grid, M, N);

        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                int e = floodfill(r, c, f, '.', grid, M, N);
                if (e > max)
                {
                    max = e;
                }
            }
        }

        cout << max << endl;
    }

    return 0;
}

