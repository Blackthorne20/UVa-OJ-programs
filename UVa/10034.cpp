/*
10034 - Freckles

This program calculates the minimum length of ink lines needed to connect
a given set of freckles with their coordinates.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;

#define endl '\n'

class UnionFind
{
private:
    vector<int> p;
    vector<int> rank;
public:
    UnionFind(int N)
    {
        rank.assign(N, 0);
        p.assign(N, 0);
        for (int i = 0; i < N; i++)
        {
            p[i] = i;
        }
    }
    int findSet(int i)
    {
        return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }
    bool isSameSet(int i, int j)
    {
        return findSet(i) == findSet(j);
    }
    void unionSet(int i, int j)
    {
        if (!isSameSet(i, j))
        {
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y])
            {
                p[y] = x;
            }
            else
            {
                p[x] = y;
                if (rank[x] == rank[y])
                {
                    rank[y]++;
                }
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; // number of test cases
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        // get positions of freckles
        int n; // number of freckles
        cin >> n;
        vector<pair<double, double> > freckles(n); // (x, y) coordinates of freckles
        for (int j = 0; j < n; ++j)
        {
            cin >> freckles[j].first >> freckles[j].second;
        }

        // calculate distances between freckles, store in edge list as weights
        vector < pair<double, pair<int, int>>> EdgeList; // weigtht, vertices
        EdgeList.reserve(n * (n - 1) / 2);
        for (int j = 0; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                EdgeList.push_back({ sqrt(pow(freckles[j].first - freckles[k].first, 2) + pow(freckles[j].second - freckles[k].second, 2)), {j, k} });
            }
        }
        sort(EdgeList.begin(), EdgeList.end());


        // Kruskal's algorithm (Minimum Spanning Tree)
        double mst_cost = 0;
        UnionFind UF(n);
        for (int j = 0; j < EdgeList.size(); j++)
        {
            pair<double, pair<int, int>> front = EdgeList[j];
            if (!UF.isSameSet(front.second.first, front.second.second))
            {
                mst_cost += front.first;
                UF.unionSet(front.second.first, front.second.second);
            }
        }

        // print output
        cout << fixed << setprecision(2) << mst_cost << endl;
        if (i != t - 1)
        {
            cout << endl;
        }
    }

    return 0;
}

