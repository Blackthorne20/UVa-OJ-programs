// SuperLongSums.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int M;
        cin >> M;
        vector<int> int1(M), int2(M);
        for (int j = 0; j < M; j++)
        {
            cin >> int1[j] >> int2[j];
        }

        vector<int> result(M);
        int c = 0;
        for (int j = M - 1; j >= 0; j--)
        {
            int sum = int1[j] + int2[j] + c;
            int d = sum % 10;
            c = sum / 10;
            result[j] = d;
        }
        if (c == 1)
        {
            result.insert(result.begin(), c);
        }

        for (auto n:result)
        {
            cout << n;
        }
        cout << endl;
        if (i != N - 1)
        {
            cout << endl;
        }
    }

    return 0;
}

