#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define endl '\n'
#define INF 1000000000

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string A, B;
    while (getline(cin, A), getline(cin, B))
    {
        int n = A.size(), m = B.size();
        int i, j; // Needleman Wunsnch's algorithm
        vector<vector<int>> table(n + 1, vector<int>(m + 1, 0));

        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++) {
                // match = 1 point, mismatch = -INF points
                table[i][j] = table[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 1 : -INF); // cost for match or mismatches
                                                                                     // insert/delete = 0 points
                table[i][j] = max(table[i][j], table[i - 1][j] - 0); // delete
                table[i][j] = max(table[i][j], table[i][j - 1] - 0); // insert
            }

        cout << table[n][m] << endl;
    }

    return 0;
}