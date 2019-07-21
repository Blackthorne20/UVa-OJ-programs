// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define SIZE 3

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int B, N;
    while (cin >> B >> N, !(B == 0 && N == 0))
    {
        vector<int> banks(B);
        vector<vector<int>> debentures(N, vector<int>(SIZE));
        for (int i = 0; i < B; i++)
        {
            cin >> banks[i];
        }
        bool canLiquidate = true;
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < SIZE; c++)
            {
                cin >> debentures[r][c];
            }
            canLiquidate = canLiquidate && debentures[r][0] + debentures[r][1] > debentures[r][2];
        }
        if (canLiquidate)
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }

    return 0;
}

