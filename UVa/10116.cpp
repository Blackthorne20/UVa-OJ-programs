//Evan Wood : Robot Motion : 10116 : Blackthorne20
//
//data structure required: map, implicit graph (2D vector)
//
//tricks of the trade: implicit graph traversal

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // map each cardinal direction to associated vector
    unordered_map<char, pair<int, int>> dir =
    { {'N',{-1,0}}, {'E',{0,1}}, {'S',{1,0}}, {'W',{0,-1}} };

    int numRows, numColumns, entry;
    cin >> numRows >> numColumns >> entry;
    while (!(numRows == 0 && numColumns == 0 && entry == 0))
    {
        // fill the implicit graph
        vector<vector<char>> grid(numRows, vector<char>(numColumns));
        for (int r = 0; r < numRows; r++)
        {
            for (int c = 0; c < numColumns; c++)
            {
                cin >> grid[r][c];
            }
        }

        // stepGraph tracks the number of steps taken to get to location
        // (i, j) so we can calculate the length of a loop
        vector<vector<int>> stepGraph(numRows, vector<int>(numColumns, 0));
        int i = 0, j = entry - 1, steps = 0;
        bool outOfBounds = false, loopHit = false;
        while (!(outOfBounds || loopHit))
        {
            // out of bounds
            if (!(i >= 0 && i < numRows && j >= 0 && j < numColumns))
            {
                outOfBounds = true;
                cout << steps << " step(s) to exit" << endl;
            }

            // loop entered
            else if (grid[i][j] == '.')
            {
                loopHit = true;
                cout << stepGraph[i][j] << " step(s) before a loop of "
                    << steps - stepGraph[i][j] << " step(s)" << endl;
            }

            // move to new location
            else
            {
                // get move direction
                pair<int, int> v = dir[grid[i][j]];

                // spot marked with '.' to indicate it has been passed
                grid[i][j] = '.';
                stepGraph[i][j] = steps;

                // update location
                i += v.first;
                j += v.second;

                steps++;
            }
        }

        cin >> numRows >> numColumns >> entry;
    }

    return 0;
}

