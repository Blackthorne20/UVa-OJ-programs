// OilDeposits.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<char> vc;

vector<vc> grid;
const vector<ii> dir = { {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1} };

int floodfill(int r, int c, char c1, char c2)
{
    if (grid[r][c] != c1)
    {
        return 0;
    }
    int ans = 1;
    grid[r][c] = c2;
    for (int d = 0; d < (int)dir.size(); d++)
    {
        ans += floodfill(r + dir[d].first, c + dir[d].second, c1, c2);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;
    while (m != 0)
    {
        grid = vector<vc>(m + 2, vc(n + 2, '*'));
        for (int r = 1; r <= m; r++)
        {
            for (int c = 1; c <= n; c++)
            {
                cin >> grid[r][c];
            }
        }

        int numDeposits = 0;
        for (int r = 1; r <= m; r++)
        {
            for (int c = 1; c <= n; c++)
            {
                if (grid[r][c] == '@')
                {
                    numDeposits++;
                    floodfill(r, c, '@', '*');
                }
            }
        }

        cout << numDeposits << endl;

        grid.clear();
        cin >> m >> n;
    }

    return 0;
}

