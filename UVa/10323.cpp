/*
10323 - Factorial? You Must be Kidding!!!

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1264
*/
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define SIZE 14

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // generate 1! to 14!
    // ------------------
    vector<long long> factorials(SIZE);
    factorials[0] = 1;
    for (int i = 1; i < SIZE; i++)
    {
        factorials[i] = factorials[i - 1] * i;
    }

    // read input & print output
    // -------------------------
    int n;
    while (cin >> n)
    {
        // negative factorials are not defined, but in this problem,
        // negative even numbers result in an underflow, and
        // negative odd numbers result in an overflow
        if (n >= 0 && n < 8 || n < 0 && -n % 2 == 0)
        {
            cout << "Underflow!" << endl;
        }
        else if (n > 13 || n < 0 && -n % 2 == 1)
        {
            cout << "Overflow!" << endl;
        }
        else
        {
            cout << factorials[n] << endl;
        }
    }

    return 0;
}

