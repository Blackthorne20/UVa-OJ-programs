// OneLittleTwoLittleThreeLittleEndians.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <bitset>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    while (cin >> n)
    {
        bitset<32> numBig(n);
        bitset<32> numLittle;
        for (int i = 0; i < 8; i++)
        {
            numLittle[24 + i] = numBig[i];
            numLittle[16 + i] = numBig[i + 8];
            numLittle[8 + i] = numBig[i + 16];
            numLittle[i] = numBig[i + 24];
        }
        m = numLittle.to_ulong();
        cout << n << " converts to " << m << endl;
    }

    return 0;
}

