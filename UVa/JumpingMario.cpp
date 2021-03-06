// JumpingMario.cpp : Defines the entry point for the console application.
//

#include <iostream>
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
        int N, numLowJumps = 0, numHighJumps = 0, prevHeight;
        cin >> N;

        for (int j = 0; j < N; j++)
        {
            int height;
            cin >> height;

            if (j > 0)
            {
                if (height > prevHeight)
                {
                    numHighJumps++;
                }
                else if (height < prevHeight)
                {
                    numLowJumps++;
                }
            }
            prevHeight = height;
        }

        cout << "Case " << i + 1 << ": " << numHighJumps << " " << numLowJumps << endl;
    }


    return 0;
}

