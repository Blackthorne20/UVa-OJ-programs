/*
10066 - The Twin Towers

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=1007&mosmsg=Submission+received+with+ID+23130978
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 1000000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N1, N2, t = 1;
    while (cin >> N1 >> N2, N1 || N2)
    {
        cout << "Twin Towers #" << t << endl;

        // first tower
        vector<int> A(N1);
        for (int i = 0; i < N1; i++)
        {
            cin >> A[i];
        }

        // second tower
        vector<int> B(N2);
        for (int i = 0; i < N2; i++)
        {
            cin >> B[i];
        }

        // longest common subsequence DP algorithm
        vector<vector<int>> table(N1 + 1, vector<int>(N2 + 1, 0));
        for (int r = 1; r < N1 + 1; r++)
        {
            for (int c = 1; c < N2 + 1; c++)
            {
                table[r][c] = table[r - 1][c - 1] + (A[r - 1] == B[c - 1] ? 1 : -INF);
                table[r][c] = max(table[r][c], table[r - 1][c]);
                table[r][c] = max(table[r][c], table[r][c - 1]);
            }
        }

        cout << "Number of Tiles : " << table[N1][N2] << endl << endl;

        t++;
    }

    return 0;
}

