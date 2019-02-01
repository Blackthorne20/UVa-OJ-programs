// 624 - CD
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cmath>
using namespace std;

#define endl '\n'

vector<int> tracks;
int t;

//int dps(int remTime, int i)
//{
//    if (i == t || remTime == 0)
//    {
//        return 0;
//    }
//    int s = tracks[i];
//    if (s > remTime)
//    {
//        return dps(remTime, i + 1);
//    }
//    return max(dps(remTime, i + 1), s + dps(remTime - s, i + 1));
//}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N)
    {
        cin >> t;
        bitset<10000> bs(1);
        tracks = vector<int>(t);
        for (int i = 0; i < t; ++i)
        {
            cin >> tracks[i];
        }

        int lim = (int)pow(2, t);
        int maxsum = 0, maxindex = 0;
        for (int i = 1; i <= lim; ++i)
        {
            int sum = 0;
            for (int j = 0; j < t; ++j)
            {
                sum += (int)bs[j] * tracks[j];
            }
            if (sum > maxsum && sum <= N)
            {
                maxsum = sum;
                maxindex = bs.to_ulong();
                if (sum == N)
                {
                    break;
                }
            }
            bs = i + 1;
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

