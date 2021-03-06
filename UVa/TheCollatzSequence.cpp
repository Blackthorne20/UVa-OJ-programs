// TheCollatzSequence.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int caseNo = 1;
    long long A, L;
    while (cin >> A >> L, A > -1 && L > -1)
    {
        cout << "Case " << caseNo << ": A = " << A << ", limit = " << L << ", number of terms = ";
        int numTerms = 0;
        while (A <= L)
        {
            if (A == 1)
            {
                numTerms++;
                break;
            }
            else if (A % 2 == 0)
            {
                A /= 2;
            }
            else if (A % 2 == 1)
            {
                A = 3 * A + 1;
            }
            numTerms++;
        }

        cout << numTerms << endl;
        caseNo++;
    }

    return 0;
}

