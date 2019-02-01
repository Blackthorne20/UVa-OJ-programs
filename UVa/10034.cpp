// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef pair<int, int> ii

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        vector<pair<int, ii> > EdgeList(n);
        for (int j = 0; j < n; ++j)
        {
            int u, v, w;
            cin >> u >> v >> w;
            EdgeList[j] = { u, {v, w} };
        }
        sort(EdgeList.begin(), EdgeList.end());
    }

    return 0;
}

