// LoansomeCarBuyer.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <map>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int numMonths;

    cin >> numMonths;
    while (numMonths >= 0)
    {
        double downPayment, originalLoan, carValue, curDepreciation, loan;
        unsigned int numDepreciationRecords, curMonth = 0;
        map<int, double> depreciations;

        cin >> downPayment >> originalLoan >> numDepreciationRecords;
        carValue = downPayment + originalLoan;

        for (int i = 0; i < numDepreciationRecords; i++)
        {
            int m;
            double n;

            cin >> m >> n;
            depreciations.insert(make_pair(m, n));
        }

        //Car value depreciates the instant it leaves the dealership
        curDepreciation = depreciations[curMonth];
        carValue -= carValue * depreciations[curMonth];
        loan = originalLoan;

        //Make loan payment and depreciate car value each month
        while (loan >= carValue && curMonth != numMonths)
        {
            loan -= originalLoan / numMonths;
            curMonth++;

            if (depreciations.count(curMonth) != 0)
            {
                curDepreciation = depreciations[curMonth];
                carValue -= carValue * depreciations[curMonth];
            }
            else
            {
                carValue -= carValue * curDepreciation;
            }
        }

        if (curMonth == 1)
        {
            cout << "1 month" << endl;

        }
        else
        {
            cout << curMonth << " months" << endl;
        }

        cin >> numMonths;
    }
    return 0;
}

