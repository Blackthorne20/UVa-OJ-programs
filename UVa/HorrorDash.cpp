//Evan Wood : Horror Dash : 11799 : Blackthorne20
//
//data structure required : vector
//
//tricks of the trade :

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
    int i_numLines;
    cin >> i_numLines;

    //find fastest student, he is the minimum required speed
    for (int i = 0; i < i_numLines; i++)
    {
        int i_numStudents;
        cin >> i_numStudents;

        vector<int> vi_speeds(i_numStudents);

        for (int j = 0; j < i_numStudents; j++)
        {
            cin >> vi_speeds[j];
        }

        int i_minRequiredSpeed = *max_element(vi_speeds.begin(), vi_speeds.end());
        cout << "Case " << i + 1 << ": " << i_minRequiredSpeed << endl;
    }

    return 0;
}

