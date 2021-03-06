//Evan Wood : Robot Motion : 10986 : Blackthorne20
//
//data structure required: AdjList, priority queue
//
//tricks of the trade: implicit graph traversal

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define endl '\n'
#define INF 1000000000

typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef vector<int> vi;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        // filling the Adjacency List
        int n, m, S, T;
        cin >> n >> m >> S >> T;

        vector<vii> AdjList(n); // weighted list

        for (int j = 0; j < m; j++)
        {
            // get edge a->b with latency w
            int a, b, w;
            cin >> a >> b >> w;

            AdjList[a].push_back({ b, w });
            AdjList[b].push_back({ a, w });
        }

        // finding the SSSP using Dijkstra's algorithm
        vi dist(n, INF); // track shortest distance to vertex
        dist[S] = 0;
        priority_queue<ii, vector<ii>, greater<ii>> pq; // sort by increasing distance
        pq.push({ 0, S });
        while (!pq.empty())
        {
            ii front = pq.top(); // get shortest unvisited vertex
            pq.pop();
            int d = front.first, u = front.second;
            if (d > dist[u])
            {
                continue;
            }
            for (int j = 0; j < (int)AdjList[u].size(); j++)
            {
                ii v = AdjList[u][j];
                if (dist[u] + v.second < dist[v.first])
                {
                    dist[v.first] = dist[u] + v.second; // relax operation
                    pq.push({ dist[v.first], v.first });
                }
            }
        }

        // print output
        cout << "Case #" << i + 1 << ": ";
        int t = dist[T];
        if (t == INF)
        {
            cout << "unreachable" << endl;
        }
        else
        {
            cout << t << endl;
        }
    }


    return 0;
}

