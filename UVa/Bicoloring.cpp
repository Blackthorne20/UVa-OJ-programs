// Bicoloring.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n, n != 0)
    {
        int l;
        cin >> l;

        vector<vii> AdjList;
        AdjList.assign(n, vii());
        for (int j = 0; j < l; j++)
        {
            int first, second;
            cin >> first >> second;

            AdjList[first].push_back(make_pair(second, 0));
            AdjList[second].push_back(make_pair(first, 0));
        }

        queue<int> q;
        q.push(0);
        vi color(n, INF);
        color[0] = 0;
        bool isBipartite = true;
        while (!q.empty() & isBipartite)
        {
            int u = q.front();
            q.pop();
            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                ii v = AdjList[u][j];
                if (color[v.first] == INF)
                {
                    color[v.first] = 1 - color[u];
                    q.push(v.first);
                }
                else if (color[v.first] == color[u])
                {
                    isBipartite = false;
                    break;
                }
            }
        }

        if (isBipartite)
        {
            cout << "BICOLORABLE." << endl;
        }
        else
        {
            cout << "NOT BICOLORABLE." << endl;
        }

    }

    return 0;
}

