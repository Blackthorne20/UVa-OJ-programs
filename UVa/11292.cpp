/*
11292 - Dragon of Loowater

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=2267&mosmsg=Submission+received+with+ID+23428644
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m; // n = number of dragon heads, m = number of knights
    while (cin >> n >> m, n || m)
    {
        vector<int> dragonHeads(n), knights(m);
        for (int i = 0; i < n; i++)
        {
            cin >> dragonHeads[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> knights[i];
        }
        int gold = 0;
        sort(dragonHeads.begin(), dragonHeads.end());
        sort(knights.begin(), knights.end());
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (knights[j] >= dragonHeads[i]) // the knight has to be at least as big as the dragon head to chop it off
            {
                gold += knights[j]; // the size of the knight determines how much he gets paid
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        if (i == n) // all dragon heads chopped off
        {
            cout << gold << endl;
        }
        else if (j == m) // not enough knights, or knights not big enough to chop off the heads
        {
            cout << "Loowater is doomed!" << endl;
        }
    }

    return 0;
}

