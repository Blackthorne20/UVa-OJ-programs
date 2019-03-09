// 624 - CD
//
// Given a tape with capacity N minutes, find the set of CD tracks that will maximize
// the amount of tape space used.

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <string>
#include <cmath>
using namespace std;

#define endl '\n'


// subset sum
int val(vector<int> &tracks, vector<vector<int>> &memo, int id, int remT)
{
    // out of tape space, or no more tracks to check
    if (remT == 0 || id == tracks.size())
    {
        return 0;
    }

    // use precalculated value if available
    if (memo[id][remT] != -1)
    {
        return memo[id][remT];
    }

    // track too big, skip to next one
    if (tracks[id] > remT)
    {
        return memo[id][remT] = val(tracks, memo, id + 1, remT);
    }

    // either choose this track or move to the next one
    return memo[id][remT] = max(val(tracks, memo, id + 1, remT), tracks[id] + val(tracks, memo, id + 1, remT - tracks[id]));
}

bool backtrack(vector<int> &tracks, string &a, int sum, int max, int i)
{
    if (sum == max)
    {
        return true;
    }
    if (i == tracks.size())
    {
        return false;
    }

    // if this track was added, append to output string
    if (backtrack(tracks, a, sum + tracks[i], max, i + 1))
    {
        a = to_string(tracks[i]) + " " + a;
        return true;
    }
    if (backtrack(tracks, a, sum, max, i + 1))
    {
        return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // tape capacity (in minutes)
    while (cin >> N)
    {
        int t; // number of tracks
        cin >> t;
        vector<int> tracks(t);
        vector<vector<int>> memo(t, vector<int>(N + 1, -1));
        for (int i = 0; i < t; ++i)
        {
            cin >> tracks[i]; // get track length (in minutes)
        }

        int sum = val(tracks, memo, 0, N); // get maximum tape length
        string nums = "";
        backtrack(tracks, nums, 0, sum, 0); // find set of numbers equal to maximum value

        cout << nums << "sum:" << sum << endl;
    }

    return 0; // run time: 0.040
}

