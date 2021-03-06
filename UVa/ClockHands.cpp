// ClockHands.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int H, M;
    cin >> H;
    cin.ignore();
    cin >> M;

    while (!(H == 0 && M == 0))
    {

        double degH = 30.0f * H + M / 2.0f;
        double degM = 6.0f * M;
        double theta = abs(degH - degM);
        if (theta > 180.0f)
        {
            theta = 360.0f - theta;
        }
        cout << fixed << setprecision(3) << theta << endl;

        cin >> H;
        cin.ignore();
        cin >> M;
    }


    return 0;
}

