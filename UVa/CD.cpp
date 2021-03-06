// CD.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <unordered_set>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numJacksCDs, numJillCDs;
    cin >> numJacksCDs >> numJillCDs;
    while (!(numJacksCDs == 0 && numJillCDs == 0))
    {
        unordered_set<int> JackCDs;
        int CD, numDuplicates = 0;
        for (int i = 0; i < numJacksCDs; i++)
        {
            cin >> CD;
            JackCDs.insert(CD);
        }
        for (int i = 0; i < numJillCDs; i++)
        {
            cin >> CD;
            unordered_set<int>::iterator it;
            it = JackCDs.find(CD);
            if (it != JackCDs.end())
            {
                numDuplicates++;
            }
        }
        cout << numDuplicates << endl;
        cin >> numJacksCDs >> numJillCDs;
    }

    return 0;
}

// |A U B| = |A| + |B| - |A ^ B|
