// EventPlanning.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int numParticipants, numHotels, numWeeks, price, minCost;
    unsigned long budget;

    while (cin >> numParticipants)
    {
        cin >> budget >> numHotels >> numWeeks;
        minCost = budget;

        for (int i = 0; i < numHotels; i++)
        {
            vector<unsigned int> numRooms(numWeeks);
            cin >> price;
            for (int j = 0; j < numWeeks; j++)
            {
                cin >> numRooms[j];
            }
            if (*max_element(numRooms.begin(), numRooms.end()) > numParticipants)
            {
                if (price * numParticipants < minCost)
                {
                    minCost = price * numParticipants;
                }
            }
        }

        if (minCost == budget)
        {
            cout << "stay home" << endl;
        }
        else
        {
            cout << minCost << endl;
        }
    }

    return 0;
}

