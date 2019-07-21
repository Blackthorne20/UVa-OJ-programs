/*
12149 - Feynman

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=3301
*/
#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // side length of square
    while (cin >> N, N != 0)
    {
        cout << (N * (N + 1) * (2 * N + 1)) / 6 << endl; // sum of squares from 1 to N
    }

    return 0;
}

