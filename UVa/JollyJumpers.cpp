// JollyJumpers.cpp : Defines the entry point for the console application.
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

    int n_numInts;
    while (cin >> n_numInts)
    {
        vector<int> n_list(n_numInts);
        vector<bool> b_numsFound(n_numInts, false);
        for (int i = 0; i < n_numInts; i++)
        {
            cin >> n_list[i];

            if (i > 0)
            {
                int n_absDif = abs(n_list[i] - n_list[i - 1]);
                if (n_absDif > -1 && n_absDif < n_numInts)
                {
                    b_numsFound[n_absDif] = true;
                }
            }
        }
        if (all_of(b_numsFound.begin()+1, b_numsFound.end(), [](bool i) {return i == true; }))
        {
            cout << "Jolly" << endl;
        }
        else
        {
            cout << "Not jolly" << endl;
        }
    }
    return 0;
}

