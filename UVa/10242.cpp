// FourthPoint!_10242.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

typedef pair<double, double> c;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    c P1, P2, P3, P4;
    while (cin >> P1.first)
    {
        cin >> P1.second >> P2.first >> P2.second >> P3.first >> P3.second >> P4.first >> P4.second;

        if (P1 == P3)
        {
            c v = make_pair(P1.first - P4.first, P1.second - P4.second);

        }
        else if (P1 == P4)
        {

        }
        else if (P2 == P3)
        {

        }
        else if (P2 == P4)
        {

        }
    }

    return 0;
}

