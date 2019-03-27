/*
10006 - Carmichael Numbers

This program reads in an integer and decides if the number is
a Carmichael number or not.
*/

#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

#define endl '\n'
#define SIZE 65000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // hard code all Carmichael numbers less than 65000
    const vector<int> CarmichaelNums = { 561, 1105, 1729, 2465, 2821, 6601, 8911, 10585, 15841, 29341, 41041, 46657, 52633, 62745, 63973 };
    bitset<SIZE> bs;
    for (auto i : CarmichaelNums)
    {
        bs.set(i);
    }

    int n;
    while (cin >> n, n != 0)
    {
        if (bs[n])
        {
            cout << "The number " << n << " is a Carmichael number." << endl;
        }
        else
        {
            cout << n << " is normal." << endl;
        }
    }


    return 0;
}

