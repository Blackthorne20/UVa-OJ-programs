/*
476 - Points in Figures: Rectangles

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=417&mosmsg=Submission+received+with+ID+23070697
*/
#include <iostream>
#include <list>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    list < pair<pair<double, double>, pair<double, double>>> rectangles;

    // get rectangle corners
    // ---------------------
    char type;
    while (cin >> type, type != '*')
    {
        pair<double, double> upperLeft, bottomRight; // (x, y) coordinates of rectangle corners
        cin >> upperLeft.first >> upperLeft.second >> bottomRight.first >> bottomRight.second;
        rectangles.push_back({ upperLeft, bottomRight });
    }


    // read in points, output the rectangles containing the points
    // -----------------------------------------------------------
    pair<double, double> point, end = { 9999.9, 9999.9 };
    int pointNo = 1;
    while (cin >> point.first >> point.second, point != end)
    {
        bool contained = false;
        int rectangleNo = 1;
        for (auto i : rectangles)
        {
            // points coinciding with boundaries are not counted
            if (point.first > i.first.first && point.first < i.second.first && point.second > i.second.second && point.second < i.first.second)
            {
                cout << "Point " << pointNo << " is contained in figure " << rectangleNo << endl;
                contained = true;
            }
            rectangleNo++;
        }
        if (!contained)
        {
            cout << "Point " << pointNo << " is not contained in any figure" << endl;
        }
        pointNo++;
    }

    return 0;
}

