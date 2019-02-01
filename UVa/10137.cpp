// UVa.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n, n != 0)
    {
        vector<int> A(n);
        double num;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> num;
            sum += A[i] = lround(num * 100.0);
        }
        int average = sum / n, pennies = sum % n, pos_dif = 0, neg_dif = 0;
        for (auto i : A)
        {
            if (i > average)
            {
                pos_dif += i - average;
            }
            else
            {
                neg_dif += average - i;
            }
        }
        sum_dif -= pennies;
        cout << "$" << sum_dif / 100 << "." << setfill('0') << setw(2) << sum_dif % 100 << endl;
    }

    return 0;
}

