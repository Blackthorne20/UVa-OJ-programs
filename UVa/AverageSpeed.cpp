// AverageSpeed.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

#define endl '\n'


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double distance = 0, speed = 0, x=0, y=0, z=0;

    string line;
    while (getline(cin, line))
    {
        int h, m, s;

        stringstream ss(line);
        ss >> h;
        ss.ignore();
        ss >> m;
        ss.ignore();
        ss >> s;

        distance += speed * (((h * 3600.0f + m * 60.0f + s) - (x * 3600.0f + y * 60.0f + z)) / 3600.0f);

        if (!ss.eof())
        {
            ss >> speed;
        }
        else
        {
            cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ":" << setw(2) 
                << setfill('0') << s << " " << fixed << setprecision(2) << distance << " km" << endl;
        }

        x = h;
        y = m;
        z = s;
    }

    return 0;
}

