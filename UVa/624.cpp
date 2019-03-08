// 624 - CD
//
// Given a tape with capacity N minutes, find the set of CD tracks that will maximize
// the amount of tape space used.

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
using namespace std;

#define endl '\n'

//TODO: figure out how to backtrack
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

        int sum = val(tracks, memo, 0, N);

        cout << "sum:" << sum << endl;
    }

    return 0;
}

