// WhereIsTheMarble_10474.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int caseNo = 1;

    int N, Q;
    cin >> N >> Q;
    while (!(N == 0 && Q == 0))
    {
        cout << "CASE# " << caseNo << ":" << endl;

        vector<int> marbles(N);
        for (int i = 0; i < N; i++)
        {
            cin >> marbles[i];
        }

        auto itb = marbles.begin(), ite = marbles.end();
        sort(itb, ite);

        for (int i = 0; i < Q; i++)
        {
            int S;
            cin >> S;
            auto it = lower_bound(itb, ite, S);
            if (it != ite && *it == S)
            {
                cout << S << " found at " << it - itb + 1 << endl;
            }
            else
            {
                cout << S << " not found" << endl;
            }
        }
        cin >> N >> Q;
        caseNo++;
    }

    return 0;
}

