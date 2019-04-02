/*
10161 - Ant on a Chessboard

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1102
*/
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // number of seconds elapsed
    while (cin >> N, N != 0)
    {
        double a = sqrt(N);
        int b = lround(ceil(a));
        int c = b * b;
        int d = 2 * b - 1;
        int e = b * b - N;
        pair<int, int> ans;
        if (b % 2 == 0)
        {
            ans = { b, 1 };
            if (e * 2 > d)
            {
                swap(ans.first, ans.second);
                ans.first += d - e - 1;
            }
            else
            {
                ans.second += e;
            }
        }
        else
        {
            ans = { 1, b };
            if (e * 2 > d)
            {
                swap(ans.first, ans.second);
                ans.second += d - e - 1;
            }
            else
            {
                ans.first += e;
            }
        }

        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}

