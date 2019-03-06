// 624 - CD
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N)
    {
        int t;
        cin >> t;
        vector<int> tracks(t);
        for (int i = 0; i < t; ++i)
        {
            cin >> tracks[i];
        }

        int maxsum = INT_MIN, maxindex, g = pow(2, t);
        bitset<20> bs;
        for (int i = 0; i <= g; ++i)
        {
            bs = i;
            int sum = 0;
            for (int j = 0; j < t; ++j)
            {
                sum += tracks[j] * bs[j];
            }
            if (sum >= maxsum && sum <= N)
            {
                maxsum = sum;
                maxindex = bs.to_ulong();
            }
        }

        bs = maxindex;
        for (int i = 0; i < t; ++i)
        {
            if (bs[i])
            {
                cout << tracks[i] << " ";
            }
        }
        cout << "sum:" << maxsum << endl;
    }

    return 0;
}

