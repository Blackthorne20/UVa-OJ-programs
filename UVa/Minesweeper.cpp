// Minesweeper.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define endl '\n'

typedef unsigned short us;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    us n, m, fieldNo = 1;
    cin >> n >> m;
    while (!(n == 0 && m == 0))
    {
        vector<vector<char>> minefield(n + 2, vector<char>(m + 2, '-'));
        for (int r = 1; r < n + 1; r++)
        {
            for (int c = 1; c < m + 1; c++)
            {
                cin >> minefield[r][c];
            }
        }

        for (int r = 1; r < n + 1; r++)
        {
            for (int c = 1; c < m + 1; c++)
            {
                us adjMines = 0;
                if (minefield[r][c] == '.')
                {
                    if (minefield[r - 1][c - 1] == '*')
                    {
                        adjMines++;
                    }
                    if (minefield[r - 1][c] == '*')
                    {
                        adjMines++;
                    }
                    if (minefield[r - 1][c + 1] == '*')
                    {
                        adjMines++;
                    }
                    if (minefield[r][c - 1] == '*')
                    {
                        adjMines++;
                    }
                    if (minefield[r][c + 1] == '*')
                    {
                        adjMines++;
                    }
                    if (minefield[r + 1][c - 1] == '*')
                    {
                        adjMines++;
                    }
                    if (minefield[r + 1][c] == '*')
                    {
                        adjMines++;
                    }
                    if (minefield[r + 1][c + 1] == '*')
                    {
                        adjMines++;
                    }
                    minefield[r][c] = (char)adjMines + 48;
                }
            }
        }

        cout << "Field #" << fieldNo++ << ":" << endl;
        for (int r = 1; r < n + 1; r++)
        {
            for (int c = 1; c < m + 1; c++)
            {
                cout << minefield[r][c];
            }
            cout << endl;
        }
        cin >> n >> m;
        if (!(n == 0 && m == 0))
        {
            cout << endl;
        }
    }

    return 0;
}

