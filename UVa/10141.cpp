// UVa.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <limits>
#include <string>
#include <cfloat>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    int n, p, t = 1;
    while (cin >> n >> p, !(n == 0 && p == 0))
    {
        cin.ignore(numeric_limits<streamsize>::max(), endl);
        if (t > 1)
        {
            cout << endl;
        }
        string maxname;
        int maxval = 0;
        double mincost = DBL_MAX;
        for (int i = 0; i < n; ++i)
        {
            cin.ignore(numeric_limits<streamsize>::max(), endl);
        }
        for (int i = 0; i < p; ++i)
        {
            double d;
            int r;
            getline(cin, line);
            string name = line;
            cin >> d >> r;
            if (r > maxval)
            {
                maxval = r;
                maxname = name;
                mincost = d;
            }
            else if (r == maxval && d < mincost)
            {
                maxname = name;
                mincost = d;
            }
            cin.ignore(numeric_limits<streamsize>::max(), endl);
            for (int j = 0; j < r; ++j)
            {
                cin.ignore(numeric_limits<streamsize>::max(), endl);
            }
        }

        cout << "RFP #" << t << endl << maxname << endl;
        ++t;
    }

    return 0;
}

