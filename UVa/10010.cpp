/*
10010 - Where's Waldorf?

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=951
*/
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

#define endl '\n'

const vector<pair<int, int>> dir = { {1,0},{0,1},{1,1},{-1,-1},{-1,1},{1,-1},{-1,0},{0,-1} };

void findWord(const vector<string> &grid, const string &word, const int &m, const int &n)
{
    for (int r = 1; r <= m; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            if (tolower(word[0]) == tolower(grid[r][c]))
            {
                for (auto d : dir) // check each direction (must be a straight line)
                {
                    int i = 1, row = r + d.first, col = c + d.second;
                    while (tolower(word[i]) == tolower(grid[row][col]))
                    {
                        row += d.first;
                        col += d.second;
                        i++;
                    }
                    if (i == word.length())
                    {
                        cout << r << " " << c << endl; // print location of first matching character
                        return;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // no. of test cases
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // read input and initialize grid
        // ------------------------------
        int m, n; // grid size (m x n)
        cin >> m >> n;
        vector<string> grid(m + 2); // add boundary layer around grid
        for (int r = 0; r < m + 2; r++)
        {
            if (r == 0 || r == m + 1)
            {
                grid[r] = string(n + 2, '-');
            }
            else
            {
                cin >> grid[r];
                grid[r] = '-' + grid[r] + '-';
            }
        }

        // get words, find their locations in the grid
        // -------------------------------------------
        int k; // no. of words to find in grid
        cin >> k;
        string word;
        for (int j = 0; j < k; j++)
        {
            cin >> word;
            findWord(grid, word, m, n);
        }

        if (i < t - 1)
        {
            cout << endl;
        }
    }

    return 0;
}

