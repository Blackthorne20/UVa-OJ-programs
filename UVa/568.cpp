/*
568 - Just the Facts


https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=509
*/
#include <iostream>
#include <iomanip>
using namespace std;

#define endl '\n'

const int dig[] = { 1, 1, 2, 6, 4, 2, 2, 4, 2, 8 }; // last non-zero digit of factorials between 0 and 9 

int D(int n) // returns the last non-zero digit of n!
{
    if (n < 10)
    {
        return dig[n];
    }
    else if (n / 10 % 10 % 2) // is the ten's digit even or odd?
    {
        return 4 * D(n / 5) * dig[n % 10] % 10;
    }
    else
    {
        return 6 * D(n / 5) * dig[n % 10] % 10;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    while (cin >> N)
    {
        cout << right << setw(5) << N << " -> " << D(N) << endl;
    }

    return 0;
}

