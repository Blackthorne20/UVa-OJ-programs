//Evan Wood : Vertex : 280 : Blackthorne20
//
//data structure required: adjacency list, queue, vector
//
//tricks of the trade: graph traversal

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; // n = number of vertices
    cin >> n;
    while (n != 0)
    {
        // fill the Adjacency List
        vector<vector<int>> AdjList(n + 1); // treat as one-based
        int vertex;
        cin >> vertex;
        while (vertex != 0)
        {
            int edge;
            cin >> edge;
            while (edge != 0)
            {
                AdjList[vertex].push_back(edge);
                cin >> edge;
            }
            cin >> vertex;
        }

        // get the list of starting vertices to inspect
        int numStartVertices;
        cin >> numStartVertices;
        vector<int> startVertex(numStartVertices);
        for (int i = 0; i < numStartVertices; i++)
        {
            cin >> startVertex[i];
        }

        // BFS traversal
        for (int i = 0; i < numStartVertices; i++)
        {
            // the starting vertex is not marked as visited
            vector<bool> d(n + 1, false);
            d[0] = true; // zero is not a vertex, so don't count it

            // push the starting vertex onto the queue
            queue<int> q;
            q.push(startVertex[i]);

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                // find adjacent vertices that are not already visited
                for (int j = 0; j < (int)AdjList[u].size(); j++)
                {
                    int v = AdjList[u][j];

                    // mark adjacent vertices as visited if they weren't
                    // already, then push them onto the queue
                    if (!d[v])
                    {
                        d[v] = true;
                        q.push(v);
                    }
                }
            }

            // print number of inaccesible vertices followed by the indices
            // of the inaccesible vertices
            cout << count(d.begin(), d.end(), false);
            for (int i = 1; i < d.size(); i++)
            {
                if (!d[i])
                {
                    cout << " " << i;
                }
            }
            cout << endl;
        }

        cin >> n;
    }

    return 0;
}

