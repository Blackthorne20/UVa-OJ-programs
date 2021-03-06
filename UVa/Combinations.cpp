// Combinations.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    while (N != 0 && M != 0)
    {
        int d = N - M;
        double C = 1;

        if (d >= M)
        {
            for (int i = 0; i < M; i++)
            {
                C *= ((double)N - i) / (i + 1);
            }
        }
        else
        {
            for (int i = 0; i < d; i++)
            {
                C *= ((double)N - i) / (i + 1);
            }
        }

        cout << N << " things taken " << M << " at a time is " << lround(C) << " exactly." << endl;
        cin >> N >> M;
    }

    return 0;
}

