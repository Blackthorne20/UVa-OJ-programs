// ColorfulFlowers_11152.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

#define endl '\n'
const double PI = 3.14159265358979;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;

    while (cin >> a >> b >> c)
    {
        double s = (a + b + c) / 2.0f;
        double av = sqrt(s*(s - a)*(s - b)*(s - c));
        double r = av / s;
        double ar = PI * r * r;
        av -= ar;
        double R = a * b * c / (4.0f * av);
        double as = PI * R * R - av;

        cout << fixed << setprecision(4) << as << " " << av << " " << ar << endl;
    }

    return 0;
}

