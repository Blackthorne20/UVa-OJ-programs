// Pseudo-Random Numbers
//
// This program finds the cycle length of a given pseudo-random
// number algorithm.

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // L = last number
    // Z, I, M = constants
    // t = case number
    int Z, I, M, L, t = 1;
    while (cin >> Z >> I >> M >> L, Z || I || M || L)
    {
        cout << "Case " << t << ": ";
        int cycleLength = 0, Li = L = (Z * L + I) % M; // Li = L initial (the seed value)
        do
        {
            L = (Z * L + I) % M; // generate random numbers repeatedly until a full cycle is made
            ++cycleLength;
        } while (L != Li);
        cout << cycleLength << endl;
        ++t;
    }

    return 0;
}

