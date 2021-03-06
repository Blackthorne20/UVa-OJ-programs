// Perfection.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << "PERFECTION OUTPUT" << endl;

    int N;
    cin >> N;

    while (N != 0)
    {
        int sum = 0;

        for (int i = 1; i <= N / 2; i++)
        {
            if (N % i == 0)
            {
                sum += i;
            }
        }

        if (sum > N)
        {
            cout << setw(5) << right << N << "  " << "ABUNDANT" << endl;
        }
        else if (sum < N)
        {
            cout << setw(5) << right << N << "  " << "DEFICIENT" << endl;
        }
        else if (sum == N)
        {
            cout << setw(5) << right << N << "  " << "PERFECT" << endl;
        }
        cin >> N;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}

