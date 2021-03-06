//Evan Wood : Cost Cutting : 11727 : Blackthorne20
//
//Data structure required : array
//
//Tricks of the trade :

#include <iostream>
#include <algorithm>
#include <array>
#include <list>
using namespace std;

int main()
{
    //get three numbers, find the middle one, then print it
    int i_numLines;
    cin >> i_numLines;

    for (int i = 0; i < i_numLines; i++)
    {
        array<int, 3> salaries;
        for (int i = 0; i < salaries.size(); i++)
        {
            cin >> salaries[i];
        }
        sort(salaries.begin(), salaries.end());
        cout << "Case " << i + 1 << ": " << salaries[1] << endl;
    }
    return 0;
}

