// EcologicalPremium.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int f;
        unsigned long long budget = 0;

        cin >> f;
        for (int j = 0; j < f; j++)
        {
            unsigned long long farmArea, numAnimals, ecoFriendliness, premium;
            cin >> farmArea >> numAnimals >> ecoFriendliness;

            premium = farmArea * ecoFriendliness;
            budget += premium;
        }
        cout << budget << endl;
    }
    return 0;
}

