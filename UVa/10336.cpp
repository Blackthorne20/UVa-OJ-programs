//Evan Wood : Rank the Languages : 10336 : Blackthorne20
//
//data structure required: implicit graph (vector), ASCII table (vector)
//
//tricks of the trade: flood fill (counting and ranking connected components

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

vector<string> grid;
vector<pair<int, int>> dir = { {-1,0},{0,1},{1,0},{0,-1} }; // N, E, S, W;

// comparator function
bool sortBySec(pair<char, int> a, pair<char, int> b)
{
    // sort alphabetically if same value
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    // else sort in decreasing order
    else
    {
        return a.second > b.second;
    }
}

// returns the number of connected components in
// graph (diagonals not counted)
int floodfill(int r, int c, char c1, char c2)
{
    // return 0 if the character doesn't match
    if (grid[r][c] != c1)
    {
        return 0;
    }
    int ans = 1;
    grid[r][c] = c2; // replace char with a dot to avoid cycling
    for (int d = 0; d < dir.size(); d++)
    {
        // find matching neighbors recursively
        ans += floodfill(r + dir[d].first, c + dir[d].second, c1, c2);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        // read input, fill the grid
        int H, W;
        cin >> H >> W;
        grid = vector<string>(H + 2); // put boundary layers on grid
        for (int r = 0; r < H + 2; r++)
        {
            string line(W + 2, '.');
            if (r == 0 || r == H + 1)
            {
                grid[r] = line;
            }
            else
            {
                cin >> line;
                grid[r] = "." + line + ".";
            }
        }

        // pair contains a language (char) and the number of regions
        // where the language is spoken (int)
        vector<pair<char, int>> ascii(128, {'.', 0});

        // traverse the grid
        for (int r = 1; r < H + 1; r++)
        {
            for (int c = 1; c < W + 1; c++)
            {
                // find a char not equal to '.'
                char ch = grid[r][c];
                if (ch != '.')
                {
                    // insert the pair into the ascii table
                    ascii[(int)ch].first = ch;
                    ascii[(int)ch].second++;

                    // find all neighbors containing same char
                    // and replace with '.' so the region is
                    // counted only once
                    floodfill(r, c, ch, '.');
                }
            }
        }

        // sort in descending order of regions where language is spoken
        sort(ascii.begin(), ascii.end(), sortBySec);

        // print the sorted table (only languages with one or more regions)
        cout << "World #" << i + 1 << endl;
        int j = 0;
        pair<char, int> v = ascii[j];
        while (v.second > 0)
        {
            cout << v.first << ": " << v.second << endl;
            j++;
            v = ascii[j];
        }

        grid.clear();
    }

    return 0;
}

