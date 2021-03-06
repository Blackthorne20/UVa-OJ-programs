// f91.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

unsigned int f91(unsigned int N);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int N;
    cin >> N;

    while (N != 0)
    {
        cout << "f91(" << N << ") = "<< f91(N) << endl;
        cin >> N;
    }
    return 0;
}

unsigned int f91(unsigned int N)
{
    if (N <= 100)
    {
        return f91(f91(N + 11));
    }
    else if (N >= 101)
    {
        return N - 10;
    }
}

