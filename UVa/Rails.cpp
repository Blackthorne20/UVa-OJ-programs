//Evan Wood : Rails : 514 : Blackthorne20
//
//data structure required: vector used as a stack
//
//tricks of the trade: debugging like crazy to optimize efficiency, also
//                     using variable instead of the loop variable
//                     to keep track of coaches, and terminating the
//                     loop early once an impossible sequence is found

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //I use a vector instead of a stack so I can clear it easily
    vector<int> station;
    int n_numCoaches;
    while (cin >> n_numCoaches)
    {
        if (n_numCoaches != 0)
        {
            int n_nextCoachInSequence;
            cin >> n_nextCoachInSequence;

            while (n_nextCoachInSequence != 0)
            {
                int n_coachToPushNext = 1;
                for (int i = 0; i < n_numCoaches; i++)
                {
                    //if the coach we want is next in the sequence, send it without
                    //pushing it in the station
                    if (n_coachToPushNext == n_nextCoachInSequence)
                    {
                        n_coachToPushNext++;
                    }

                    //if the coach we want next is next in the station, send it
                    else if (!station.empty() && station.back() == n_nextCoachInSequence)
                    {
                        station.pop_back();
                    }

                    //if the coach is in the sequence but is obstructed by other coaches,
                    //push the other coaches into the station until we get to the one we want
                    else if (n_coachToPushNext < n_nextCoachInSequence)
                    {
                        while (n_coachToPushNext < n_nextCoachInSequence)
                        {
                            station.push_back(n_coachToPushNext);
                            n_coachToPushNext++;
                        }
                        //we made it to the coach we want, so treat it like condition 1
                        n_coachToPushNext++;
                    }
                    
                    //the coach we want is in the station, but is behind other coaches,
                    //so the sequence is impossible
                    else if (n_coachToPushNext > n_nextCoachInSequence)
                    {
                        cout << "No" << endl;
                        cin.ignore(9000, endl); //skip to next line of input

                        //reset some variables for the next sequence
                        station.clear();
                        n_coachToPushNext = 1;

                        //break out of the loop since it is impossible to continue
                        i = n_numCoaches;
                    }

                    //if all the coaches made it through, then output "Yes".
                    if (i == n_numCoaches - 1 && station.empty())
                    {
                        cout << "Yes" << endl;
                        n_coachToPushNext = 1;
                    }
                    cin >> n_nextCoachInSequence;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
