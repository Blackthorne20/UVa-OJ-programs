// BeatTheSpread!.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        unsigned int s, d, score1, score2;
        cin >> s >> d;

        //s and d must both be even or odd
        if (d <= s && !(s % 2 == 1 != d % 2 == 1))
        {
            score1 = s / 2 + d / 2 + s % 2;
            score2 = s / 2 - d / 2;
            cout << score1 << " " << score2 << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
    }

    return 0;
}

