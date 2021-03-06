// TheSnail.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double H, U, D, F;
    cin >> H >> U >> D >> F;

    while (H != 0)
    {
        double heightClimbed = 0.0f, fatigue = U * (F / 100.0f);
        int day = 1;
        bool success = false;
        while (!success)
        {
            heightClimbed += U;
            if (heightClimbed > H)
            {
                success = true;
                break;
            }

            heightClimbed -= D;
            if (heightClimbed < 0)
            {
                break;
            }

            U -= fatigue;
            if (U < 0)
            {
                U = 0;
            }
            day++;
        }
        if (success)
        {
            cout << "success on day " << day << endl;
        }
        else
        {
            cout << "failure on day " << day << endl;
        }

        cin >> H >> U >> D >> F;
    }

    return 0;
}

