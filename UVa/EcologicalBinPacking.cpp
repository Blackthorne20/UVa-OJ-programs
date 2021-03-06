// EcologicalBinPacking.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <climits>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    while (getline(cin, line))
    {
        int minMovements = INT_MAX, index;
        vector<int> bottles(9);
        vector<int> numMoves(6);
        stringstream ss(line);

        for (int i = 0; i < 9; i++)
        {
            ss >> bottles[i];
        }

        //    BCG
        numMoves[0] = bottles[3] + bottles[6] + bottles[2] + bottles[8] + bottles[1] + bottles[4];
        //    BGC
        numMoves[1] = bottles[3] + bottles[6] + bottles[1] + bottles[7] + bottles[2] + bottles[5];
        //    CBG
        numMoves[2] = bottles[5] + bottles[8] + bottles[0] + bottles[6] + bottles[1] + bottles[4];
        //    CGB
        numMoves[3] = bottles[5] + bottles[8] + bottles[1] + bottles[7] + bottles[0] + bottles[3];
        //    GBC
        numMoves[4] = bottles[4] + bottles[7] + bottles[0] + bottles[6] + bottles[2] + bottles[5];
        //    GCB
        numMoves[5] = bottles[4] + bottles[7] + bottles[2] + bottles[8] + bottles[0] + bottles[3];

        for (int i = 0; i < 6; i++)
        {
            if (numMoves[i] < minMovements)
            {
                minMovements = numMoves[i];
                index = i;
            }
        }

        switch (index)
        {
        case 0:
            cout << "BCG ";
            break;
        case 1:
            cout << "BGC ";
            break;
        case 2:
            cout << "CBG ";
            break;
        case 3:
            cout << "CGB ";
            break;
        case 4:
            cout << "GBC ";
            break;
        case 5:
            cout << "GCB ";
            break;
        }

        cout << minMovements << endl;
    }

    return 0;
}

