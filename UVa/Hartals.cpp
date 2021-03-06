// Hartals.cpp : Defines the entry point for the console application.
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

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N, P;
        cin >> N >> P;

        vector<bool> days(N, 0);
        int hartalParam;
        for (int j = 0; j < P; j++)
        {
            cin >> hartalParam;
            for (int k = hartalParam - 1; k < N; k += hartalParam)
            {
                //don't count Fridays or Saturdays
                if (k % 7 != 5 && k % 7 != 6)
                {
                    days[k] = 1;
                }
            }
        }
        cout << count(days.begin(), days.end(), 1) << endl;
    }

    return 0;
}

