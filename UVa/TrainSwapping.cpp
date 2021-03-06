// TrainSwapping.cpp : Defines the entry point for the console application.
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

    unsigned short N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        unsigned short L, numSwaps = 0;
        cin >> L;

        vector<unsigned short> carriage(L);
        for (int j = 0; j < L; j++)
        {
            cin >> carriage[j];
        }

        do
        {
            unsigned short newn = 0;
            for (int l = 0; l < L - 1; l++)
            {
                unsigned short r = l + 1;
                if (carriage[l] > carriage[r])
                {
                    swap(carriage[l], carriage[r]);
                    newn = r;
                    numSwaps++;
                }
            }
            L = newn;
        } while (L != 0);

        cout << "Optimal train swapping takes " << numSwaps << " swaps." << endl;
    }
    return 0;
}

