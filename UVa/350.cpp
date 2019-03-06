// Pseudo-Random Numbers
//
#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Z, I, M, L, t = 1;
    while (cin >> Z >> I >> M >> L, Z || I || M || L)
    {
        cout << "Case " << t << ": ";
        int cycleLength = 0, Li = L = (Z * L + I) % M;
        do
        {
            L = (Z * L + I) % M;
            ++cycleLength;
        } while (L != Li);
        cout << cycleLength << endl;
        ++t;
    }

    return 0;
}

