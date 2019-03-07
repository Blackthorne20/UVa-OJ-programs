// The Trip
//
// A set of n students has different amounts of money. This program
// calculates the minimum amount of money they need to transfer for
// each student to have an equal amount of money.

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

    int n; //number of students
    while (cin >> n, n != 0)
    {
        vector<int> A(n); //stores the amount of money each student has
        double num;
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> num;
            sum += A[i] = lround(num * 100.0); //convert dollar amount to pennies to avoid precision error
        }


        //calculate minimum amount of money we need to transfer to equalize
        int average = sum / n, pennies = sum % n, sum_dif = 0;
        for (auto i : A)
        {
            if (i > average)
            {
                sum_dif += i - average;
                if (pennies > 0)
                {
                    sum_dif--;
                    pennies--;
                }
            }
        }

        //print value
        cout << "$" <<  sum_dif / 100 << "." << setfill('0') << setw(2) << sum_dif % 100 << endl;
    }

    return 0;
}

