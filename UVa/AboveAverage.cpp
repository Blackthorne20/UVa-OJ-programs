// AboveAverage.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int C;
    cin >> C;

    for (int i = 0; i < C; i++)
    {
        int N, sum = 0, numAboveAvg = 0;
        double avg = 0.0f;
        cin >> N;

        vector<int> grades(N);
        for (int j = 0; j < N; j++)
        {
            cin >> grades[j];
            sum += grades[j];
        }
        avg = (double)sum / N;
        for (int j = 0; j < N; j++)
        {
            if (grades[j] > avg)
            {
                numAboveAvg++;
            }
        }

        cout << fixed << setprecision(3) << (double)numAboveAvg / N * 100 << "%" << endl;

    }

    return 0;
}

