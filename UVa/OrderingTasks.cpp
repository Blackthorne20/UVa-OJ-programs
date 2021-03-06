//Evan Wood : Ordering Tasks : 10305 : Blackthorne20
//
//data structure required: Adjacency List (unweighted)
//
//tricks of the trade: Topological Sort (Directed Acyclic Graph)

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define VISITED 1
#define UNVISITED -1

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

vi ts; // global vector to store the toposort in reverse order
vector<vi> AdjList;
vi dfs_num; // keep track of visited/unvisited vertices

void dfs2(int u)
{
    dfs_num[u] = VISITED; // mark vertex as visited
    for (int j = 0; j < (int)AdjList[u].size(); j++)
    {
        int v = AdjList[u][j];

        // recursively visit all unvisited neighbors of vertex u
        if (dfs_num[v] == UNVISITED)
        {
            dfs2(v);
        }
    }
    ts.push_back(u); // only difference from normal DFS
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    while (!(n == 0 && m == 0))
    {
        AdjList = vector<vi>(n + 1);
        dfs_num = vi(n + 1, UNVISITED); // set all vertices to UNVISITED
        dfs_num[0] = VISITED;
        int i, j;

        // fill the Adjacency list
        for (int k = 0; k < m; k++)
        {
            cin >> i >> j;
            AdjList[i].push_back(j);
        }

        ts.clear();
        for (int k = 1; k <= n; k++)
        {
            if (dfs_num[k] == UNVISITED)
            {
                dfs2(k);
            }
        }

        // print ts in reverse
        for (int k = (int)ts.size() - 1; k >= 0; k--)
        {
            cout << ts[k];
            k > 0 ? cout << " " : cout << "";
        }
        cout << endl;
        cin >> n >> m;
    }

    return 0;
}

